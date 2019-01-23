#pragma once
#include <string>
#include <iostream>
using namespace std;
//
//�������ֵ������������
//
class Fraction {
public:
  Fraction();
  //���ع��캯������Ҫ������Ӻͷ�ĸ����ĸ����Ϊ0
  Fraction(int numerator, int denominator);
  //���÷��ӷ�ĸ��ͬ���캯��
  void Set(int numerator, int denominator);
  //���򣬷���Fraction�࣬����ԭ����
  Fraction Simplify();
  //����һ��������������ԭ���󣬷���һ���¶���
  Fraction Add(Fraction fraction);
  //����һ��������������ԭ���󣬷���һ���¶���
  Fraction Subtract(Fraction fraction);
  //����һ��������������ԭ���󣬷���һ���¶���
  Fraction Multiply(Fraction fraction);
  //����һ��������������ԭ���󣬷���һ���¶���
  Fraction DividedBy(Fraction fraction);
  //������������ԭ���󣬷���һ���¶���
  Fraction Reciprocal();
  //�˷���expΪָ����������ԭ���󣬷���һ���¶���
  Fraction Power(int exp);
  //ת��Ϊstring�ַ���������Ϊʮ��������������Ϊa/b�������ո�
  string ToString();
  //�õ���Ա����ֵ
  int GetNumerator();
  //�õ���Ա����ֵ
  int GetDenominator();
  //�õ���Ա����ֵ
  bool IsInteger();

private:
  //����
  int numerator_; 
  //��ĸ
  int denominator_;
  //�Ƿ�����
  bool isinteger_;
};

