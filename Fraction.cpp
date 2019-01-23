#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

Fraction::Fraction() {

}

//
//设置分子分母，自动设置isinteger_，如果分数分子分母>10000或为负，直接返回-1/1
//
Fraction::Fraction(int numerator, int denominator) {
  //如果分数分子分母太大或为负，直接返回-1
  if (denominator > 10000 || numerator > 10000 || denominator <= 0 || numerator < 0) {
      denominator_ = 1;
      numerator_ = -1;
      isinteger_ = true;
      return;
  }
  numerator_ = numerator;
  denominator_ = denominator;
  if (denominator == 1 || numerator == 0) {
    isinteger_ = true;
  } else {
    isinteger_ = false;
  }
  this->Simplify();
}

//
//设置分子分母，自动设置isinteger_，如果分数分子分母>10000或为负，直接返回-1/1
//
void Fraction::Set(int numerator, int denominator) {
  //如果分数分子分母太大或为负，直接返回-1
  if (denominator > 10000 || numerator > 10000 || denominator <= 0 || numerator < 0) {
      denominator_ = 1;
      numerator_ = -1;
      isinteger_ = true;
      return;
  }
  numerator_ = numerator;
  denominator_ = denominator;
  if (denominator == 1 || numerator == 0) {
    isinteger_ = true;
  } else {
    isinteger_ = false;
  }
  this->Simplify();
}

//
//分数化简，直接更改原对象，并返回*this，如果分数分子分母>10000或为负，直接返回-1/1
//
Fraction Fraction::Simplify() {
  //如果分数分子分母太大或为负，直接返回-1
  if (denominator_ > 10000 || numerator_ > 10000 || denominator_ <= 0 || numerator_ < 0) {
      return Fraction(-1, 1);
  }
  //如果分母是1，或者分子是0
  if (denominator_ == 1 || numerator_ == 0) {
    //分子是0，将分母改为1，整数标识改1
    if (numerator_ == 0) {
      denominator_ = 1;
      isinteger_ = true;
      return *this;
    }
    //不是0，分母是1，则整数标志改1
    isinteger_ = true;
    return *this;
  }
  //遍历小于分母的数，看能不能同时整除分子分母，直到没有这样的数，或者分母为1
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
    //分母为1，则整数标志设1，直接返回
    if (denominator_ == 1) {
      isinteger_ = true;
      return *this;
    }
    //整数标志设0，返回
    if (i == currentdenominator + 1) {
      isinteger_ = false;
      return *this;
    }
  }
}

//
//相加
//
Fraction Fraction::Add(Fraction fraction) {
  int numerator = fraction.GetDenominator() * numerator_ + fraction.GetNumerator() * denominator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
//
//相减
//
Fraction Fraction::Subtract(Fraction fraction) {
  int numerator = fraction.GetDenominator() * numerator_ - fraction.GetNumerator() * denominator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
//
//相乘
//
Fraction Fraction::Multiply(Fraction fraction) {
  int numerator = fraction.GetNumerator() * numerator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
//
//除以
//
Fraction Fraction::DividedBy(Fraction fraction) {
  return this->Multiply(fraction.Reciprocal());
}
//
//倒数
//
Fraction Fraction::Reciprocal() {
  Fraction result(denominator_, numerator_);
  return result;
}
//
//乘方，返回原对象的exp次方
//
Fraction Fraction::Power(int exp) {
  Fraction result(1, 1);
  for (int i = 0; i < exp; i++) {
    result = result.Multiply(*this);
  }
  return result.Simplify();
}

//
//返回字符串形式
//
string Fraction::ToString() {
  char buffer[105];
  //如果是整数
  if (isinteger_) {
    _itoa_s(numerator_, buffer, 10);
    string result = buffer;
    return result;
  //如果是分数
  } else {
    _itoa_s(numerator_, buffer, 10);
    string result = buffer;
    result.push_back('/');
    _itoa_s(denominator_, buffer, 10);
    result.append(buffer);
    return result;
  }
}

//
//获取成员变量numerator_
//
int Fraction::GetNumerator() {
  return numerator_;
}
//
//获取成员变量denominator_
//
int Fraction::GetDenominator() {
  return denominator_;
}
//
//获取成员变量isinteger_
//
bool Fraction::IsInteger() {
  return isinteger_;
}