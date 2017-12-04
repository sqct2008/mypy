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
  //void setValue(const std::string& name, const Literal* val);
  void setValue(const std::string& name, Node* val);
  void setValue(TuplesLiteral*, TuplesLiteral*);
  void setParents(SymbolTable* symbolTable);
  //const Literal* getValue(const std::string& name) const;
  Node* getValue(const std::string& name) const;
  //SymbolTable* operator=(const SymbolTable*);
  void print() const;
private:
  std::map<std::string, Node*> table;
  SymbolTable* parents = nullptr;
};

#endif
