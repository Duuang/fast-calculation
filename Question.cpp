#include "Question.h"
#include "Fraction.h"

Question::Question() {
  amount = 0;
  number_type = ALL_INTEGER;
  if_pow_operator = false;
}

//
//设置问题种类，整数/分数/整数分数混合，和有无乘方运算符
//
int Question::SetType(enum NumberType number_type, bool if_pow_operator) {
  this->number_type = number_type;
  this->if_pow_operator = if_pow_operator;
  return 0;
}

//
//生成amount数量的题目，并保存在字符串question_str
//
int Question::GenerateAndSave(int amount) {
  Question::QuestionGenerator generator;
  //调用QuestionGenerator类的Generate()
  for (int i = 0; i < amount; i++) {
    generator.GenerateOne(*this);
  }
  return 0;
}

//
//计算index处的题目结果（index取值0 ~ amount-1)
//
Fraction Question::Calculate(int index) {
  Question::QuestionCalculator calculator;
  return calculator.Calculate(index, *this);
  
}

//
//得到index处题目的string字符串（index取值0 ~ amount-1)
//
string Question::GetQuestion(int index) {
  return question_str[index];
}