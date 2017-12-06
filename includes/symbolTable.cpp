#include "symbolTable.h"
#include "ast.h"

extern NoneTypeLiteral NONE;

Node* SymbolTable::getValue(const std::string name) const {
  std::map<std::string, Node*>::const_iterator it = table.find(name);
  if ( it == table.end() ) {
    SymbolTable* tmp = parents;
    while(tmp) {
      std::map<std::string, Node*>::const_iterator it = tmp->table.find(name);
      if ( it == tmp -> table.end() ) {
        tmp = tmp -> parents;
      }
      else
        return it->second;
    }
    std::cout << "no name in symbolTable" << std::endl;
    return &NONE;
  }
  else
    return it->second;
}

// XXX: only used within AssBinaryNode::eval()
bool SymbolTable::findNative(const std::string name) const {
  std::map<std::string, Node*>::const_iterator it = table.find(name);
  if ( it == table.end() ) {
    return false;
  }
  else
    return true;
}

void SymbolTable::setValue(const std::string& name, Node* val) {
  table[name] = val;
}

void SymbolTable::setParents(SymbolTable* symbolTable) {
  if(!symbolTable)
    throw "cannot add parents to symbolTable";
  parents = symbolTable;
}

void SymbolTable::print() const {
  for(auto it : table) {
    std::cout << it.first << "=";
    (it.second) -> eval(const_cast<SymbolTable*>(this)) -> print();
    std::cout << std::endl;
  }
}
