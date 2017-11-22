#include <iostream>
#include <vector>
class BigInt {
public:
  BigInt();
  BigInt(long);
  BigInt(const BigInt&);
  BigInt& operator=(const BigInt&);
  BigInt& operator+(const BigInt&);
  BigInt& operator-(const BigInt&);
  BigInt& operator*(const BigInt&);
  BigInt& operator/(const BigInt&);

private:
  friend std::ostream& operator<<(std::ostream&, const BigInt&);
  std::vector<unsigned long> intVec;
  bool sign;
};
