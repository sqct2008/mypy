#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <typeinfo>
#include "ast.h"

NoneTypeLiteral None;
extern SymbolTable sTable;

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


const Node* ReturnNode::eval(SymbolTable* symbolTable) {
  const Node* returnNode = res -> eval(symbolTable);
  FuncDef* funcDef = dynamic_cast<FuncDef*>(const_cast<Node*>(returnNode));
  if(funcDef) {
    ClosureNode* returnValue = new ClosureNode(funcDef, symbolTable);
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
        if(subTuple) 
          const_cast<Node*>(subTuple) -> eval(symbolTable) -> print();
        else
          None.print();
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

  return nullptr;
}


const Node* GlobalNode::eval(SymbolTable* symbolTable) {
  const std::list<Node*>& nameVec = globalVar -> getVec();
  for(auto it : nameVec) {
    std::string id = static_cast<IdentNode*>(it) -> getIdent();
    symbolTable -> setValue(id, sTable.getValue(id));
  }
  return nullptr;
}

void SetToNone(Node* tP,SymbolTable* sT) {
  TuplesLiteral* name_tuple = dynamic_cast<TuplesLiteral*>(tP);
  if(name_tuple) {
    const std::list<Node*>& to_be_none = name_tuple -> getVec();
    for(auto it : to_be_none) {
      IdentNode* id = dynamic_cast<IdentNode*>(it);
      TuplesLiteral* ids = dynamic_cast<TuplesLiteral*>(it);
      if(id) {
        if(! sT -> findNative(id->getIdent())){
          sT -> setValue(id->getIdent(), &None);
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
        sT -> setValue(id->getIdent(), &None);
      }
    }
    else
      throw "wrong assignment";
  }
}

FuncDef::FuncDef(std::string _id, TuplesLiteral* _parametersList, SuiteNode* _suite) : Node(), id(_id), parametersList(_parametersList), suite(_suite){
  initial_symbolTable = new SymbolTable;
  PoolOfNodes::getInstance().addSymbolTable(initial_symbolTable);
  const std::list<Node*>& lineVec = suite -> getLines();
  std::list<Node*>::const_iterator it = lineVec.begin();
  while(it != lineVec.end()) {
    if((*it) -> getTypeName() == ASSIGN) {
      AssBinaryNode* ass = static_cast<AssBinaryNode*>(*it);
      SetToNone(ass->getLeft(), initial_symbolTable);
    }
    ++it;
  }
  // XXX: Still need to do this with parameters!
  SetToNone(parametersList, initial_symbolTable);
}

void FuncDef::setParents(SymbolTable* _symbolTable) { 
  initial_symbolTable -> setParents(_symbolTable); 
}

const Node* FuncCall::eval(SymbolTable* _symbolTable) {

  // SETUP function body
  if(!node) {
    node = _symbolTable -> getValue(id); 
  }
  if(!node) {
    throw "wrong way";
  }
  TuplesLiteral* arguments = dynamic_cast<TuplesLiteral*>(argumentsList -> getFirst());
  if(arguments) {
    switch(node -> getTypeName()) {
      // HERE IS FUNCTION
      case FUNCDEF:
        {
          FuncDef* funcDef = static_cast<FuncDef*>(node);
          AssBinaryNode* assParas = new AssBinaryNode(funcDef -> getParas(), const_cast<Node*>(arguments -> eval(_symbolTable)));
          PoolOfNodes::getInstance().add(assParas);
          symbolTable = new SymbolTable(*funcDef -> getSymbolTable());
          PoolOfNodes::getInstance().addSymbolTable(symbolTable);
          assParas -> eval(symbolTable);

          const Node* res = funcDef -> getSuite() -> eval(symbolTable);

          TuplesLiteral* new_argumentsList = new TuplesLiteral(argumentsList -> getVec());
          PoolOfNodes::getInstance().add(new_argumentsList);
          new_argumentsList -> pop_front();

          if(new_argumentsList -> getFirst() && new_argumentsList -> getFirst() -> getTypeName() != NONETYPE) {
            if(res) {
              switch(res -> getTypeName()) {
                case CLOSURE:
                  {
                    // creat new FuncCall Node
                    ClosureNode* closure = static_cast<ClosureNode*>(const_cast<Node*>(res));

                    FuncCall* next_func = new FuncCall(closure -> getFuncDef(), new_argumentsList);
                    PoolOfNodes::getInstance().add(next_func);
                    return next_func -> eval(closure -> getSymbolTable());
                    break;
                  }
                default:
                  throw "None Function cannot be called";
                  break;
              }
            }
            else {
              throw "nothing can be called";
            }
          }
          return res;
          break;
        }
      // HERE IS CLOSURE
      case CLOSURE:
        {
          ClosureNode* closure = static_cast<ClosureNode*>(node);

          node = closure -> getFuncDef();
          symbolTable = closure -> getSymbolTable();

          FuncDef* funcDef = static_cast<FuncDef*>(node);
          AssBinaryNode* assParas = new AssBinaryNode(funcDef -> getParas(), const_cast<Node*>(arguments -> eval(_symbolTable)));
          PoolOfNodes::getInstance().add(assParas);
          symbolTable = new SymbolTable(*funcDef -> getSymbolTable());
          PoolOfNodes::getInstance().addSymbolTable(symbolTable);
          assParas -> eval(symbolTable);

          Node* res = const_cast<Node*>(funcDef -> getSuite() -> eval(symbolTable));

          TuplesLiteral* new_argumentsList = new TuplesLiteral(argumentsList -> getVec());
          PoolOfNodes::getInstance().add(new_argumentsList);
          new_argumentsList -> pop_front();

          if(new_argumentsList -> getFirst()) {
            if(res) {
              switch(res -> getTypeName()) {
                case CLOSURE:
                  {
                    // creat new FuncCall Node
                    ClosureNode* closure = static_cast<ClosureNode*>(const_cast<Node*>(res));

                    FuncCall* next_func = new FuncCall(closure -> getFuncDef(), new_argumentsList);
                    PoolOfNodes::getInstance().add(next_func);
                    return next_func -> eval(closure -> getSymbolTable());
                    break;
                  }
                default:
                  throw "None Function cannot be called";
                  break;
              }
            }
            else {
              throw "nothing can be called";
            }
          }
          return res;

          break;
        }
      default:
        throw "wrong call for function: " + id;
        break;
    }
  }
  else {
    throw id + " wrong calling function without arguments";
  }
}

const Node* ClosureNode::eval(SymbolTable*) {
  return this;
}

IFNode::IFNode(Node* _test, SuiteNode* _suite) : test(_test) {
  tuple_if_suite = new TuplesLiteral(_suite);
  PoolOfNodes::getInstance().add(tuple_if_suite);
}

void IFNode::add_suite(TuplesLiteral* suite_trailer) {
  const std::list<Node*>& trailer = suite_trailer -> getVec();
  for(auto& it : trailer) {
    tuple_if_suite -> add_back(it);
  }
}

void IFNode::add_line(SuiteNode* suite_trailer) {
    tuple_if_suite -> add_back(suite_trailer);
}

const Node* IFNode::eval(SymbolTable* symbolTable) {
  const Node* resultNode = test -> eval(symbolTable);
  Literal* literalNode = dynamic_cast<Literal*>(const_cast<Node*>(resultNode));
  if(literalNode) {
    const std::list<Node*>& if_suite_vec = tuple_if_suite -> getVec();
    std::list<Node*>::const_iterator it = if_suite_vec.begin();
    if(literalNode -> Bool()) {
      SuiteNode* suite = static_cast<SuiteNode*>(*it);
      const Node* suiteRes = suite -> eval(symbolTable);
      if(suiteRes)
        return suiteRes;
      return &None;
    }
    else {
      ++it;
      while(it != if_suite_vec.end()) {
        const Node* suiteRes = (*it) -> eval(symbolTable);
        if(suiteRes)
          return suiteRes;
        it++;
      }
      return nullptr;
    }
  }
  else
    throw "no test value available";
}

void SuiteNode::addLine(Node* line) {
  suite->add_back(line);
}

const Node* SuiteNode::eval(SymbolTable* symbolTable) {
  std::list<Node*> lines = suite -> getVec();
  std::list<Node*>::const_iterator it = lines.begin();
  // WHEN IN Global, just do normal eval
  if(symbolTable -> isGlobal()) {
    while(it != lines.end()) {
      switch((*it) -> getTypeName()) {
        case FUNCDEF:
          {
            FuncDef* funcDef = static_cast<FuncDef*>(*it);
            symbolTable -> setValue(funcDef -> getID(), funcDef);
            funcDef -> setParents(symbolTable);
            ++it;
            break;
          }
        case FUNCCALL:
          {
            FuncCall* funcCall = static_cast<FuncCall*>(*it);
            // XXX: NEED TO ADD new function SO THAT it CAN recursively call itself
            FuncCall* new_funcCall = new FuncCall(*funcCall);
            PoolOfNodes::getInstance().add(new_funcCall);
            new_funcCall -> eval(symbolTable);
            ++it;
            break;
          }
        default:
          (*it) -> eval(symbolTable);
          it++;
          break;
      }
    }
    return nullptr;
  }
  // XXX: WHEN not in Global, need to handle RETURN
  else {
    while(it != lines.end()) {
      switch((*it) -> getTypeName()) {
        case LITERAL:
          ++it;
          break;
        case RETURNTYPE:
          {
            ReturnNode* res = static_cast<ReturnNode*>(*it);
            return res -> eval(symbolTable);
            ++it;
            break;
          }
        case FUNCDEF:
          {
            FuncDef* funcDef = static_cast<FuncDef*>(*it);
            symbolTable -> setValue(funcDef -> getID(), funcDef);
            funcDef -> setParents(symbolTable);
            ++it;
            break;
          }
        case FUNCCALL:
          {
            FuncCall* funcCall = static_cast<FuncCall*>(*it);
            // TODO:
            FuncCall* new_funcCall = new FuncCall(*funcCall);
            PoolOfNodes::getInstance().add(new_funcCall);
            new_funcCall -> eval(symbolTable);
            ++it;
            break;
          }
        case IFELSE:
          {
            IFNode* ifNode = static_cast<IFNode*>(*it);
            const Node* ifRes = ifNode -> eval(symbolTable);
            if(!symbolTable -> isGlobal())
              if(ifRes)
                return ifRes;
            ++it;
            break;
          }
        default:
          (*it) -> eval(symbolTable);
          ++it;
          break;
      }
    }
    return nullptr;
  }
}


AssBinaryNode::AssBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
}



const Node* AssBinaryNode::eval(SymbolTable* symbolTable) { 
  if (!left || !right) {
    throw "error";
  }
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
      return nullptr;
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

const Node* GreaterNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return *x > *y;
  else
    throw "only Literals can be compared";
}

const Node* LessNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return *y > *x;
  else
    throw "only Literals can be compared";
}

const Node* GreaterEQNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return *x >= *y;
  else
    throw "only Literals can be compared";
}

const Node* LessEQNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return *y >= *x;
  else
    throw "only Literals can be compared";
}

const Node* EQEqualNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y)
    return *x == *y;
  else
    throw "only Literals can be compared";
}

const Node* NotEQNode::eval(SymbolTable* symbolTable) {
  if (!left || !right) {
    throw "error";
  }
  const Node* a = left->eval(symbolTable);
  const Node* b = right->eval(symbolTable);
  const Literal* x = dynamic_cast<const Literal*>(a);
  const Literal* y = dynamic_cast<const Literal*>(b);
  
  if(x && y) {
    BoolLiteral* res = const_cast<BoolLiteral*>(*y == *x);
    res -> setOpposite();
    return res;
  }
  else
    throw "only Literals can be compared";
}

