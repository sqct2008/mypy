#include <cmath>
#include <iomanip>
#include "node.h"
#include "poolOfNodes.h"
class ContainerLiteral; 
class NoneTypeLiteral;
class BoolLiteral;
class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+(const Literal& rhs) const =0;
  virtual const Literal* opPlus(long double) const =0;
  virtual const Literal* opPlus(int) const =0;
  virtual const Literal* opPlus(const NoneTypeLiteral*) const =0;
  virtual const Literal* opPlus(const ContainerLiteral*) const =0;

  virtual const Literal* operator*(const Literal& rhs) const =0;
  virtual const Literal* opMult(long double) const =0;
  virtual const Literal* opMult(int) const =0;
  virtual const Literal* opMult(const NoneTypeLiteral*) const =0;
  virtual const Literal* opMult(const ContainerLiteral*) const =0;

  virtual const Literal* operator-(const Literal& rhs) const =0;
  virtual const Literal* opSubt(long double) const =0;
  virtual const Literal* opSubt(int) const =0;
  virtual const Literal* opSubt(const NoneTypeLiteral*) const =0;
  virtual const Literal* opSubt(const ContainerLiteral*) const =0;

  virtual const Literal* operator/(const Literal& rhs) const =0;
  virtual const Literal* opDiv(long double) const =0;
  virtual const Literal* opDiv(int) const =0;
  virtual const Literal* opDiv(const NoneTypeLiteral*) const =0;
  virtual const Literal* opDiv(const ContainerLiteral*) const =0;

  virtual const Literal* opPower(const Literal& rhs) const =0;
  virtual const Literal* opPower(long double) const =0;
  virtual const Literal* opPower(int) const =0;
  virtual const Literal* opPower(const NoneTypeLiteral*) const =0;
  virtual const Literal* opPower(const ContainerLiteral*) const =0;

  virtual const Literal* operator%(const Literal& rhs) const =0;
  virtual const Literal* opMod(long double) const =0;
  virtual const Literal* opMod(int) const =0;
  virtual const Literal* opMod(const NoneTypeLiteral*) const =0;
  virtual const Literal* opMod(const ContainerLiteral*) const =0;

  virtual const Literal* doubleSlash(const Literal& rhs) const = 0;
  virtual const Literal* doubleSlash(long double) const =0;
  virtual const Literal* doubleSlash(int) const =0;
  virtual const Literal* doubleSlash(const NoneTypeLiteral*) const =0;
  virtual const Literal* doubleSlash(const ContainerLiteral*) const =0;

  virtual const BoolLiteral* operator>(const Literal& rhs) const = 0;
  virtual const BoolLiteral* opGreater(long double) const =0;
  virtual const BoolLiteral* opGreater(int) const =0;
  virtual const BoolLiteral* opGreater(const NoneTypeLiteral*) const =0;
  virtual const BoolLiteral* opGreater(const ContainerLiteral*) const =0;

  virtual const BoolLiteral* operator>=(const Literal& rhs) const = 0;
  virtual const BoolLiteral* opGreaterEQ(long double) const =0;
  virtual const BoolLiteral* opGreaterEQ(int) const =0;
  virtual const BoolLiteral* opGreaterEQ(const NoneTypeLiteral*) const =0;
  virtual const BoolLiteral* opGreaterEQ(const ContainerLiteral*) const =0;

  virtual const BoolLiteral* operator==(const Literal& rhs) const = 0;
  virtual const BoolLiteral* opEQEqual(long double) const =0;
  virtual const BoolLiteral* opEQEqual(int) const =0;
  virtual const BoolLiteral* opEQEqual(const NoneTypeLiteral*) const =0;
  virtual const BoolLiteral* opEQEqual(const ContainerLiteral*) const =0;

  virtual bool Bool() const = 0;
  virtual TypeName getTypeName() const { return LITERAL; }
  virtual const Node* eval(SymbolTable*) = 0;
  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};

class NoneTypeLiteral : public Literal {
public:
  virtual ~NoneTypeLiteral() {}
  virtual const Literal* operator+(const Literal& rhs) const {
    return rhs.opPlus(this);
  }
  virtual const Literal* opPlus(long double ) const {
    throw "cannot add \'NoneType\' with \'Float\'!";
  }
  virtual const Literal* opPlus(int ) const {
    throw "cannot add \'NoneType\' with \'int\'!";
  }
  virtual const Literal* opPlus(const NoneTypeLiteral*) const {
    throw "cannot add \'NoneType\' with \'NoneType\'!";
  }
  virtual const Literal* opPlus(const ContainerLiteral*) const {
    throw "cannot add \'NoneType\' with \'Container\'!";
  }

  virtual const Literal* operator-(const Literal& rhs) const {
    return rhs.opSubt(this);
  }
  virtual const Literal* opSubt(long double ) const {
    throw "cannot Subt \'NoneType\' with \'Float\'!";
  }
  virtual const Literal* opSubt(int ) const {
    throw "cannot Subt \'NoneType\' with \'int\'!";
  }
  virtual const Literal* opSubt(const NoneTypeLiteral*) const {
    throw "cannot Subt \'NoneType\' with \'NoneType\'!";
  }
  virtual const Literal* opSubt(const ContainerLiteral*) const {
    throw "cannot Subt \'NoneType\' with \'Container\'!";
  }

  virtual const Literal* operator*(const Literal& rhs) const {
    return rhs.opMult(this);
  }
  virtual const Literal* opMult(long double ) const {
    throw "cannot Mult \'NoneType\' with \'Float\'!";
  }
  virtual const Literal* opMult(int ) const {
    throw "cannot Mult \'NoneType\' with \'int\'!";
  }
  virtual const Literal* opMult(const NoneTypeLiteral*) const {
    throw "cannot Mult \'NoneType\' with \'NoneType\'!";
  }
  virtual const Literal* opMult(const ContainerLiteral*) const {
    throw "cannot Mult \'NoneType\' with \'Container\'!";
  }

  virtual const Literal* operator/(const Literal& rhs) const {
    return rhs.opDiv(this);
  }
  virtual const Literal* opDiv(long double ) const {
    throw "cannot Div \'NoneType\' with \'Float\'!";
  }
  virtual const Literal* opDiv(int ) const {
    throw "cannot Div \'NoneType\' with \'int\'!";
  }
  virtual const Literal* opDiv(const NoneTypeLiteral*) const {
    throw "cannot Div \'NoneType\' with \'NoneType\'!";
  }
  virtual const Literal* opDiv(const ContainerLiteral*) const {
    throw "cannot Div \'NoneType\' with \'Container\'!";
  }
 
  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPower(this);
  }
  virtual const Literal* opPower(long double ) const {
    throw "cannot Power \'NoneType\' with \'Float\'!";
  }
  virtual const Literal* opPower(int ) const {
    throw "cannot Power \'NoneType\' with \'int\'!";
  }
  virtual const Literal* opPower(const NoneTypeLiteral*) const {
    throw "cannot Power \'NoneType\' with \'NoneType\'!";
  }
  virtual const Literal* opPower(const ContainerLiteral*) const {
    throw "cannot Power \'NoneType\' with \'Container\'!";
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return rhs.opMod(this);
  }
  virtual const Literal* opMod(long double ) const {
    throw "cannot Mod \'NoneType\' with \'Float\'!";
  }
  virtual const Literal* opMod(int ) const {
    throw "cannot Mod \'NoneType\' with \'int\'!";
  }
  virtual const Literal* opMod(const NoneTypeLiteral*) const {
    throw "cannot Mod \'NoneType\' with \'NoneType\'!";
  }
  virtual const Literal* opMod(const ContainerLiteral*) const {
    throw "cannot Mod \'NoneType\' with \'Container\'!";
  }

  virtual const Literal* doubleSlash(const Literal& rhs) const {
    return rhs.doubleSlash(this);
  } 
  virtual const Literal* doubleSlash(long double ) const {
    throw "cannot doubleSlash \'NoneType\' with \'Float\'!";
  }
  virtual const Literal* doubleSlash(int ) const {
    throw "cannot doubleSlash \'NoneType\' with \'int\'!";
  }
  virtual const Literal* doubleSlash(const NoneTypeLiteral*) const {
    throw "cannot doubleSlash \'NoneType\' with \'NoneType\'!";
  }
  virtual const Literal* doubleSlash(const ContainerLiteral*) const {
    throw "cannot doubleSlash \'NoneType\' with \'Container\'!";
  }

  virtual const BoolLiteral* operator>(const Literal& rhs) const {
    return rhs.opGreater(this);
  }
  virtual const BoolLiteral* opGreater(long double ) const ;
  virtual const BoolLiteral* opGreater(int ) const ;
  virtual const BoolLiteral* opGreater(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opGreater(const ContainerLiteral*) const ;

  virtual const BoolLiteral* operator>=(const Literal& rhs) const {
    return rhs.opGreaterEQ(this);
  }
  virtual const BoolLiteral* opGreaterEQ(long double ) const ;
  virtual const BoolLiteral* opGreaterEQ(int ) const ;
  virtual const BoolLiteral* opGreaterEQ(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opGreaterEQ(const ContainerLiteral*) const ;

  virtual const BoolLiteral* operator==(const Literal& rhs) const {
    return rhs.opEQEqual(this);
  }
  virtual const BoolLiteral* opEQEqual(long double) const ;
  virtual const BoolLiteral* opEQEqual(int) const ;
  virtual const BoolLiteral* opEQEqual(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opEQEqual(const ContainerLiteral*) const ;

  virtual bool Bool() const {
    return false;
  }
  virtual TypeName getTypeName() const { return NONETYPE; }
  virtual const Node* eval(SymbolTable*) { return this; }
  virtual void print() const { 
    std::cout << "None"; 
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
  virtual const Literal* opPlus(const NoneTypeLiteral*) const {
    throw "cannot add \'Container\' with \'NoneType\'!";
  }
  virtual const Literal* opPlus(const ContainerLiteral* ) const =0;

  virtual const Literal* operator-(const Literal& ) const =0;
  virtual const Literal* opSubt(int ) const {
    throw "cannot sub \'Container\' with \'int\'!";
  }
  virtual const Literal* opSubt(long double ) const {
    throw "cannot sub \'Container\' with \'float\'!";
  }
  virtual const Literal* opSubt(const NoneTypeLiteral*) const {
    throw "cannot sub \'Container\' with \'NoneType\'!";
  }
  virtual const Literal* opSubt(const ContainerLiteral* ) const {
    throw "cannot sub \'Container\' with \'Container\'!";
  }

  virtual const Literal* operator*(const Literal& ) const =0;
  virtual const Literal* opMult(int ) const =0;
  virtual const Literal* opMult(long double ) const {
    throw "cannot mult \'Container\' with \'float\'!";
  }
  virtual const Literal* opMult(const NoneTypeLiteral*) const {
    throw "cannot Mult \'Container\' with \'NoneType\'!";
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
  virtual const Literal* opDiv(const NoneTypeLiteral*) const {
    throw "cannot div \'Container\' with \'NoneType\'!";
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
  virtual const Literal* opPower(const NoneTypeLiteral*) const {
    throw "cannot power \'Container\' with \'NoneType\'!";
  }
  virtual const Literal* opPower(const ContainerLiteral* ) const {
    throw "cannot power \'Container\' with \'Container\'!";
  }

  virtual const Literal* operator%(const Literal& ) const =0;
  virtual const Literal* opMod(int ) const {
    throw "cannot Mod \'Container\' with \'int\'!";
  }
  virtual const Literal* opMod(long double ) const {
    throw "cannot Mod \'Container\' with \'float\'!";
  }
  virtual const Literal* opMod(const NoneTypeLiteral*) const {
    throw "cannot Mod \'Container\' with \'NoneType\'!";
  }
  virtual const Literal* opMod(const ContainerLiteral* ) const {
    throw "cannot Mod \'Container\' with \'Container\'!";
  }
  virtual const Literal* doubleSlash(const Literal& rhs) const = 0;
  virtual const Literal* doubleSlash(long double ) const {
    throw "cannot doubleslash \'Container\' with \'float\'!";
  }
  virtual const Literal* doubleSlash(int ) const {
    throw "cannot doubleslash \'Container\' with \'int\'!";
  }
  virtual const Literal* doubleSlash(const NoneTypeLiteral*) const {
    throw "cannot doubleslash \'Container\' with \'NoneType\'!";
  }
  virtual const Literal* doubleSlash(const ContainerLiteral*) const {
    throw "cannot doubleslash \'Container\' with \'container\'!";
  }

  virtual const BoolLiteral* operator>(const Literal& rhs) const {
    return rhs.opGreater(this);
  }
  virtual const BoolLiteral* opGreater(long double ) const ;
  virtual const BoolLiteral* opGreater(int ) const ;
  virtual const BoolLiteral* opGreater(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opGreater(const ContainerLiteral*) const ;

  virtual const BoolLiteral* operator>=(const Literal& rhs) const {
    return rhs.opGreaterEQ(this);
  }
  virtual const BoolLiteral* opGreaterEQ(long double ) const ;
  virtual const BoolLiteral* opGreaterEQ(int ) const ;
  virtual const BoolLiteral* opGreaterEQ(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opGreaterEQ(const ContainerLiteral*) const ;

  virtual const BoolLiteral* operator==(const Literal& rhs) const {
    return rhs.opEQEqual(this);
  }
  virtual const BoolLiteral* opEQEqual(long double) const ;
  virtual const BoolLiteral* opEQEqual(int) const ;
  virtual const BoolLiteral* opEQEqual(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opEQEqual(const ContainerLiteral*) const ;

  virtual bool Bool() const {
    return true;
  }
  virtual const Node* eval(SymbolTable*) = 0; 
  virtual void print() const { 
    std::cout << "No way!" << std::endl;
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
  virtual const Literal* opPlus(const NoneTypeLiteral*) const {
    throw "cannot add \'Float\' with \'NoneType\'!";
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
  virtual const Literal* opSubt(const NoneTypeLiteral*) const {
    throw "cannot sub \'Float\' with \'NoneType\'!";
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
  virtual const Literal* opMult(const NoneTypeLiteral*) const {
    throw "cannot Mult \'Float\' with \'NoneType\'!";
  }
  virtual const Literal* opMult(const ContainerLiteral* lhs) const {
    return lhs->opMult(val);
  }

  virtual const Literal* operator/(const Literal& rhs) const {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(long double lhs) const {
    if(val == 0)
      throw "cannot divided by zero";
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const {
    if(val == 0)
      throw "cannot divided by zero";
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(const NoneTypeLiteral*) const {
    throw "cannot div \'Float\' with \'NoneType\'!";
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
  virtual const Literal* opPower(const NoneTypeLiteral*) const {
    throw "cannot power \'Float\' with \'NoneType\'!";
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
  virtual const Literal* opMod(const NoneTypeLiteral*) const {
    throw "cannot mod \'Float\' with \'NoneType\'!";
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
  virtual const Literal* doubleSlash(const NoneTypeLiteral*) const {
    throw "cannot doubleslash \'Float\' with \'NoneType\'!";
  }
  virtual const Literal* doubleSlash(const ContainerLiteral*) const {
    throw "cannot doubleslash \'Container\' with \'float\'!";
  }

  virtual const BoolLiteral* operator>(const Literal& rhs) const {
    return rhs.opGreater(val);
  }
  virtual const BoolLiteral* opGreater(long double ) const ;
  virtual const BoolLiteral* opGreater(int ) const ;
  virtual const BoolLiteral* opGreater(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opGreater(const ContainerLiteral*) const ;

  virtual const BoolLiteral* operator>=(const Literal& rhs) const {
    return rhs.opGreaterEQ(val);
  }
  virtual const BoolLiteral* opGreaterEQ(long double ) const ;
  virtual const BoolLiteral* opGreaterEQ(int ) const ;
  virtual const BoolLiteral* opGreaterEQ(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opGreaterEQ(const ContainerLiteral*) const ;

  virtual const BoolLiteral* operator==(const Literal& rhs) const {
    return rhs.opEQEqual(val);
  }
  virtual const BoolLiteral* opEQEqual(long double) const ;
  virtual const BoolLiteral* opEQEqual(int) const ;
  virtual const BoolLiteral* opEQEqual(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opEQEqual(const ContainerLiteral*) const ;

  virtual bool Bool() const {
    return val ? true : false;
  }
  virtual const Node* eval(SymbolTable*) { return this; }
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
  virtual const Literal* opPlus(const NoneTypeLiteral*) const {
    throw "cannot add \'int\' with \'NoneType\'!";
  }
  virtual const Literal* opPlus(const ContainerLiteral*) const {
    throw "cannot add \'int\' with \'Container\'!";
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
  virtual const Literal* opSubt(const NoneTypeLiteral*) const {
    throw "cannot sub \'int\' with \'NoneType\'!";
  }
  virtual const Literal* opSubt(const ContainerLiteral*) const {
    throw "cannot add \'int\' with \'Container\'!";
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
  virtual const Literal* opMult(const NoneTypeLiteral*) const {
    throw "cannot Mult \'int\' with \'NoneType\'!";
  }
  virtual const Literal* opMult(const ContainerLiteral* lhs) const {
    return lhs->opMult(val);
  }

  virtual const Literal* operator/(const Literal& rhs) const {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(long double lhs) const {
    if(val == 0)
      throw "cannot divided by zero";
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const {
    if(val == 0)
      throw "cannot divided by zero";
    const Literal* node = new IntLiteral(floor(static_cast<long double>(lhs) / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(const NoneTypeLiteral*) const {
    throw "cannot div \'int\' with \'NoneType\'!";
  }
  virtual const Literal* opDiv(const ContainerLiteral*) const {
    throw "cannot div \'int\' with \'Container\'!";
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
  virtual const Literal* opPower(const NoneTypeLiteral*) const {
    throw "cannot power \'int\' with \'NoneType\'!";
  }
  virtual const Literal* opPower(const ContainerLiteral*) const {
    throw "cannot add \'int\' with \'Container\'!";
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
  virtual const Literal* opMod(const NoneTypeLiteral*) const {
    throw "cannot mod \'int\' with \'NoneType\'!";
  }
  virtual const Literal* opMod(const ContainerLiteral*) const {
    throw "cannot mod \'int\' with \'Container\'!";
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
  virtual const Literal* doubleSlash(const NoneTypeLiteral*) const {
    throw "cannot doubleslash \'int\' with \'NoneType\'!";
  }
  virtual const Literal* doubleSlash(const ContainerLiteral*) const {
    throw "cannot doubleslash \'int\' with \'Container\'!";
  }

  virtual const BoolLiteral* operator>(const Literal& rhs) const {
    return rhs.opGreater(val);
  }
  virtual const BoolLiteral* opGreater(long double ) const ;
  virtual const BoolLiteral* opGreater(int ) const ;
  virtual const BoolLiteral* opGreater(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opGreater(const ContainerLiteral*) const ;

  virtual const BoolLiteral* operator>=(const Literal& rhs) const {
    return rhs.opGreaterEQ(val);
  }
  virtual const BoolLiteral* opGreaterEQ(long double ) const ;
  virtual const BoolLiteral* opGreaterEQ(int ) const ;
  virtual const BoolLiteral* opGreaterEQ(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opGreaterEQ(const ContainerLiteral*) const ;

  virtual const BoolLiteral* operator==(const Literal& rhs) const {
    return rhs.opEQEqual(val);
  }
  virtual const BoolLiteral* opEQEqual(long double) const ;
  virtual const BoolLiteral* opEQEqual(int) const ;
  virtual const BoolLiteral* opEQEqual(const NoneTypeLiteral*) const ;
  virtual const BoolLiteral* opEQEqual(const ContainerLiteral*) const ;

  virtual bool Bool() const {
    return val ? true : false;
  }
  virtual const Node* eval(SymbolTable*) { return this; }
  virtual void print() const { 
    //std::cout << "INT:" << val ; 
    std::cout << val ; 
  }
protected:
  int val;
};

class BoolLiteral : public IntLiteral {
public:
  BoolLiteral(bool _val) : IntLiteral(_val) {  }
  //virtual bool Bool() const;
  virtual const Node* eval(SymbolTable*) { return this; }
  void setOpposite() { val = val ? false : true; }
  virtual void print() const {
    if(val == 0) {
      std::cout << "False";
    }
    else if(val == 1) {
      std::cout << "True";
    }
    else {
      std::cout << "wrong way to print bool" << val << std::endl;
    }
  }
};

