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


class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Node* eval(SymbolTable*);
private:
  std::string ident;
};

class ReturnNode : public Node {
public:
  ReturnNode(Node* _res) : Node(), res(_res) { } 
  virtual ~ReturnNode() {}
  virtual const Node* eval(SymbolTable*);
private:
  Node* res;
};

class PrintNode : public Node {
public:
  PrintNode(Node* _res) : Node(), printList(_res) { } 
  virtual ~PrintNode() {}
  virtual const Node* eval(SymbolTable*);
private:
  Node* printList;
};

class FuncNode : public Node {
public:
  FuncNode(std::string _id, TuplesLiteral* arguments) : Node(), id(_id), argumentsList(arguments){ } 
  //FuncNode(, TuplesLiteral* arguments) : Node(), id(_id), argumentsList(arguments){ } 
  virtual ~FuncNode() { delete symbolTable; }
  virtual const Node* eval(SymbolTable*);
private:
  std::string id;
  TuplesLiteral* argumentsList;
  SymbolTable* symbolTable = nullptr;
};

class SuiteNode;

class ClosureNode : public Node {
public:
  ClosureNode(SuiteNode* _suite, SymbolTable* _symbolTable) : suite(_suite), symbolTable(_symbolTable) {  }
  // They are all copy of other node's attribute, so no need to delete
  virtual ~ClosureNode() {}
  SymbolTable* getSymbolTable() { return symbolTable; }
  SuiteNode* getSuiteNode() { return suite; }
  virtual const Node* eval(SymbolTable*);
private:
  SuiteNode* suite;
  SymbolTable* symbolTable;
};

class SuiteNode : public Node {
public:
  SuiteNode(Node* line) : suite(new TuplesLiteral(line)) { 
    PoolOfNodes::getInstance().add(suite);
  } 
  virtual ~SuiteNode() { }
  void setID(std::string);
  std::string getID() { return id; }
  void addLine(Node*);
  void setParas(TuplesLiteral* );
  Node* getParas();
  virtual const Node* eval(SymbolTable*);
private:
  std::string id;
  TuplesLiteral* suite;
  TuplesLiteral* parametersList;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Node* eval(SymbolTable*) = 0;
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
  virtual const Node* eval(SymbolTable*);
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval(SymbolTable*);
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval(SymbolTable*);
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Node* eval(SymbolTable*);
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval(SymbolTable*);
};

class DoubleSlashBinaryNode : public BinaryNode {
public:
  DoubleSlashBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval(SymbolTable*);
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Node* eval(SymbolTable*);
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};

class LeftShiftNode : public BinaryNode {
public:
  LeftShiftNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};

class RightShiftNode : public BinaryNode {
public:
  RightShiftNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};
