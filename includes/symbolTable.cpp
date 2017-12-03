#include "symbolTable.h"
#include "ast.h"

//SymbolTable& SymbolTable::getInstance() {
//  static SymbolTable instance;
//  return instance;
//}

const Literal* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = table_var.find(name);
  if ( it == table_var.end() ) {
    SymbolTable* tmp = parent;
    while(tmp) {
      std::map<std::string, const Literal*>::const_iterator it = tmp->table_var.find(name);
      if ( it == table_var.end() ) 
        tmp = tmp -> parent;
      else
        return it->second;
    }
    NoneTypeLiteral* None = new NoneTypeLiteral;
    PoolOfNodes::getInstance().add(None);
    return None;
    //throw name+std::string(" not found");
  }
  else
    return it->second;
}

Node* SymbolTable::getFunc(const std::string& name) const {
  std::map<std::string, Node*>::const_iterator it = table_func.find(name);
  if ( it == table_func.end() ) {
    SymbolTable* tmp = parent;
    while(tmp) {
      std::map<std::string, Node*>::const_iterator it = tmp->table_func.find(name);
      if ( it == table_func.end() ) 
        tmp = tmp -> parent;
      else
        return it->second;
    }
    NoneTypeLiteral* None = new NoneTypeLiteral;
    PoolOfNodes::getInstance().add(None);
    return None;
    //throw name+std::string(" not found");
  }
  else
    return it->second;
}

void SymbolTable::setValue(const std::string& name, const Literal* val) { 
  std::map<std::string, Node*>::const_iterator it = table_func.find(name);
  if ( it != table_func.end() ) {
    table_func.erase(it);
  }
  table_var[name] = val;  
}

void SymbolTable::setValue(const std::string& name, Node* val) {
  std::map<std::string, const Literal*>::const_iterator it = table_var.find(name);
  if ( it != table_var.end() ) {
    table_var.erase(it);
  }
  table_func[name] = val;
}

void SymbolTable::setValue(TuplesLiteral* identVecNode, TuplesLiteral* tupleVecNode) {

  const std::list<Node*>& identVec = identVecNode -> getVec();
  const std::list<Node*>& tupleVec = tupleVecNode -> getVec();
  if( identVec.size() != tupleVec.size() )
    throw "cannot assign";
  std::list<Node*>::const_iterator identIt = identVec.begin();
  std::list<Node*>::const_iterator tupleIt = tupleVec.begin();
  while(identIt != identVec.end()) {
    IdentNode* tempidentNode = dynamic_cast<IdentNode*>(*identIt);
    // IS identnode
    if(tempidentNode) {
      const std::string n = tempidentNode->getIdent();
      table_var[n] = (*tupleIt)->eval();
    }
    // IS NOT identnode
    else {
      throw "cannot have NONE Ident in the parameters list!";
    }
    ++identIt;
    ++tupleIt;
  }
}
