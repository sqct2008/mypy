#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>

class Node;
class TuplesLiteral;

class SymbolTable {
public:
  SymbolTable() {}
  SymbolTable(const SymbolTable&);
  ~SymbolTable() {}
  void setValue(const std::string& name, Node* val);
  void setValue(TuplesLiteral*, TuplesLiteral*);
  void setParents(SymbolTable* symbolTable);
  Node* getValue(const std::string name) const;
  bool findNative(const std::string name) const;
  bool isGlobal() { return parents ? false : true; }
  void print() const;
private:
  std::map<std::string, Node*> table;
  SymbolTable* parents = nullptr;
};

#endif
