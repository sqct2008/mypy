#include <cmath>
#include <iomanip>
#include "node.h"
#include "poolOfNodes.h"
class ContainerLiteral; 
class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+(const Literal& rhs) const =0;
  virtual const Literal* opPlus(long double) const =0;
  virtual const Literal* opPlus(int) const =0;
  virtual const Literal* opPlus(const ContainerLiteral*) const =0;

  virtual const Literal* operator*(const Literal& rhs) const =0;
  virtual const Literal* opMult(long double) const =0;
  virtual const Literal* opMult(int) const =0;
  virtual const Literal* opMult(const ContainerLiteral*) const =0;

  virtual const Literal* operator-(const Literal& rhs) const =0;
  virtual const Literal* opSubt(long double) const =0;
  virtual const Literal* opSubt(int) const =0;
  virtual const Literal* opSubt(const ContainerLiteral*) const =0;

  virtual const Literal* operator/(const Literal& rhs) const =0;
  virtual const Literal* opDiv(long double) const =0;
  virtual const Literal* opDiv(int) const =0;
  virtual const Literal* opDiv(const ContainerLiteral*) const =0;

  virtual const Literal* opPower(const Literal& rhs) const =0;
  virtual const Literal* opPower(long double) const =0;
  virtual const Literal* opPower(int) const =0;
  virtual const Literal* opPower(const ContainerLiteral*) const =0;

  virtual const Literal* operator%(const Literal& rhs) const =0;
  virtual const Literal* opMod(long double) const =0;
  virtual const Literal* opMod(int) const =0;
  virtual const Literal* opMod(const ContainerLiteral*) const =0;

  virtual const Literal* doubleSlash(const Literal& rhs) const = 0;
  virtual const Literal* doubleSlash(long double) const =0;
  virtual const Literal* doubleSlash(int) const =0;
  virtual const Literal* doubleSlash(const ContainerLiteral*) const =0;

  virtual const Literal* eval() const = 0;
  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};

class ContainerLiteral: public Literal {

public:
  virtual ~ContainerLiteral() {};

  virtual const Literal* operator+(const Literal& ) const =0;
  virtual const Literal* opPlus(int ) const {
    throw "cannot add \'Container\' with \'int\'!";
  }
  virtual const Literal* opPlus(long double ) const {
    throw "cannot add \'Container\' with \'float\'!";
  }
  virtual const Literal* opPlus(const ContainerLiteral* ) const =0;

  virtual const Literal* operator-(const Literal& ) const =0;
  virtual const Literal* opSubt(int ) const {
    throw "cannot sub \'Container\' with \'int\'!";
  }
  virtual const Literal* opSubt(long double ) const {
    throw "cannot sub \'Container\' with \'float\'!";
  }
  virtual const Literal* opSubt(const ContainerLiteral* ) const {
     throw "cannot sub \'Container\' with \'Container\'!";
  }

  virtual const Literal* operator*(const Literal& ) const =0;
  virtual const Literal* opMult(int ) const =0;
  virtual const Literal* opMult(long double ) const {
    throw "cannot mult \'Container\' with \'float\'!";
  }
  virtual const Literal* opMult(const ContainerLiteral* ) const {
    throw "cannot mult \'Container\' with \'Container\'!";
  }

  virtual const Literal* operator/(const Literal& ) const =0;
  virtual const Literal* opDiv(int ) const {
    throw "cannot div \'Container\' with \'int\'!";
  }
  virtual const Literal* opDiv(long double ) const {
    throw "cannot div \'Container\' with \'float\'!";
  }
  virtual const Literal* opDiv(const ContainerLiteral* ) const {
    throw "cannot div \'Container\' with \'Container\'!";
  }

  virtual const Literal* opPower(const Literal& ) const =0;
  virtual const Literal* opPower(long double ) const {
    throw "cannot power \'Container\' with \'int\'!";
  }
  virtual const Literal* opPower(int ) const {
    throw "cannot power \'Container\' with \'int\'!";
  }
  virtual const Literal* opPower(const ContainerLiteral* ) const {
    throw "cannot power \'Container\' with \'Container\'!";
  }

  virtual const Literal* eval() const = 0; 
  virtual void print() const { 
    std::cout << "No way!" << std::endl;
  }

  virtual const Literal* operator%(const Literal& ) const =0;
  virtual const Literal* opMod(int ) const {
    throw "cannot div \'Container\' with \'int\'!";
  }
  virtual const Literal* opMod(long double ) const {
    throw "cannot div \'Container\' with \'float\'!";
  }
  virtual const Literal* opMod(const ContainerLiteral* ) const {
    throw "cannot div \'Container\' with \'Container\'!";
  }
  virtual const Literal* doubleSlash(const Literal& rhs) const = 0;
  virtual const Literal* doubleSlash(long double ) const {
    throw "cannot doubleslash \'Container\' with \'float\'!";
  }
  virtual const Literal* doubleSlash(int ) const {
    throw "cannot doubleslash \'Container\' with \'int\'!";
  }
  virtual const Literal* doubleSlash(const ContainerLiteral*) const {
    throw "cannot doubleslash \'Container\' with \'container\'!";
  }
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(long double _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(long double lhs) const {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(const ContainerLiteral*) const {
    throw "cannot add \'Container\' with \'int\'!";
  }

  virtual const Literal* operator-(const Literal& rhs) const {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(long double lhs) const {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(const ContainerLiteral*) const {
    throw "cannot add \'Container\' with \'int\'!";
  }

  virtual const Literal* operator*(const Literal& rhs) const {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(long double lhs) const {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const {
    const Literal* node = new FloatLiteral(static_cast<long double>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(const ContainerLiteral* lhs) const {
    return lhs->opMult(val);
  }

  virtual const Literal* operator/(const Literal& rhs) const {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(long double lhs) const {
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const {
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(const ContainerLiteral*) const {
    throw "cannot div \'Container\' with \'int\'!";
  }
 
  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPower(val);
  }
  virtual const Literal* opPower(long double lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPower(int lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPower(const ContainerLiteral*) const {
    throw "cannot power \'Container\' with \'int\'!";
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(long double lhs) const {
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const {
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(const ContainerLiteral*) const {
    throw "cannot mod \'Container\' with \'float\'!";
  }

  virtual const Literal* doubleSlash(const Literal& rhs) const {
    return rhs.doubleSlash(val);
  } 
  virtual const Literal* doubleSlash(long double lhs) const {
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* doubleSlash(int lhs) const {
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* doubleSlash(const ContainerLiteral*) const {
    throw "cannot doubleslash \'Container\' with \'float\'!";
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    //std::cout << "FLOAT:" << val ; 
    std::cout << std::setprecision(17) << val ; 
    if(fmod(val,1.0) == 0) std::cout << ".0";
  }
private:
  long double val;
};

class IntLiteral: public Literal {
public:
 IntLiteral(int _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(long double lhs) const {
    const Literal* node = new FloatLiteral(val + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(const ContainerLiteral*) const {
    throw "cannot add \'Container\' with \'int\'!";
  }

  virtual const Literal* operator-(const Literal& rhs) const {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(long double lhs) const {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(const ContainerLiteral*) const {
    throw "cannot add \'Container\' with \'int\'!";
  }

  virtual const Literal* operator*(const Literal& rhs) const {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(long double lhs) const {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(const ContainerLiteral* lhs) const {
    return lhs->opMult(val);
  }

  virtual const Literal* operator/(const Literal& rhs) const {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(long double lhs) const {
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const {
    const Literal* node = new IntLiteral(floor(static_cast<long double>(lhs) / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(const ContainerLiteral*) const {
    throw "cannot add \'Container\' with \'int\'!";
  }

  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPower(val);
  }
  virtual const Literal* opPower(long double lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPower(int lhs) const {
    const Literal* node = new IntLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPower(const ContainerLiteral*) const {
    throw "cannot add \'Container\' with \'int\'!";
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(long double lhs) const {
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const {
    const Literal* node = new IntLiteral(lhs % val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(const ContainerLiteral*) const {
    throw "cannot mod \'Container\' with \'int\'!";
  }
  virtual const Literal* doubleSlash(const Literal& rhs) const {
    return rhs.doubleSlash(val);
  } 
  virtual const Literal* doubleSlash(long double lhs) const {
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* doubleSlash(int lhs) const {
    const Literal* node = new IntLiteral(floor(static_cast<long double>(lhs) / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* doubleSlash(const ContainerLiteral*) const {
    throw "cannot doubleslash \'Container\' with \'float\'!";
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    //std::cout << "INT:" << val ; 
    std::cout << val ; 
  }
private:
  int val;
};
