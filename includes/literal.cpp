#include "literal.h"

const BoolLiteral* NoneTypeLiteral::opGreater(long double ) const {
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opGreater(int ) const {
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opGreater(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opGreater(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const BoolLiteral* NoneTypeLiteral::opGreaterEQ(long double ) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opGreaterEQ(int ) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opGreaterEQ(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opGreaterEQ(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const BoolLiteral* NoneTypeLiteral::opEQEqual(long double) const {
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opEQEqual(int) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opEQEqual(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* NoneTypeLiteral::opEQEqual(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}


const BoolLiteral* FloatLiteral::opGreater(long double lhs) const {
  const BoolLiteral* node = new BoolLiteral(lhs > val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opGreater(int lhs) const {
  const BoolLiteral* node = new BoolLiteral(lhs > val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opGreater(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opGreater(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const BoolLiteral* FloatLiteral::opGreaterEQ(long double lhs) const { 
  const BoolLiteral* node = new BoolLiteral(lhs >= val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opGreaterEQ(int lhs) const { 
  const BoolLiteral* node = new BoolLiteral(lhs >= val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opGreaterEQ(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opGreaterEQ(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const BoolLiteral* FloatLiteral::opEQEqual(long double lhs) const {
  const BoolLiteral* node = new BoolLiteral(lhs == val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opEQEqual(int lhs) const { 
  const BoolLiteral* node = new BoolLiteral(lhs == val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opEQEqual(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* FloatLiteral::opEQEqual(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}



const BoolLiteral* IntLiteral::opGreater(long double lhs) const {
  const BoolLiteral* node = new BoolLiteral(lhs > val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opGreater(int lhs) const {
  const BoolLiteral* node = new BoolLiteral(lhs > val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opGreater(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opGreater(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const BoolLiteral* IntLiteral::opGreaterEQ(long double lhs) const { 
  const BoolLiteral* node = new BoolLiteral(lhs >= val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opGreaterEQ(int lhs) const { 
  const BoolLiteral* node = new BoolLiteral(lhs >= val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opGreaterEQ(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opGreaterEQ(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const BoolLiteral* IntLiteral::opEQEqual(long double lhs) const {
  const BoolLiteral* node = new BoolLiteral(lhs == val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opEQEqual(int lhs) const { 
  const BoolLiteral* node = new BoolLiteral(lhs == val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opEQEqual(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* IntLiteral::opEQEqual(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}


const BoolLiteral* ContainerLiteral::opGreater(long double ) const {
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opGreater(int ) const {
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opGreater(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opGreater(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const BoolLiteral* ContainerLiteral::opGreaterEQ(long double ) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opGreaterEQ(int ) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opGreaterEQ(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opGreaterEQ(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(true);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const BoolLiteral* ContainerLiteral::opEQEqual(long double) const {
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opEQEqual(int) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opEQEqual(const NoneTypeLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const BoolLiteral* ContainerLiteral::opEQEqual(const ContainerLiteral*) const { 
  const BoolLiteral* node = new BoolLiteral(false);
  PoolOfNodes::getInstance().add(node);
  return node;
}

