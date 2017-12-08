#pragma once
#include <iostream>

class Literal;
class SymbolTable;

enum TypeName { NODE, LITERAL, NONETYPE, FUNCDEF, FUNCCALL, RETURNTYPE, IFELSE, CLOSURE, ASSIGN};

class Node {
public:
  Node() {}
  virtual ~Node() {}
  virtual TypeName getTypeName() const { return NODE; }
  virtual const Node* eval(SymbolTable*) = 0;
  virtual void print() const { 
    std::cout << "NODE" << std::endl; 
  }
};

