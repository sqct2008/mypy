#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class SymbolTable;
class Literal;

// Class Literal inherits from Node; so I'm putting the include here!
// Alternatively, we could put class Node in a file by itself and
// then only include it into literal.h
#include "containerliteral.h"

void freeAST(Node*);


class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class SuiteNode;

class FuncNode : public Node {
public:
  FuncNode(SuiteNode* _suiteNode, TuplesLiteral* parameters) : Node(), suiteNode(_suiteNode) {
    std::list<Node*> paras = parameters->getVec();
    std::list<Node*>::iterator it = paras.begin();
    while(it != paras.end()) {
      IdentNode* ident = dynamic_cast<IdentNode*>(*it);
      ident->getIdent();
      new NoneTypeLiteral();
      ++it;
    }



  } 
  virtual ~FuncNode() {}
  virtual const Literal* eval() const;
private:
  Node* parent = nullptr;
  Node* son = nullptr;
  std::vector<std::string> symboltable;
  SuiteNode* suiteNode;
};

class SuiteNode : public Node {
public:
  SuiteNode(TuplesLiteral* _lines) : Node(), suite(_lines) { } 
  // FIXME: Is it better to do deconstruction here?
  virtual ~SuiteNode() {}
  virtual const Literal* eval() const;
private:
  TuplesLiteral* suite;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class AssBinaryNode : public BinaryNode {
public:
  AssBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class DoubleSlashBinaryNode : public BinaryNode {
public:
  DoubleSlashBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval()const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Literal* eval()const;
};
