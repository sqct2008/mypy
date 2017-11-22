#include"bigInt.h"

BigInt::BigInt(): sign(true) {
  intVec.push_back(0);
}

BigInt::BigInt(long _int): sign(_int < 0 ? false : true) {
  intVec.push_back(sign ? _int : -_int);
}

BigInt::BigInt(const BigInt& _bigInt) {
  sign = _bigInt.sign;
  intVec = _bigInt.intVec;
}

BigInt& BigInt::operator=(const BigInt& rhs) {
  this->sign = rhs.sign;
  this->intVec = rhs.intVec;
  return *this; 
}
BigInt& BigInt::operator+(const BigInt& _bigInt) {
  int max = this->intVec.size();
  int min = _bigInt.intVec.size();
  if( max < min ) {
    int temp = min; 
    min = max; 
    max = temp;
  }
}

std::ostream& operator<<(std::ostream& out, const BigInt& _bigInt) {
  out << (_bigInt.sign ? "" : "-");
  if(_bigInt.intVec.size()>2) {


  }
  else {
    out << _bigInt.intVec[0] << _bigInt.intVec[1];
  }
  return out;
}
