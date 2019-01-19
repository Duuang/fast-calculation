#pragma once
#include "Fraction.h"
#include <string>

//
//����Ƕ����QuestionGenerator��QuestionCalculator
//�������ò���������ָ��������Ŀ������ĳ��Ľ��
//
class Question {
private:
  class QuestionGenerator; //��������Question���Ƕ���࣬���ϾۺϹ�ϵ,��ֱ�ӷ���Question���˽�в���
  class QuestionCalculator;
  enum NumberType {  //��ʾ����/����/�����������
    ALL_INTEGER = 1,
    ALL_FRACTION,
    INTEGER_AND_FRACTION
  };

public:
  //��ʼ����Ա����
  Question();
  //�������ɵ��������ͣ�����/�������������˷�
  int SetType(enum NumberType number_type, bool if_pow_calculator);
  //����ָ�������Ĳ�ͬ���⣬���浽�ļ�
  int GenerateAndSave(int amount);  
  //������ʽֵ
  Fraction Calculate(int index);

private:
  //�������ʽ�������ţ�������������пո�
  std::string question_str[1005];
  //��׺���ʽ��������������пո�
  std::string postfix_expression[1005];
  //������Ŀ������
  int amount;
  //������÷�����ʾ
  Fraction results[1005];
  //����/����/�����������
  enum NumberType number_type;
  //�������˷�
  bool if_pow_operator;
};

//
//��������һ�����ظ�����Ŀ
//
class Question::QuestionGenerator {
public:
  //����һ��������Question�����Ҫ����Question���˽�в���
  int Generate(Question &question);  
private:
  int Random(int x, int y);
  //�������һ������
  //�жϺ�֮ǰ�������Ƿ��ظ�����
};

//
//����index���������Ŀ��ֵ���Է�����ʽ����
//
class Question::QuestionCalculator {
public:
  //����index����ֵ
  Fraction Calculate(int index, Question &question);
private:
  //���ɺ�׺���ʽ����
  //���㣨��
};

