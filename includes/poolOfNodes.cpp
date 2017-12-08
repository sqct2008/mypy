#include "node.h"
#include "poolOfNodes.h"
#include "symbolTable.h"

PoolOfNodes& PoolOfNodes::getInstance() {
  static PoolOfNodes pool;
  return pool;
}

void PoolOfNodes::drainThePool() {
  for ( const Node* node : nodePool ) {
    delete node;
  }
  for ( const SymbolTable* symbolTable : symbolTablePool ) {
    delete symbolTable;
  }
}

