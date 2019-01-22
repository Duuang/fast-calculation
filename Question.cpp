#include "Question.h"
#include "Fraction.h"

Question::Question() {
  amount = 0;
  number_type = ALL_INTEGER;
  if_pow_operator = false;
}

//
//�����������࣬����/����/����������ϣ������޳˷������
//
int Question::SetType(enum NumberType number_type, bool if_pow_operator) {
  this->number_type = number_type;
  this->if_pow_operator = if_pow_operator;
  return 0;
}

//
//����amount��������Ŀ�����������ַ���question_str
//
int Question::GenerateAndSave(int amount) {
  Question::QuestionGenerator generator;
  //����QuestionGenerator���Generate()
  for (int i = 0; i < amount; i++) {
    generator.GenerateOne(*this);
  }
  return 0;
}

//
//����index������Ŀ�����indexȡֵ0 ~ amount-1)
//
Fraction Question::Calculate(int index) {
  Question::QuestionCalculator calculator;
  return calculator.Calculate(index, *this);
  
}

//
//�õ�index����Ŀ��string�ַ�����indexȡֵ0 ~ amount-1)
//
string Question::GetQuestion(int index) {
  return question_str[index];
}