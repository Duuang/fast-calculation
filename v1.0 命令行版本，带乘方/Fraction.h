#pragma once
#include <string>
#include <iostream>
using namespace std;
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
  //加另一个分数，不更改原对象，返回一个新对象
  Fraction Add(Fraction fraction);
  //减另一个分数，不更改原对象，返回一个新对象
  Fraction Subtract(Fraction fraction);
  //乘另一个分数，不更改原对象，返回一个新对象
  Fraction Multiply(Fraction fraction);
  //除另一个分数，不更改原对象，返回一个新对象
  Fraction DividedBy(Fraction fraction);
  //倒数，不更改原对象，返回一个新对象
  Fraction Reciprocal();
  //乘方，exp为指数，不更改原对象，返回一个新对象
  Fraction Power(int exp);
  //转化为string字符串，整数为十进制整数，分数为a/b，不带空格
  string ToString();
  //得到成员变量值
  int GetNumerator();
  //得到成员变量值
  int GetDenominator();
  //得到成员变量值
  bool IsInteger();

private:
  //分子
  int numerator_; 
  //分母
  int denominator_;
  //是否整数
  bool isinteger_;
};

