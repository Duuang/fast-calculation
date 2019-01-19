#pragma once
#include "Fraction.h"
#include <string>

//
//包含嵌套类QuestionGenerator和QuestionCalculator
//用来设置参数、生成指定数量题目、计算某题的结果
//
class Question {
private:
  class QuestionGenerator; //这俩类是Question类的嵌套类，复合聚合关系,能直接访问Question类的私有部分
  class QuestionCalculator;
  enum NumberType {  //表示整数/分数/整数分数混合
    ALL_INTEGER = 1,
    ALL_FRACTION,
    INTEGER_AND_FRACTION
  };

public:
  //初始化成员变量
  Question();
  //设置生成的问题类型，整数/分数，带不带乘方
  int SetType(enum NumberType number_type, bool if_pow_calculator);
  //生成指定数量的不同的题，保存到文件
  int GenerateAndSave(int amount);  
  //计算表达式值
  Fraction Calculate(int index);

private:
  //正常表达式，带括号，数和运算符间有空格
  std::string question_str[1005];
  //后缀表达式，数和运算符间有空格
  std::string postfix_expression[1005];
  //已有题目的数量
  int amount;
  //结果，用分数表示
  Fraction results[1005];
  //整数/分数/整数分数混合
  enum NumberType number_type;
  //带不带乘方
  bool if_pow_operator;
};

//
//用来生成一个不重复的题目
//
class Question::QuestionGenerator {
public:
  //生成一个，存在Question类里，需要访问Question类的私有部分
  int Generate(Question &question);  
private:
  int Random(int x, int y);
  //随机生成一个（）
  //判断和之前的所有是否重复（）
};

//
//根据index，计算该题目的值，以分数方式返回
//
class Question::QuestionCalculator {
public:
  //根据index计算值
  Fraction Calculate(int index, Question &question);
private:
  //生成后缀表达式（）
  //计算（）
};

