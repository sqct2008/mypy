#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"

SymbolTable sTable;

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

Node* IdentNode::getFunc() {
  return sTable.getFunc(ident);
}

const Literal* IdentNode::eval() const { 
  const Literal* val = sTable.getValue(ident);
  const Literal* res = val;
  return res;
}

const Literal* ReturnNode::eval() const {
  return res -> eval();
}

const Literal* PrintNode::eval() const {
  if(printList) {
    TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>(printList);
    if(tuples) {
      const std::list<Node*>& elements = tuples -> getVec();
      std::list<Node*>::const_iterator it = elements.begin();
      while(it!=elements.end()){
        (*it) -> eval() -> print();
        it++;
        if(it==elements.end()) {}
        else
          std::cout << ' ';
      }
    }
    else {
      printList -> eval() -> print();
    }
    std::cout << std::endl;
  }
  else
    std::cout << std::endl;

  // FIXME: is it OK to NOT manualy delete a pointer which points to an object that does not have any attribute?
  NoneTypeLiteral* None = new NoneTypeLiteral;
  PoolOfNodes::getInstance().add(None);
  return None;
}

const Literal* FuncNode::eval() const {
  // TODO: need to do the function evaluation
  SuiteNode* suite = static_cast<SuiteNode*>(symbolTable.getFunc(id));
  return new NoneTypeLiteral;

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

//Literal* SuiteNode::callSuite(TuplesLiteral* parasList) const {
//
//}

const Literal* SuiteNode::eval() const {
  std::list<Node*> lines = suite -> getVec();
  std::list<Node*>::const_iterator it = lines.begin();
  TuplesLiteral* res = nullptr;
  //PoolOfNodes::getInstance().add(res);
  while(it != lines.end()) {
    SuiteNode* subSuite = dynamic_cast<SuiteNode*>(*it);
    if(subSuite) {
      // TODO: deal with the symboltable within subSuite!
      ++it;
      continue;
    }
    (*it) -> eval();
    ReturnNode* res = dynamic_cast<ReturnNode*>(*it);
    if(res) {
      //return res;

    }
    //const_cast<Literal*>((*it)->eval()));
    ++it;
  }
  return res;
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


const Literal* AssBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();
  IdentNode* idtNode = dynamic_cast<IdentNode*>(left);

  // IS identnode
  if(idtNode) {
    const std::string n = idtNode->getIdent();
    sTable.setValue(n, res);
  }
  // IS NOT identnode
  else {
    TuplesLiteral* identVecNode = dynamic_cast<TuplesLiteral*>(left);
    TuplesLiteral* tupleVecNode = dynamic_cast<TuplesLiteral*>(const_cast<Literal*>(right->eval()));
    if( !identVecNode )
      throw "indent is not tuple";
    if( !tupleVecNode )
      throw "tuple is not tuple";
    const std::list<Node*>& identVec = identVecNode -> getVec();
    const std::list<Node*>& tupleVec = tupleVecNode -> getVec();
    if( identVec.size() != tupleVec.size() )
      throw "cannot assign";
    std::list<Node*>::const_iterator identIt = identVec.begin();
    std::list<Node*>::const_iterator tupleIt = tupleVec.begin();
    while(identIt != identVec.end()) {
      IdentNode* tempidentNode = dynamic_cast<IdentNode*>(*identIt);
      // IS identnode
      if(tempidentNode) {
        const std::string n = tempidentNode->getIdent();
        sTable.setValue(n, (*tupleIt)->eval());
      }
      // IS NOT identnode
      else {
        Node* node = new AssBinaryNode(*identIt, *tupleIt);
        PoolOfNodes::getInstance().add(node);
        node -> eval();
      }
      ++identIt;
      ++tupleIt;
    }
  }
  return res;
}

const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  if ( y->eval() == 0 ) {
    throw std::string("ZeroDivisionError");
  }

  return ((*x)/(*y));
}

const Literal* DoubleSlashBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  if ( y->eval() == 0 ) {
    throw std::string("ZeroDivisionError");
  }

  return ((*x).doubleSlash(*y));
}

const Literal* PowBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).opPower(*y));
}

const Literal* ModBinaryNode::eval()const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();

  // This is a trick to make the outcome the same as python
  return *(*((*x)%(*y))+(*y))%(*y);
}

const Literal* LeftShiftNode::eval()const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();

  IntLiteral* _intLiteral = dynamic_cast<IntLiteral*>(const_cast<Literal*>(x));
  if(_intLiteral) {
    IntLiteral* intNode = new IntLiteral(2);
    PoolOfNodes::getInstance().add(intNode);
    Node* rhs = new PowBinaryNode(intNode, const_cast<Literal*>(y));
    PoolOfNodes::getInstance().add(rhs);
    Node* res = new MulBinaryNode(_intLiteral, rhs);
    PoolOfNodes::getInstance().add(res);
    
    return res->eval();
  }
  else {
    throw "error when shifting";
  }
}

const Literal* RightShiftNode::eval()const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();

  IntLiteral* _intLiteral = dynamic_cast<IntLiteral*>(const_cast<Literal*>(x));
  if(_intLiteral) {
    IntLiteral* intNode = new IntLiteral(2);
    PoolOfNodes::getInstance().add(intNode);
    Node* rhs = new PowBinaryNode(intNode, const_cast<Literal*>(y));
    PoolOfNodes::getInstance().add(rhs);
    Node* res = new DivBinaryNode(_intLiteral, rhs);
    PoolOfNodes::getInstance().add(res);
    
    return res->eval();
  }
  else {
    throw "error when shifting";
  }
}
