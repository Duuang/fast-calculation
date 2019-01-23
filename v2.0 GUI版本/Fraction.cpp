#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

Fraction::Fraction() {

}

//
//���÷��ӷ�ĸ���Զ�����isinteger_������������ӷ�ĸ>10000��Ϊ����ֱ�ӷ���-1/1
//
Fraction::Fraction(int numerator, int denominator) {
  //����������ӷ�ĸ̫���Ϊ����ֱ�ӷ���-1
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
//���÷��ӷ�ĸ���Զ�����isinteger_������������ӷ�ĸ>10000��Ϊ����ֱ�ӷ���-1/1
//
void Fraction::Set(int numerator, int denominator) {
  //����������ӷ�ĸ̫���Ϊ����ֱ�ӷ���-1
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
//��������ֱ�Ӹ���ԭ���󣬲�����*this������������ӷ�ĸ>10000��Ϊ����ֱ�ӷ���-1/1
//
Fraction Fraction::Simplify() {
  //����������ӷ�ĸ̫���Ϊ����ֱ�ӷ���-1
  if (denominator_ > 10000 || numerator_ > 10000 || denominator_ <= 0 || numerator_ < 0) {
      return Fraction(-1, 1);
  }
  //�����ĸ��1�����߷�����0
  if (denominator_ == 1 || numerator_ == 0) {
    //������0������ĸ��Ϊ1��������ʶ��1
    if (numerator_ == 0) {
      denominator_ = 1;
      isinteger_ = true;
      return *this;
    }
    //����0����ĸ��1����������־��1
    isinteger_ = true;
    return *this;
  }
  //����С�ڷ�ĸ���������ܲ���ͬʱ�������ӷ�ĸ��ֱ��û���������������߷�ĸΪ1
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
    //��ĸΪ1����������־��1��ֱ�ӷ���
    if (denominator_ == 1) {
      isinteger_ = true;
      return *this;
    }
    //������־��0������
    if (i == currentdenominator + 1) {
      isinteger_ = false;
      return *this;
    }
  }
}

//
//���
//
Fraction Fraction::Add(Fraction fraction) {
  int numerator = fraction.GetDenominator() * numerator_ + fraction.GetNumerator() * denominator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
//
//���
//
Fraction Fraction::Subtract(Fraction fraction) {
  int numerator = fraction.GetDenominator() * numerator_ - fraction.GetNumerator() * denominator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
//
//���
//
Fraction Fraction::Multiply(Fraction fraction) {
  int numerator = fraction.GetNumerator() * numerator_;
  int denominator = fraction.GetDenominator() * denominator_;
  Fraction result(numerator, denominator);
  return result.Simplify();
}
//
//����
//
Fraction Fraction::DividedBy(Fraction fraction) {
  return this->Multiply(fraction.Reciprocal());
}
//
//����
//
Fraction Fraction::Reciprocal() {
  Fraction result(denominator_, numerator_);
  return result;
}
//
//�˷�������ԭ�����exp�η�
//
Fraction Fraction::Power(int exp) {
  Fraction result(1, 1);
  for (int i = 0; i < exp; i++) {
    result = result.Multiply(*this);
  }
  return result.Simplify();
}

//
//�����ַ�����ʽ
//
string Fraction::ToString() {
  char buffer[105];
  //���������
  if (isinteger_) {
    _itoa_s(numerator_, buffer, 10);
    string result = buffer;
    return result;
  //����Ƿ���
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
//��ȡ��Ա����numerator_
//
int Fraction::GetNumerator() {
  return numerator_;
}
//
//��ȡ��Ա����denominator_
//
int Fraction::GetDenominator() {
  return denominator_;
}
//
//��ȡ��Ա����isinteger_
//
bool Fraction::IsInteger() {
  return isinteger_;
}