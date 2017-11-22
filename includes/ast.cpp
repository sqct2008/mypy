#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"

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


const Literal* IdentNode::eval() const { 
  const Node* val = SymbolTable::getInstance().getValue(ident);
  const Literal* res = val-> eval();
  return res;
}


AssBinaryNode::AssBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
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
    SymbolTable::getInstance().setValue(n, res);
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
        SymbolTable::getInstance().setValue(n, (*tupleIt)->eval());
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
