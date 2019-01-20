#include "Fraction.h"

Fraction::Fraction() {

}

Fraction::Fraction(int numerator, int denominator) {
  numerator_ = numerator;
  denominator_ = denominator;
  if (denominator == 1 || numerator == 0) {
    isinteger_ = true;
  } else {
    isinteger_ = false;
  }
  this->Simplify();
}

void Fraction::Set(int numerator, int denominator) {
  numerator_ = numerator;
  denominator_ = denominator;
  if (denominator == 1 || numerator == 0) {
    isinteger_ = true;
  } else {
    isinteger_ = false;
  }
  this->Simplify();
}

Fraction Fraction::Simplify() {
  if (denominator_ == 1 || numerator_ == 0) {
    if (numerator_ == 0) {
      denominator_ = 1;
      isinteger_ = true;
      return *this;
    }
    isinteger_ = true;
    return *this;
  }
  while (true) {
    int i;
    int currentdenominator = denominator_;
    for (i = 2; i <= currentdenominator; i++) {
      if (numerator_ % i == 0 && denominator_ % i == 0) {
        numerator_ = numerator_ / i;
        denominator_ = denominator_ / i;
        break;
      }
    }
    if (denominator_ == 1) {
      isinteger_ = true;
      return *this;
    }
    if (i == currentdenominator + 1)
      return *this;
  }
}

Fraction Fraction::Add(Fraction fraction) {
  int numerator = fraction.GetDenominator() * numerator_ + fraction.GetNumerator() * denominator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
Fraction Fraction::Subtract(Fraction fraction) {
  int numerator = fraction.GetDenominator() * numerator_ - fraction.GetNumerator() * denominator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
Fraction Fraction::Multiply(Fraction fraction) {
  int numerator = fraction.GetNumerator() * numerator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
Fraction Fraction::DividedBy(Fraction fraction) {
  return this->Multiply(fraction.Reciprocal());
}
Fraction Fraction::Reciprocal() {
  Fraction result(denominator_, numerator_);
  return result;
}
Fraction Fraction::Power(int exp) {
  Fraction result(1, 1);
  for (int i = 0; i < exp; i++) {
    result = result.Multiply(*this);
  }
  return result.Simplify();
}

int Fraction::GetNumerator() {
  return numerator_;
}
int Fraction::GetDenominator() {
  return denominator_;
}
bool Fraction::IsInteger() {
  return isinteger_;
}