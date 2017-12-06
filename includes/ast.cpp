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


const Node* IdentNode::eval(SymbolTable* symbolTable) { 
  if(!symbolTable)
    throw "wrong symbolTable";
  const Node* res = symbolTable -> getValue(ident);
  return res;
}

//class SuiteNode;

const Node* ReturnNode::eval(SymbolTable* symbolTable) {
  const Node* returnNode = res -> eval(symbolTable);
  SuiteNode* suiteNode = dynamic_cast<SuiteNode*>(const_cast<Node*>(returnNode));
  if(suiteNode) {
    ClosureNode* returnValue = new ClosureNode(suiteNode, symbolTable);
    PoolOfNodes::getInstance().add(returnValue);
    return returnValue;
  }
  else
    return returnNode;
}

const Node* PrintNode::eval(SymbolTable* symbolTable) {
  if(printList) {
    TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>(printList);
    if(tuples) {
      const std::list<Node*>& elements = tuples -> getVec();
      std::list<Node*>::const_iterator it = elements.begin();
      while(it!=elements.end()){
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

  return &NONE;
}


const Node* FuncNode::eval(SymbolTable* _symbolTable) {

  // SETUP symbolTalbe pointer
  if(symbolTable) 
    delete symbolTable;
  symbolTable = new SymbolTable;
  symbolTable -> setParents(_symbolTable);

  // SETUP function body
  Node* node = symbolTable -> getValue(id); 
  SuiteNode* suite = dynamic_cast<SuiteNode*>(node);
  ClosureNode* closure = dynamic_cast<ClosureNode*>(node); 

  // IS suite
  if(suite) {
    TuplesLiteral* arguments = dynamic_cast<TuplesLiteral*>(argumentsList -> getFirst());
    // HAVE new arguments
    if(arguments) {
      // use assbinarynode to do parameters assignment
      // XXX: NEED to FIRST get value of FUNCTION
      AssBinaryNode* assParas = new AssBinaryNode(suite -> getParas(), const_cast<Node*>(arguments -> eval(symbolTable)));
      PoolOfNodes::getInstance().add(assParas);
      //SetToNone(suite -> getParas(), symbolTable);
      assParas -> eval(symbolTable);

      // eval function body
      Node* res = const_cast<Node*>(suite -> eval(symbolTable));
      closure = dynamic_cast<ClosureNode*>(res); 
      // go new func
      //if(false) {
      //  // XXX: SHALL NOT ruin the argumentsList of original function! Otherwise you may not call it again!
      //  TuplesLiteral* new_argumentsList = new TuplesLiteral(argumentsList -> getVec());
      //  PoolOfNodes::getInstance().add(new_argumentsList);
      //  new_argumentsList -> pop_front();
      //  FuncNode* next_func = new FuncNode(suite->getID(), new_argumentsList);
      //  PoolOfNodes::getInstance().add(next_func);
      //  return next_func -> eval(symbolTable);
      //}
      // return value should not be suitenode
      if(closure) {
        std::cout << "new closure" << std::endl;
        TuplesLiteral* new_argumentsList = new TuplesLiteral(argumentsList -> getVec());
        PoolOfNodes::getInstance().add(new_argumentsList);
        new_argumentsList -> pop_front();

        FuncNode* next_func = new FuncNode(closure -> getSuiteNode() ->getID(), new_argumentsList);
        PoolOfNodes::getInstance().add(next_func);
        return next_func -> eval(closure -> getSymbolTable());
      }
      // return
      else {
        return res;
        throw "wrong call for func";
      }
    }
    // HAVE NO new arguments
    else {
      return suite;
    }
  }
  // IS closure
  else if(closure) {
    std::cout << "in closure" << std::endl;
    TuplesLiteral* arguments = dynamic_cast<TuplesLiteral*>(argumentsList -> getFirst());
    // HAVE new arguments
    if(arguments) {
      // use assbinarynode to do parameters assignment
      // XXX: NEED to FIRST get value of FUNCTION
      AssBinaryNode* assParas = new AssBinaryNode(closure -> getSuiteNode() -> getParas(), 
          const_cast<Node*>(arguments -> eval(symbolTable)));
      PoolOfNodes::getInstance().add(assParas);
      assParas -> eval(symbolTable);
      // XXX: use closure environment to initial symbolTable.parents
      symbolTable -> setParents(closure -> getSymbolTable());

      // eval function body
      Node* res = const_cast<Node*>(closure -> getSuiteNode() -> eval(symbolTable));
      // return value could not be suitenode;
      closure = dynamic_cast<ClosureNode*>(res); 
      // keep new closure
      if(closure) {
        std::cout << "new closure" << std::endl;
        TuplesLiteral* new_argumentsList = new TuplesLiteral(argumentsList -> getVec());
        PoolOfNodes::getInstance().add(new_argumentsList);
        new_argumentsList -> pop_front();
        FuncNode* next_func = new FuncNode(closure -> getSuiteNode() ->getID(), new_argumentsList);
        PoolOfNodes::getInstance().add(next_func);
        return next_func -> eval(closure -> getSymbolTable());
      }
      // return
      else {
        return res;
        throw "wrong call for func";
      }
    }
    // HAVE NO new arguments
    else {
      return closure;
    }
  }
  // IS NOT suite & closure
  else {
    throw id + " is not a function";
  }
}

const Node* ClosureNode::eval(SymbolTable*) {
  return this;
}

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


const Node* SuiteNode::eval(SymbolTable* symbolTable) {
  std::list<Node*> lines = suite -> getVec();
  std::list<Node*>::const_iterator it = lines.begin();
  while(it != lines.end()) {
    SuiteNode* subSuite = dynamic_cast<SuiteNode*>(*it);
    if(subSuite) {
      // TODO: deal with the symboltable within subSuite!
      symbolTable -> setValue(subSuite -> id, subSuite);
      ++it;
      continue;
    }

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
}

// XXX: ONLY USED in assbinarynode::eval
void SetToNone(Node* tP,SymbolTable* sT) {
  TuplesLiteral* name_tuple = dynamic_cast<TuplesLiteral*>(tP);
  if(name_tuple) {
    const std::list<Node*>& to_be_none = name_tuple -> getVec();
    for(auto it : to_be_none) {
      IdentNode* id = dynamic_cast<IdentNode*>(it);
      TuplesLiteral* ids = dynamic_cast<TuplesLiteral*>(it);
      if(id) {
        if(! sT -> findNative(id->getIdent())){
          sT -> setValue(id->getIdent(), &NONE);
        }
      }
      else if(ids) {
        SetToNone(ids, sT);
      }
      else
        throw "wrong assignment";
    }
  }
  else {
    IdentNode* id = dynamic_cast<IdentNode*>(tP);
    if(id) {
      if(! sT -> findNative(id->getIdent())){
        sT -> setValue(id->getIdent(), &NONE);
      }
    }
    else
      throw "wrong assignment";
  }
}


const Node* AssBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  // FIXME:
  SetToNone(left, symbolTable);
  const Node* res = right->eval(symbolTable);
  IdentNode* idtNode = dynamic_cast<IdentNode*>(left);

  // IS identnode
  if(idtNode) {
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
  return res;
}

const Node* AddBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return (*x).operator+(*y);
  else
    throw "only Literals can be added";
}

const Node* SubBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return ((*x)-(*y));
  else
    throw "only Literals can be mined";
}

const Node* MulBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return ((*x)*(*y));
  else
    throw "only Literals can be Multiplied";
}

const Node* DivBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return ((*x)/(*y));
  else
    throw "only Literals can be divided";
}

const Node* DoubleSlashBinaryNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return ((*x).doubleSlash(*y));
  else
    throw "only Literals can be doubleSlashed";
}

const Node* PowBinaryNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return ((*x).opPower(*y));
  else
    throw "only Literals can be powered";
}

const Node* ModBinaryNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    // This is a trick to make the outcome the same as python
    return *(*((*x)%(*y))+(*y))%(*y);
  else
    throw "only Literals can be Modded";
}

const Node* LeftShiftNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y) {
    IntLiteral* _intLiteral = dynamic_cast<IntLiteral*>(const_cast<Literal*>(x));
    if(_intLiteral) {
      IntLiteral* intNode = new IntLiteral(2);
      PoolOfNodes::getInstance().add(intNode);
      return (*x)*(*(intNode->opPower(*y)));
    }
    else {
      throw "error when shifting";
    }
  }
  else
    throw "only Literals can be LeftShifted";
}

const Node* RightShiftNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y) {
    IntLiteral* _intLiteral = dynamic_cast<IntLiteral*>(const_cast<Literal*>(x));
    if(_intLiteral) {
      IntLiteral* intNode = new IntLiteral(2);
      PoolOfNodes::getInstance().add(intNode);
      return (*x)/(*(intNode->opPower(*y)));
    }
    else {
      throw "error when shifting";
    }
  }
  else
    throw "only Literals can be RightShifted";
}
