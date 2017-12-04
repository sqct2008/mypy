#pragma once
#include <iostream>

class Literal;
class SymbolTable;

class Node {
public:
  Node() {}
  virtual ~Node() {}
  virtual const Node* eval(SymbolTable*) = 0;
  virtual void print() const { 
    std::cout << "NODE" << std::endl; 
  }
};

