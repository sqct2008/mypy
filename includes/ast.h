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
  virtual TypeName getTypeName() const { return RETURNTYPE; }
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

class GlobalNode : public Node {
public:
  GlobalNode(TuplesLiteral* _varList) : Node(), globalVar(_varList) { } 
  virtual ~GlobalNode() {}
  virtual const Node* eval(SymbolTable*);
private:
  TuplesLiteral* globalVar;
};


class SuiteNode;

class FuncDef : public Node {
public:
  FuncDef(std::string , TuplesLiteral* , SuiteNode* );
  virtual ~FuncDef() { }
  std::string getID() { return id; }
  TuplesLiteral* getParas() { return parametersList; }
  SuiteNode* getSuite() { return suite; }
  SymbolTable* getSymbolTable() { return initial_symbolTable; }
  void setParents(SymbolTable*);
  virtual TypeName getTypeName() const { return FUNCDEF; }
  virtual const Node* eval(SymbolTable*) { return nullptr; }
private:
  std::string id;
  TuplesLiteral* parametersList;
  SymbolTable* initial_symbolTable = nullptr;
  SuiteNode* suite;
};

class FuncCall : public Node {
public:
  FuncCall(std::string _id, TuplesLiteral* arguments) : Node(), id(_id), argumentsList(arguments){  } 
  FuncCall(FuncDef* _funcDef, TuplesLiteral* _argumentsList) : node(_funcDef), argumentsList(_argumentsList) { if(!node) std::cout << "no funcdef" << std::endl; }
  virtual ~FuncCall() { }
  virtual TypeName getTypeName() const { return FUNCCALL; }
  virtual const Node* eval(SymbolTable*);
private:
  std::string id;
  Node* node = nullptr;
  TuplesLiteral* argumentsList;
  SymbolTable* symbolTable = nullptr;
};

class ClosureNode : public Node {
public:
  ClosureNode(FuncDef* _funcDef, SymbolTable* _symbolTable) : funcDef(_funcDef), symbolTable(_symbolTable) { }
  // They are all copy of other node's attribute, so no need to delete
  virtual ~ClosureNode() { ; }
  SymbolTable* getSymbolTable() { return symbolTable; }
  FuncDef* getFuncDef() { return funcDef; }
  virtual TypeName getTypeName() const { return CLOSURE; }
  virtual const Node* eval(SymbolTable*);
private:
  FuncDef* funcDef;
  SymbolTable* symbolTable;
};

class IFNode : public Node {
public:
  IFNode(Node* _test, SuiteNode* _suite);
  virtual ~IFNode() { }
  void add_suite(TuplesLiteral* suite_trailer);
  void add_line(SuiteNode* suite_trailer);
  virtual TypeName getTypeName() const { return IFELSE; }
  virtual const Node* eval(SymbolTable*);
private:
  Node* test;
  TuplesLiteral* tuple_if_suite;
};

class SuiteNode : public Node {
public:
  SuiteNode(Node* line) : suite(new TuplesLiteral(line)) { 
    PoolOfNodes::getInstance().add(suite);
  } 
  virtual ~SuiteNode() { }
  void addLine(Node*);
  TuplesLiteral* getSuite() { return suite; }
  const std::list<Node*>& getLines() { return suite -> getVec(); }
  virtual const Node* eval(SymbolTable*);
private:
  TuplesLiteral* suite;
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
  virtual TypeName getTypeName() const { return ASSIGN; }
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

class GreaterNode : public BinaryNode {
public:
  GreaterNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};

class LessNode : public BinaryNode {
public:
  LessNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};

class GreaterEQNode : public BinaryNode {
public:
  GreaterEQNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};

class LessEQNode : public BinaryNode {
public:
  LessEQNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};

class EQEqualNode : public BinaryNode {
public:
  EQEqualNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};

class NotEQNode : public BinaryNode {
public:
  NotEQNode(Node* left, Node* right) : BinaryNode(left,right) { }
  virtual const Node* eval(SymbolTable*);
};


