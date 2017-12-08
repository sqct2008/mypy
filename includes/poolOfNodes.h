#include <vector>
class Node;
class SymbolTable;

class PoolOfNodes {
public:
  static PoolOfNodes& getInstance();
  void add(const Node* node) { nodePool.push_back(node); }
  void addSymbolTable(const SymbolTable* symbolTable) { symbolTablePool.push_back(symbolTable); }
  void drainThePool();
private:
  std::vector<const Node*> nodePool;
  std::vector<const SymbolTable*> symbolTablePool;
  PoolOfNodes() : nodePool(), symbolTablePool() {}
};
