#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include "symbolTable.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class Literal;

// Class Literal inherits from Node; so I'm putting the include here!
// Alternatively, we could put class Node in a file by itself and
// then only include it into literal.h
#include "containerliteral.h"

void freeAST(Node*);


class ReturnNode : public Node {
public:
  ReturnNode(Node* _res) : Node(), res(_res) { } 
  virtual ~ReturnNode() {}
  virtual const Literal* eval() const;
private:
  Node* res;
};

class PrintNode : public Node {
public:
  PrintNode(Node* _res) : Node(), printList(_res) { } 
  virtual ~PrintNode() {}
  virtual const Literal* eval() const;
private:
  Node* printList;
};


class SuiteNode;

class FuncNode : public Node {
public:
  FuncNode() : Node() {}
  FuncNode(std::string _id, TuplesLiteral* arguments) : Node(), id(_id), argumentsList(arguments) { } 
  virtual ~FuncNode() {}
  virtual const Literal* eval() const;
private:
  //SuiteNode* funcBody;
  std::string id;
  TuplesLiteral* argumentsList;
  SymbolTable symbolTable;
};

class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  Node* getFunc();
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class SuiteNode : public Node {
public:
  SuiteNode(Node* line) { 
    suite = new TuplesLiteral(line);
    PoolOfNodes::getInstance().add(suite);
  } 
  // FIXME: Is it better to do deconstruction here?
  virtual ~SuiteNode() { }
  void setID(std::string );
  void addLine(Node*);
  void setParas(TuplesLiteral* );
  virtual const Literal* eval() const;
  Literal* callSuite(TuplesLiteral*) const;
  //TuplesLiteral* getSuite() { return suite; }
private:
  std::string id;
  TuplesLiteral* suite;
  TuplesLiteral* parametersList;
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

class LeftShiftNode : public BinaryNode {
public:
  LeftShiftNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Literal* eval()const;
};

class RightShiftNode : public BinaryNode {
public:
  RightShiftNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Literal* eval()const;
};
