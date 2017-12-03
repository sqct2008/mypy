#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>

class Node;
class Literal;
class TuplesLiteral;

class SymbolTable {
public:
  SymbolTable() {}
  void setValue(const std::string& name, const Literal* val);
  void setValue(const std::string& name, Node* val);
  void setValue(TuplesLiteral*, TuplesLiteral*);
  const Literal* getValue(const std::string& name) const;
  Node* getFunc(const std::string& name) const;
private:
  std::map<std::string, const Literal*> table_var;
  std::map<std::string, Node*> table_func;
  SymbolTable* parent = nullptr;
};

#endif
