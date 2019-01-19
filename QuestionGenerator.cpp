#include "Question.h"
#include "Fraction.h"
#include <random>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//
//生成一道题目，存进Question类
//
int Question::QuestionGenerator::Generate(Question &question) {
  int a = Random(1, 100);
  int b = Random(1, 100);
  int operator_number = Random(1, 4);
  string generated_question = "";
  char tmpchar[105];
  sprintf_s(tmpchar, "%d", a);
  generated_question += tmpchar;
  generated_question += " ";
  char operators[5] = {'\0', '+', '-', '*', '/'};
  generated_question.push_back(operators[operator_number]);
  generated_question += " ";
  sprintf_s(tmpchar, "%d", b);
  generated_question += tmpchar;
  (question.question_str + question.amount)->append(generated_question);
  question.amount++;
  return 1;

}

//
//生成一个 [x, y] 的随机整数
//
int Question::QuestionGenerator::Random(int x, int y) {
  std::random_device rd;
  std::minstd_rand rng{ rd() };
  std::uniform_int_distribution<long> dist{ x, y };
  return dist(rng);
}