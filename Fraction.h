#pragma once

//
//�������ֵ������������
//
class Fraction {
public:
  //����
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

  int numerator; // ����
  int denominator; //��ĸ
  bool isinteger; // �Ƿ�����
};
