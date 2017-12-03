#include <string>
#include <list>
#include "literal.h"

class StrLiteral: public ContainerLiteral {
public:
  ~StrLiteral() {};
  StrLiteral(const std::string _val): val(_val) {}
  StrLiteral() {}

  virtual const Literal* operator+(const Literal& rhs) const {
    return rhs.opPlus(this);
  }
  virtual const Literal* opPlus(const ContainerLiteral* lhs) const {
    StrLiteral* strNode = dynamic_cast<StrLiteral*>(const_cast<ContainerLiteral*>(lhs));
    if(strNode) {
      std::string lhs_str = strNode -> val;
      const Literal* node = new StrLiteral(lhs_str + val);
      PoolOfNodes::getInstance().add(node);
      return node;
    }
    else
      throw "Wrong operation!";
  }

  virtual const Literal* operator-(const Literal& rhs) const {
    return rhs.opSubt(this);
  }

  virtual const Literal* operator*(const Literal& rhs) const {
    return rhs.opMult(this);
  }
  virtual const Literal* opMult(int lhs) const {
    if( lhs <= 0 ) {
      const Literal* node = new StrLiteral();
      PoolOfNodes::getInstance().add(node);
      return node;
    }
    else if( lhs == 1 ) {
      const Literal* node = new StrLiteral(val);
      PoolOfNodes::getInstance().add(node);
      return node;
    }
    else {
      std::string new_str;
      for( int i = 0; i < lhs; ++i ) {
        new_str += val;
      }
      const Literal* node = new StrLiteral(new_str);
      PoolOfNodes::getInstance().add(node);
      return node;
    }
  }

  virtual const Literal* operator/(const Literal& rhs) const {
    return rhs.opDiv(this);
  }

  // We intend to overload opPower function!
  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPower(this);
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return rhs.opSubt(this);
  }

  virtual const Literal* doubleSlash(const Literal& rhs) const {
    return rhs.opPower(this);
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << val ;
  }
private:
  std::string val;
};
class Node;
void freeAST(Node*);
enum Type {tuple, list, set, dict};

class TuplesLiteral: public ContainerLiteral {
public:
  ~TuplesLiteral() { }
  TuplesLiteral() { }
  TuplesLiteral(Node* _tuples) {
    tuples.push_back(_tuples);
  }
  void add_back(Node* _tuples) {
    tuples.push_back(_tuples);
  }
  void add_front(Node* _tuples) {
    tuples.push_front(_tuples);
  }
  Node*& getItem(int index) {
    int _size = tuples.size();
    if(index < 0)
      index += _size;
    if(index < _size && index >= 0) {
      std::list<Node*>::iterator it = tuples.begin();
      std::advance(it, index);
      return *it;
    }
    else
      throw "out of range!"; 
  }
  Type getType() {
    return _type;
  }

  Node* getItem(int _begin, int _end) {
    int _size = tuples.size();
    if(_begin < 0)
      _begin += _size;
    if(_end < 0)
      _end += _size;
    if(_end < _size && _begin >= 0 && _begin <= _end) {
      if(_end - _begin == 1) {
        std::list<Node*>::iterator it = tuples.begin();
        std::advance(it, _begin);
        return *it;
      } else if(_begin == _end) {
        TuplesLiteral* nullTuple = new TuplesLiteral;
        PoolOfNodes::getInstance().add(nullTuple);
        return nullTuple;
      } else {
        std::list<Node*> new_list;
        std::list<Node*> copy_tuple = tuples;
        std::list<Node*>::iterator begin_it = tuples.begin();
        std::list<Node*>::iterator end_it = tuples.begin();
        std::advance(begin_it, _begin);
        std::advance(end_it, _end);
        new_list.splice( new_list.begin(), copy_tuple, begin_it, end_it );
        TuplesLiteral* node = new TuplesLiteral(new_list);
        node->setType(_type);
        PoolOfNodes::getInstance().add(node);
        return node;
      }
    }
    else
      throw "out of range!"; 
  }

  // execute the suite
  void execution() {
    std::list<Node*>::iterator it = tuples.begin();
    while(it != tuples.end()) {
      (*it)->eval();
      ++it;
    }
  }

  const std::list<Node*>& getVec() {
    return tuples;
  }

  TuplesLiteral(const std::list<Node*>& vec) {
    tuples = vec;
  }

  void setType(Type type) {
    _type = type;
  }

  virtual const Literal* operator+(const Literal& rhs) const {
    return rhs.opPlus(this);
  }
  virtual const Literal* opPlus(const ContainerLiteral* lhs) const {
    if(this->_type == set)
      throw "cannot add set!";
    TuplesLiteral* tupleNode = dynamic_cast<TuplesLiteral*>(const_cast<ContainerLiteral*>(lhs));
    if(tupleNode) {
      Type t = tupleNode->_type;
      if(this->_type != t)
        throw "cannot add different container!";
      std::list<Node*> new_vec = tupleNode->tuples;
      new_vec.insert( new_vec.end(), tuples.begin(), tuples.end() );
      TuplesLiteral* node = new TuplesLiteral(new_vec);
      node->setType(t);
      PoolOfNodes::getInstance().add(node);
      return node;
    }
    else
      throw "Wrong operation!";
  }

  virtual const Literal* operator-(const Literal& rhs) const {
    return rhs.opSubt(this);
  }

  virtual const Literal* operator*(const Literal& rhs) const {
    return rhs.opMult(this);
  }
  virtual const Literal* opMult(int lhs) const {
    if(this->_type == set)
      throw "cannot mult set!";
    if( lhs <= 0 ) {
      TuplesLiteral* node = new TuplesLiteral();
      node->setType(this->_type);
      PoolOfNodes::getInstance().add(node);
      return node;
    }
    else if( lhs == 1 ) {
      TuplesLiteral* node = new TuplesLiteral(tuples);
      node->setType(this->_type);
      PoolOfNodes::getInstance().add(node);
      return node;
    }
    else {
      std::list<Node*> new_tuples;
      for( int i = 0; i < lhs; ++i ) {
        new_tuples.insert(new_tuples.end(), tuples.begin(), tuples.end());
      }
      TuplesLiteral* node = new TuplesLiteral(new_tuples);
      node->setType(this->_type);
      PoolOfNodes::getInstance().add(node);
      return node;
    }
  }

  virtual const Literal* operator/(const Literal& rhs) const {
    return rhs.opDiv(this);
  }

  // We intend to overload opPower function!
  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPower(this);
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return rhs.opSubt(this);
  }

  virtual const Literal* doubleSlash(const Literal& rhs) const {
    return rhs.opPower(this);
  }

  virtual const Literal* eval() const { return this; }

  virtual void print() const { 
    std::list<Node*>::const_iterator it;
    switch(_type){
      case tuple:
        std::cout << "(" ;
        it = tuples.begin();
        while(it!=tuples.end()){
          // the warning is fake!
          if(dynamic_cast<StrLiteral*>(const_cast<Literal*>((*it)->eval()))) {
            std::cout << '\'';
            (*it) -> eval() -> print();
            std::cout << '\'';
          }
          else {
            (*it) -> eval() -> print();
          }
          it++;
          if(it==tuples.end()) { }
          else
            std::cout << ", ";
        }
        std::cout << ")" ;
        break;
      case list:
        std::cout << "[" ;
        it = tuples.begin();
        while(it!=tuples.end()){
          // the warning is fake!
          if(dynamic_cast<StrLiteral*>(const_cast<Literal*>((*it)->eval()))) {
            std::cout << '\'';
            (*it) -> eval() -> print();
            std::cout << '\'';
          }
          else {
            (*it) -> eval() -> print();
          }
          it++;
          if(it==tuples.end()) { }
          else
            std::cout << ", ";
        }
        std::cout << "]" ;
        break;
      case set:
        std::cout << "set([" ;
        it = tuples.begin();
        while(it!=tuples.end()){
          // the warning is fake!
          if(dynamic_cast<StrLiteral*>(const_cast<Literal*>((*it)->eval()))) {
            std::cout << '\'';
            (*it) -> eval() -> print();
            std::cout << '\'';
          }
          else {
            (*it) -> eval() -> print();
          }
          it++;
          if(it==tuples.end()) { }
          else
            std::cout << ", ";
        }
        std::cout << "])" ;
        break;
      default:
        break;
    }
  }
private:
  std::list<Node*> tuples;
  Type _type = tuple;
};


