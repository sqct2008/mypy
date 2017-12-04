#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <typeinfo>
#include "ast.h"

NoneTypeLiteral NONE;

void freeAST(Node* node) {
  if ( node ) {
    BinaryNode* temp = dynamic_cast<BinaryNode*>(node);
    if ( temp ) {
      freeAST(temp->getLeft());
      freeAST(temp->getRight());
    }
    delete node;
  }
}

//Node* IdentNode::getFunc() {
//  return sTable.getFunc(ident);
//}

const Node* IdentNode::eval(SymbolTable* symbolTable) { 
  //std::cout << "ident node eval" << std::endl;
  if(!symbolTable)
    throw "wrong symbolTable";
  const Node* res = symbolTable -> getValue(ident);
  return res;
}

const Node* ReturnNode::eval(SymbolTable* symbolTable) {
  return res -> eval(symbolTable);
}

const Node* PrintNode::eval(SymbolTable* symbolTable) {
  //std::cout << "print node eval" << std::endl;
  //symbolTable -> print();
  if(printList) {
    TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>(printList);
    if(tuples) {
      const std::list<Node*>& elements = tuples -> getVec();
      std::list<Node*>::const_iterator it = elements.begin();
      while(it!=elements.end()){
        //std::cout << static_cast<IdentNode*>(*it) -> getIdent();
        const Node* subTuple = (*it) -> eval(symbolTable);
        // XXX: really need to take care of those who have hierarch tuples.
        const_cast<Node*>(subTuple) -> eval(symbolTable) -> print();
        it++;
        if(it==elements.end()) {}
        else
          std::cout << ' ';
      }
    }
    else {
      printList -> eval(symbolTable) -> print();
    }
    std::cout << std::endl;
  }
  else
    std::cout << std::endl;

  // FIXME: is it OK to NOT manualy delete a pointer which points to an object that does not have any attribute?
  return &NONE;
}

const Node* FuncNode::eval(SymbolTable* _symbolTable) {
  //getchar();

  symbolTable = new SymbolTable;
  symbolTable -> setParents(_symbolTable);
  symbolTable -> print();
  //std::cout << "go into func" << std::endl;
  //if(node)
  //  std::cout << "happy" << std::endl;
  //else
  //  std::cout << "sad" << std::endl;
  //node -> eval(symbolTable);
  //std::cout << typeid(node).name() << std::endl;

  Node* node = symbolTable -> getValue(id); 
  SuiteNode* suite = dynamic_cast<SuiteNode*>(node);

  //std::cout << "after dynamic func" << std::endl;
  // IS suite
  if(suite) {
    TuplesLiteral* arguments = dynamic_cast<TuplesLiteral*>(argumentsList -> getFirst());
    // HAVE new arguments
    if(arguments) {
      //std::cout << "have argument" << std::endl;
      AssBinaryNode* assParas = new AssBinaryNode(suite -> getParas(), arguments);
      PoolOfNodes::getInstance().add(assParas);
      assParas -> eval(symbolTable);
      Node* res = const_cast<Node*>(suite -> eval(symbolTable));
      suite = dynamic_cast<SuiteNode*>(res);
      // keep new func
      if(suite) {
        // XXX: SHALL NOT ruin the argumentsList of original function! Otherwise you may not call it again!
        TuplesLiteral* new_argumentsList = new TuplesLiteral(argumentsList -> getVec());
        new_argumentsList -> pop_front();
        FuncNode* next_func = new FuncNode(suite->getID(), new_argumentsList);
        PoolOfNodes::getInstance().add(next_func);
        return next_func -> eval(symbolTable);
      }
      // return
      else {
        return res;
        throw "wrong call for func";
      }
    }
    // HAVE NO new arguments
    else {
      //std::cout << "have not argument" << std::endl;
      return suite;
    }
  }
  // IS NOT suite
  else {
    throw id + " is not a function";
  }
}

//const Node* FuncNode::eval(SymbolTable* _symbolTable) {
//  // TODO: need to do the function evaluation
//  // FIXME: need to modify symboltable class
//
//  SuiteNode* suite = dynamic_cast<SuiteNode*>(_symbolTable -> getValue(id));
//
//  // IS suite
//  if(suite) {
//
//    const std::list<Node*>& argList = argumentsList -> getVec();
//    std::list<Node*>::const_iterator it = argList.begin();
//
//    //std::cout << "size" << argList.size() << std::endl;
//    AssBinaryNode* assParas = new AssBinaryNode(suite -> getParas(), *it);
//    PoolOfNodes::getInstance().add(assParas);
//    SymbolTable temp_temp_symbolTable;
//    assParas -> eval(&temp_temp_symbolTable);
//    suite = dynamic_cast<SuiteNode*>(const_cast<Node*>(suite -> eval(&temp_temp_symbolTable)));
//    it++;
//
//    if(suite) {
//      if(argList.size() == 1){
//        return suite -> eval(&temp_temp_symbolTable);
//      }
//
//      while(it != argList.end()) {
//        if(suite) {
//          SymbolTable temp_symbolTable;
//          temp_symbolTable.setParents(&temp_temp_symbolTable); 
//
//          AssBinaryNode* assParas = new AssBinaryNode(suite -> getParas(), *it);
//          PoolOfNodes::getInstance().add(assParas);
//          assParas -> eval(&temp_symbolTable);
//
//          //std::cout << "print before execution" << std::endl;
//          //const_cast<Node*>(suite -> eval(&temp_symbolTable)) -> eval(&temp_symbolTable) -> print();
//          suite = dynamic_cast<SuiteNode*>(const_cast<Node*>(suite -> eval(&temp_symbolTable)));
//          it++;
//        }
//        else {
//          throw "return is not a function";
//        }
//      }
//
//    }
//
//  }
//  // IS NOT suite
//  else {
//    throw id + " is not a function";
//  }
//  return suite ;
//}

void SuiteNode::setID(std::string name) {
  id = name;
}

void SuiteNode::addLine(Node* line) {
  suite->add_back(line);
}

void SuiteNode::setParas(TuplesLiteral* paras) {
  parametersList = paras;
}

Node* SuiteNode::getParas() {
  return parametersList;
}

//Literal* SuiteNode::callSuite(TuplesLiteral* parasList) const {
//
//}

const Node* SuiteNode::eval(SymbolTable* symbolTable) {
  std::list<Node*> lines = suite -> getVec();
  std::list<Node*>::const_iterator it = lines.begin();
  //PoolOfNodes::getInstance().add(res);
  while(it != lines.end()) {
    SuiteNode* subSuite = dynamic_cast<SuiteNode*>(*it);
    if(subSuite) {
      // TODO: deal with the symboltable within subSuite!
      symbolTable -> setValue(subSuite -> id, subSuite);
      ++it;
      continue;
    }

    // XXX: need to add new funcNode each time it eval()
    //FuncNode* funcCall = dynamic_cast<FuncNode*>(*it);
    //if(funcCall) {


    //}

    ReturnNode* res = dynamic_cast<ReturnNode*>(*it);
    if(res) {
      // TODO: return res;
      //std::cout << "returning " << std::endl;
      return res -> eval(symbolTable);
    }
    //const_cast<Literal*>((*it)->eval()));
    (*it) -> eval(symbolTable);
    ++it;
  }
  return &NONE;
}


AssBinaryNode::AssBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  //if (!left || !right) {
  //  throw "error";
  //}
  //IdentNode* idtNode = dynamic_cast<IdentNode*>(left);

  //// IS identnode
  //if(idtNode) {
  //  const std::string n = idtNode->getIdent();
  //  sTable.setValue(n, right);
  //}
}


const Node* AssBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* res = right->eval(symbolTable);
  IdentNode* idtNode = dynamic_cast<IdentNode*>(left);

  // IS identnode
  if(idtNode) {
    //std::cout << "IS identNode" << std::endl;
    const std::string n = idtNode->getIdent();
    symbolTable -> setValue(n, const_cast<Node*>(res));
  }
  // IS NOT identnode
  else {
    TuplesLiteral* identVecNode = dynamic_cast<TuplesLiteral*>(left);
    TuplesLiteral* tupleVecNode = dynamic_cast<TuplesLiteral*>(const_cast<Node*>(right->eval(symbolTable)));
    if( !identVecNode )
      throw "indent is not tuple";
    if( !tupleVecNode )
      throw "tuple is not tuple";
    const std::list<Node*>& identVec = identVecNode -> getVec();
    const std::list<Node*>& tupleVec = tupleVecNode -> getVec();
    //std::cout << "id size" << identVec.size() << std::endl;
    //std::cout << "tuple size" << tupleVec.size() << std::endl;

    if( identVec.size() != tupleVec.size() )
      throw "cannot assign";
    if( identVec.size() == 0 ) {
      //std::cout << "have no value" << std::endl;
      return &NONE;
    }
    std::list<Node*>::const_iterator identIt = identVec.begin();
    std::list<Node*>::const_iterator tupleIt = tupleVec.begin();
    while(identIt != identVec.end()) {
      IdentNode* tempidentNode = dynamic_cast<IdentNode*>(*identIt);
      // IS identnode
      if(tempidentNode) {
        const std::string n = tempidentNode->getIdent();
        symbolTable -> setValue(n, const_cast<Node*>((*tupleIt)->eval(symbolTable)));
      }
      // IS NOT identnode
      else {
        Node* node = new AssBinaryNode(*identIt, *tupleIt);
        PoolOfNodes::getInstance().add(node);
        node -> eval(symbolTable);
      }
      ++identIt;
      ++tupleIt;
    }
  }
  //symbolTable->print();
  return res;
}

const Node* AddBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);
  
  return (*x).operator+(*y);
}

const Node* SubBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);

  return ((*x)-(*y));
}

const Node* MulBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);

  return ((*x)*(*y));
}

const Node* DivBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);

  //if ( y->eval(symbolTable) == 0 ) {
  //  throw std::string("ZeroDivisionError");
  //}

  return ((*x)/(*y));
}

const Node* DoubleSlashBinaryNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);
  //if ( y->eval() == 0 ) {
  //  throw std::string("ZeroDivisionError");
  //}

  return ((*x).doubleSlash(*y));
}

const Node* PowBinaryNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);

  return ((*x).opPower(*y));
}

const Node* ModBinaryNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);

  // This is a trick to make the outcome the same as python
  return *(*((*x)%(*y))+(*y))%(*y);
}

const Node* LeftShiftNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);

  IntLiteral* _intLiteral = dynamic_cast<IntLiteral*>(const_cast<Literal*>(x));
  if(_intLiteral) {
    IntLiteral* intNode = new IntLiteral(2);
    PoolOfNodes::getInstance().add(intNode);
    Node* rhs = new PowBinaryNode(intNode, const_cast<Literal*>(y));
    PoolOfNodes::getInstance().add(rhs);
    Node* res = new MulBinaryNode(_intLiteral, rhs);
    PoolOfNodes::getInstance().add(res);
    
    return res->eval(symbolTable);
  }
  else {
    throw "error when shifting";
  }
}

const Node* RightShiftNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = static_cast<const Literal*>(a);
  const Literal* y = static_cast<const Literal*>(b);

  IntLiteral* _intLiteral = dynamic_cast<IntLiteral*>(const_cast<Literal*>(x));
  if(_intLiteral) {
    IntLiteral* intNode = new IntLiteral(2);
    PoolOfNodes::getInstance().add(intNode);
    Node* rhs = new PowBinaryNode(intNode, const_cast<Literal*>(y));
    PoolOfNodes::getInstance().add(rhs);
    Node* res = new DivBinaryNode(_intLiteral, rhs);
    PoolOfNodes::getInstance().add(res);
    
    return res->eval(symbolTable);
  }
  else {
    throw "error when shifting";
  }
}
