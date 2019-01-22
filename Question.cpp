#include "Question.h"
#include "Fraction.h"

Question::Question() {
  amount = 0;
  number_type = ALL_INTEGER;
  if_pow_operator = NONE;
}

//
//设置问题种类，整数/分数/整数分数混合，和有无乘方运算符
//
int Question::SetType(enum NumberType number_type, enum IfPowOperator if_pow_operator) {
  this->number_type = number_type;
  this->if_pow_operator = if_pow_operator;
  return 0;
}

//
//生成amount数量的题目，并保存在字符串question_str，并保存到文件
//
int Question::GenerateAndSave(int amount) {
  //生成amount道题
  Question::QuestionGenerator generator;
  //调用QuestionGenerator类的Generate()
  for (int i = 0; i < amount; i++) {
    generator.GenerateOne(*this);
  }
  //保存到文件
  FILE *fp;
  errno_t err;
  err = fopen_s(&fp, "generated_questions.txt", "w+");
  if (fp == NULL) {
    printf("打开文件失败\n");
    return -1;
  }
  for (int i = 0; i < amount; i++) {
    fputs(question_str[i].data(), fp);
  }
  fclose(fp);
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