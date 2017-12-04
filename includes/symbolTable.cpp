#include "symbolTable.h"
#include "ast.h"

//SymbolTable& SymbolTable::getInstance() {
//  static SymbolTable instance;
//  return instance;
//}

//const Literal* SymbolTable::getValue(const std::string& name) const {
//  std::map<std::string, const Literal*>::const_iterator it = table_var.find(name);
//  if ( it == table_var.end() ) {
//    SymbolTable* tmp = parent;
//    while(tmp) {
//      std::map<std::string, const Literal*>::const_iterator it = tmp->table_var.find(name);
//      if ( it == table_var.end() ) 
//        tmp = tmp -> parent;
//      else
//        return it->second;
//    }
//    NoneTypeLiteral* None = new NoneTypeLiteral;
//    PoolOfNodes::getInstance().add(None);
//    return None;
//    //throw name+std::string(" not found");
//  }
//  else
//    return it->second;
//}

Node* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, Node*>::const_iterator it = table.find(name);
  if ( it == table.end() ) {
    SymbolTable* tmp = parents;
    while(tmp) {
      std::map<std::string, Node*>::const_iterator it = tmp->table.find(name);
      if ( it == tmp -> table.end() ) {
        tmp = tmp -> parents;
        //std::cout << "need to go up in symbolTable" << std::endl;
      }
      else
        return it->second;
    }
    NoneTypeLiteral* None = new NoneTypeLiteral;
    PoolOfNodes::getInstance().add(None);
    std::cout << "no name in symbolTable" << std::endl;
    return None;
    //throw name+std::string(" not found");
  }
  else
    return it->second;
}

//void SymbolTable::setValue(const std::string& name, const Literal* val) { 
//  std::map<std::string, Node*>::const_iterator it = table_func.find(name);
//  if ( it != table_func.end() ) {
//    table_func.erase(it);
//  }
//  table_var[name] = val;  
//}

void SymbolTable::setValue(const std::string& name, Node* val) {
  //std::map<std::string, const Literal*>::const_iterator it = table_var.find(name);
  //if ( it != table_var.end() ) {
  //  table_var.erase(it);
  //}
  table[name] = val;
}

//void SymbolTable::setValue(TuplesLiteral* identVecNode, TuplesLiteral* tupleVecNode) {
//
//  const std::list<Node*>& identVec = identVecNode -> getVec();
//  const std::list<Node*>& tupleVec = tupleVecNode -> getVec();
//  if( identVec.size() != tupleVec.size() )
//    throw "cannot assign";
//  std::list<Node*>::const_iterator identIt = identVec.begin();
//  std::list<Node*>::const_iterator tupleIt = tupleVec.begin();
//  while(identIt != identVec.end()) {
//    IdentNode* tempidentNode = dynamic_cast<IdentNode*>(*identIt);
//    // IS identnode
//    if(tempidentNode) {
//      const std::string n = tempidentNode->getIdent();
//      //table_var[n] = (*tupleIt)->eval();
//      //table_var[n] = (*tupleIt)->eval(const_cast<SymbolTable*>(this));
//    }
//    // IS NOT identnode
//    else {
//      throw "cannot have NONE Ident in the parameters list!";
//    }
//    ++identIt;
//    ++tupleIt;
//  }
//}

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
