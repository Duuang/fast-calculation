#pragma once

//
//保存分数值，并进行运算
//
class Fraction {
public:
  Fraction();
  //重载构造函数，需要传入分子和分母，分母不能为0
  Fraction(int numerator, int denominator);
  //设置分子分母，同构造函数
  void Set(int numerator, int denominator);
  //化简，返回Fraction类，更改原对象
  Fraction Simplify();
  //加减乘除另一个分数，不更改原对象，返回一个新对象
  Fraction Add(Fraction fraction);
  Fraction Subtract(Fraction fraction);
  Fraction Multiply(Fraction fraction);
  Fraction DividedBy(Fraction fraction);
  //倒数，不更改原对象，返回一个新对象
  Fraction Reciprocal();
  //乘方，exp为指数，，不更改原对象，返回一个新对象
  Fraction Power(int exp);
  //得到成员变量值
  int GetNumerator();
  int GetDenominator();
  bool IsInteger();
private:
  //分子
  int numerator_; 
  //分母
  int denominator_;
  //是否整数
  bool isinteger_;
};

