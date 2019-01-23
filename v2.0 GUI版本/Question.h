#pragma once
#include "Fraction.h"
#include <string>
using namespace std;
#define private public

//
//包含嵌套类QuestionGenerator和QuestionCalculator
//用来设置参数、生成指定数量题目、计算某题的结果、得到某道题目的字符串
//
class Question {
private:
  //Question类的嵌套类，复合聚合关系，包含了生成过程具体实现
  class QuestionGenerator;
  //Question类的嵌套类，复合聚合关系，包含了计算题目过程具体实现
  class QuestionCalculator;
public:
  //表示题目类型，整数/分数/整数分数混合
  enum NumberType {
    ALL_INTEGER = 1,
    ALL_FRACTION,
    INTEGER_AND_FRACTION
  };
  //有无乘方、乘方用什么表示
  enum IfPowOperator {
    NONE,
    OPERATOR_1,  //用^表示
    OPERATOR_2   //用**表示
  };

public:
  //初始化成员变量
  Question();
  //设置生成的问题类型，整数/分数，带不带乘方
  int SetType(enum NumberType number_type, enum IfPowOperator if_pow_operator);
  //生成指定数量的不同的题，并保存到文件
  int GenerateAndSave(int amount);
  //计算表达式值
  Fraction Calculate(int index);
  //返回某题的字符串值
  string GetQuestion(int index);

private:
  //中缀表达式，带括号，数和运算符间有空格
  std::string question_str[1005];
  //后缀表达式，数和运算符间有空格
  std::string postfix_expression[1005];
  //保存中间结果，即为每个问题后缀表达式计算过程中出栈的数，若干对的数和最后栈顶的数
  Fraction intermediate_result[1005][55];
  //intermediate_result中结果的个数
  int intermediate_result_amount[1005];
  //已有题目的数量
  int amount;
  //结果，用分数表示
  Fraction results[1005];
  //整数/分数/整数分数混合
  enum NumberType number_type;
  //带不带乘方
  enum IfPowOperator if_pow_operator;
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
	string PostfixExpressionGenerate(string ques);
  //计算（）
	Fraction cal(Fraction a, Fraction b, char x);
  //优先级判断
	int lev(char c);
};

//
//用来生成一个不重复的题目
//
class Question::QuestionGenerator {
public:
  //生成一个，存在Question类里，需要访问Question类的私有部分
  int GenerateOne(Question &question);
private:
  //生成后缀表达式，Calculator类的友元函数
  friend string Question::QuestionCalculator::PostfixExpressionGenerate(string ques);
  friend Fraction Question::QuestionCalculator::cal(Fraction a, Fraction b, char x);
  //判断是否和之前某题一样
  bool IfSame(Question &question, string question_str);
  //判断某题是否过难（出现负数、分子或分母运算过程中>200）
  bool IfTooHard(Question &question);
  
  //生成一个运算符
  string operate_char(enum IfPowOperator n);
  //生成随机数
  int Random(int x, int y);
};