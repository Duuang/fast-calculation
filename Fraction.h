#pragma once

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
  //�Ӽ��˳���һ��������������ԭ���󣬷���һ���¶���
  Fraction Add(Fraction fraction);
  Fraction Subtract(Fraction fraction);
  Fraction Multiply(Fraction fraction);
  Fraction DividedBy(Fraction fraction);
  //������������ԭ���󣬷���һ���¶���
  Fraction Reciprocal();
  //�˷���expΪָ������������ԭ���󣬷���һ���¶���
  Fraction Power(int exp);
  //�õ���Ա����ֵ
  int GetNumerator();
  int GetDenominator();
  bool IsInteger();
private:
  //����
  int numerator_; 
  //��ĸ
  int denominator_;
  //�Ƿ�����
  bool isinteger_;
};

