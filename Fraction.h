#pragma once

//
//保存分数值，并进行运算
//
class Fraction {
public:
  //化简
  int Simplify();
 /* {
    while (true) {
      int i;
      for (i = 2; i <= denominator; i++) {
        if (numerator % i == 0 && denominator % i == 0) {
          numerator = numerator / i;
          denominator = denominator / i;
          break;
        }
      }
      if (i == denominator + 1 || denominator == 1)
        return;
    }
  }*/
  Fraction Add(Fraction fraction);
  Fraction Subtract(Fraction fraction);

  int numerator; // 分子
  int denominator; //分母
  bool isinteger; // 是否整数
};
