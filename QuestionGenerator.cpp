#include "Question.h"
#include "Fraction.h"
#include <random>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>

using namespace std;
int Question::QuestionGenerator::Random(int x, int y) {
  std::random_device rd;
  std::minstd_rand rng{ rd() };
  std::uniform_int_distribution<long> dist{ x, y };
  return dist(rng);
}

string  Question::QuestionGenerator::operate_char(enum IfPowOperator n)
{
  string symbol;
  int j, num;
  if (n == NONE)
    num = 4;
  else
    num = 9;

  j = Random(0, num - 1);
  if (j / 2 == 0)
    symbol = '+';
  else if (j / 2 == 1)
    symbol = '-';
  else if (j / 2 == 2)
    symbol = '*';
  else if (j / 2 == 3)
    symbol = '/';
  else if (n == OPERATOR_1)
    symbol = '^';
  else
    symbol = "**";
  return symbol;
}
int Question::QuestionGenerator::GenerateOne(Question &question)
{
  if (question.number_type == ALL_INTEGER)		//纯整数

  {
    string questions;
    string operate_num1;
    string operate_num2;
    string symbol;

    int operate_number = Random(2, 5);
    int num1 = Random(1, 20);
    int num2 = Random(1, 20);
    symbol = operate_char(question.if_pow_operator);

    char zhuanhuan[100];
    _itoa_s(num1, zhuanhuan, 10);
    operate_num1 = zhuanhuan;
    _itoa_s(num2, zhuanhuan, 10);
    operate_num2 = zhuanhuan;
    questions = operate_num1 + ' ' + symbol + ' ' + operate_num2;

    if (operate_number > 2)
    {
      for (; operate_number > 2; operate_number--)
      {
        symbol = operate_char(question.if_pow_operator);
        num2 = Random(1, 30);
        _itoa_s(num2, zhuanhuan, 10);
        operate_num2 = zhuanhuan;
        operate_num1 = questions;
        int bracket = Random(0, 2);
        if (bracket == 2)
          operate_num1 = '(' + operate_num1 + ')';
        questions = operate_num1 + ' ' + symbol + ' ' + operate_num2;

      }
    }

    //----------------更改部分-----------------------------------------------------------
    //判断是否重复,且判断运算过程是否有太大的数出现
    if (IfSame(question, questions) || IfTooHard(question)) {
      return -1;
    }
    //---------------------------------------------------------------------------
    (question.question_str + question.amount)->append(questions);

    question.amount++;
    return 1;

  } else if (question.number_type == ALL_FRACTION)			//纯小数
  {
    string questions;
    int numerator;
    int denominator;
    int operate_number = Random(2, 5);

    Fraction fraction1;
    numerator = Random(1, 10);
    denominator = Random(1, 10);
    while (1) {
			 if (numerator == denominator)
				 denominator = Random(1, 10);
			 else
				 break;
		 }
    if (numerator > denominator)
    {
      int buffer = numerator;
      numerator = denominator;
      denominator = buffer;
    }
    fraction1.Set(numerator, denominator);

    Fraction fraction2;
    numerator = Random(1, 10);
    denominator = Random(1, 10);
    while (1) {
			 if (numerator == denominator)
				 denominator = Random(1, 10);
			 else
				 break;
		 }
    if (numerator > denominator)
    {
      int buffer = numerator;
      numerator = denominator;
      denominator = buffer;
    }
    fraction2.Set(numerator, denominator);

    string symbol = operate_char(question.if_pow_operator);
    string operate_fraction1 = fraction1.ToString();
    string operate_fraction2 = fraction2.ToString();
    questions = operate_fraction1 + ' ' + symbol + ' ' + operate_fraction2;
    if (operate_number > 2)
    {
      for (; operate_number > 2; operate_number--)
      {
        symbol = operate_char(question.if_pow_operator);
        numerator = Random(1, 10);
        denominator = Random(1, 10);
        while (1) {
			 		if (numerator == denominator)
				 		denominator = Random(1, 10);
			 		else
				 		break;
		 			}
        if (numerator > denominator)
        {
          int buffer = numerator;
          numerator = denominator;
          denominator = buffer;
        }
        fraction2.Set(numerator, denominator);
        operate_fraction2 = fraction2.ToString();
        operate_fraction1 = questions;
        int bracket = Random(0, 2);
        if (bracket == 2)
          operate_fraction1 = '(' + operate_fraction1 + ')';
        questions = operate_fraction1 + ' ' + symbol + ' ' + operate_fraction2;

      }
    }
    //----------------更改部分-----------------------------------------------------------
    //判断是否重复,且判断运算过程是否有太大的数出现
    if (IfSame(question, questions) || IfTooHard(question)) {
      return -1;
    }
    //---------------------------------------------------------------------------
    
    (question.question_str + question.amount)->append(questions);
    question.amount++;
    return 1;
  } else									//混合
  {
    string questions;
    string operate1;
    string operate2;
    string symbol;
    int operate_number = Random(2, 5);

    int flag;
    flag = Random(0, 1);
    if (flag == 0)
    {
      int num;
      num = Random(1, 20);
      char zhuanhuan[100];
      _itoa_s(num, zhuanhuan, 10);
      operate1 = zhuanhuan;

    } else
    {
      Fraction fraction;
      int numerator = Random(1, 10);
      int denominator = Random(1, 10);
      if (numerator > denominator)
      {
        int buffer = numerator;
        numerator = denominator;
        denominator = buffer;
      }
      fraction.Set(numerator, denominator);
      operate1 = fraction.ToString();
    }


    flag = Random(0, 1);
    if (flag == 0)
    {
      int num;
      num = Random(1, 20);
      char zhuanhuan[100];
      _itoa_s(num, zhuanhuan, 10);
      operate2 = zhuanhuan;

    } else
    {
      Fraction fraction;
      int numerator = Random(1, 10);
      int denominator = Random(1, 10);
      if (numerator > denominator)
      {
        int buffer = numerator;
        numerator = denominator;
        denominator = buffer;
      }
      fraction.Set(numerator, denominator);
      operate2 = fraction.ToString();
    }

    symbol = operate_char(question.if_pow_operator);
    questions = operate1 + ' ' + symbol + ' ' + operate2;

    if (operate_number > 2)
    {
      for (; operate_number > 2; operate_number--)
      {
        symbol = operate_char(question.if_pow_operator);
        flag = Random(0, 1);
        if (flag == 0)
        {
          int num;
          num = Random(1, 20);
          char zhuanhuan[100];
          _itoa_s(num, zhuanhuan, 10);
          operate2 = zhuanhuan;

        } else
        {
          Fraction fraction;
          int numerator = Random(1, 10);
          int denominator = Random(1, 10);
          if (numerator > denominator)
          {
            int buffer = numerator;
            numerator = denominator;
            denominator = buffer;
          }
          fraction.Set(numerator, denominator);
          operate2 = fraction.ToString();
        }
        operate1 = questions;
        int bracket = Random(0, 2);
        if (bracket == 2)
          operate1 = '(' + operate1 + ')';
        questions = operate1 + ' ' + symbol + ' ' + operate2;

      }
    }
    //----------------更改部分-----------------------------------------------------------
    //判断是否重复,且判断运算过程是否有太大的数出现
    if (IfSame(question, questions) || IfTooHard(question)) {
      return -1;
    }
    //---------------------------------------------------------------------------
    (question.question_str + question.amount)->append(questions);
    question.amount++;
    return 1;

  }//else     
}


//
////判断是否和之前某题一样
//
bool Question::QuestionGenerator::IfSame(Question &question, string question_str) {
  
  Question::QuestionCalculator tmp;
  //调用友元函数，生成后缀表达式，并保存
  question.postfix_expression[question.amount] = tmp.PostfixExpressionGenerate(question_str);
  string pos_ques = question.postfix_expression[question.amount];
  stack<Fraction> opestack; //定义操作数栈

  //将计算后缀表达式的中间过程得到的数保存
  int i = 0;
  question.intermediate_result_amount[question.amount] = 0;
  while (pos_ques[i] != '\0')
  {
    if (pos_ques[i] == ' ')
    {
      i++;
      continue;
    }
    if (pos_ques[i] >= '0' && pos_ques[i] <= '9')
    {
      Fraction fra;
      int numerator, denominator;
      numerator = atoi(&pos_ques[i]);
      while (pos_ques[i] >= '0' && pos_ques[i] <= '9') i++;
      if (pos_ques[i] == '/')
      {
        i += 1;
        denominator = atoi(&pos_ques[i]);
        while (pos_ques[i] >= '0' && pos_ques[i] <= '9') i++;
        Fraction f(numerator, denominator);
        fra = f;
      } else {
        Fraction f(numerator, 1);
        fra = f;
      }
      opestack.push(fra);
    } else {
      Fraction o1, o2;
      o2 = opestack.top();
      question.intermediate_result[question.amount][question.intermediate_result_amount[question.amount]++] = o2;
      opestack.pop();
      o1 = opestack.top();
      question.intermediate_result[question.amount][question.intermediate_result_amount[question.amount]++] = o1;
      opestack.pop();
      Fraction o3 = tmp.cal(o1, o2, pos_ques[i]);
      opestack.push(o3);
      i++;
    }
  }
  Fraction value = opestack.top();
  opestack.pop();
  question.results[question.amount] = value;
  question.intermediate_result[question.amount][question.intermediate_result_amount[question.amount]++] = value;
  
  //对之前的每个问题，看中间结果是否符合此问题的中间结果
  bool iffirsttime = true; //如果是最后栈顶的那个数
  for (int i = 0; i < question.amount; i++) {
    //首先中间结果的个数要相等
    if (question.intermediate_result_amount[i] != question.intermediate_result_amount[question.amount]) {
      return false;
    }
    //判断中间结果是否符合此问题的中间结果
    for (int j = question.intermediate_result_amount[i] - 1; j >= 0; j--) {
      //如果是最后栈顶的一个数
      if (iffirsttime) {
        iffirsttime = false;
        if (question.intermediate_result[i][j].Subtract(question.intermediate_result[question.amount][j]).GetNumerator() != 0) {
          return false;
        }
      //如果是出栈的一对数
      } else {
        if (!((question.intermediate_result[i][j].Subtract(question.intermediate_result[question.amount][j]).GetNumerator() == 0 && question.intermediate_result[i][j - 1].Subtract(question.intermediate_result[question.amount][j - 1]).GetNumerator() == 0) ||
          (question.intermediate_result[i][j - 1].Subtract(question.intermediate_result[question.amount][j]).GetNumerator() == 0 && question.intermediate_result[i][j].Subtract(question.intermediate_result[question.amount][j - 1]).GetNumerator() == 0))) {
          return false;
        }
        //因为考虑了两个成对的数，所以再-1
        j--;
      }
    }
  }
  //如果第一个问题，则不重复
  if (question.amount == 0)
    return false;
  //如果上面循环均未return，则重复
  return true;
}

//
//判断某题是否过难（出现负数、分子或分母运算过程中>200）
//
bool Question::QuestionGenerator::IfTooHard(Question &question) {
  
  for (int i = 0; i < question.intermediate_result_amount[question.amount]; i++) {
    if (question.intermediate_result[question.amount][i].GetNumerator() == -1
      || question.intermediate_result[question.amount][i].GetNumerator() > 200
      || question.intermediate_result[question.amount][i].GetDenominator() > 200) {
      return true;
    }
    
  }
  return false;
}