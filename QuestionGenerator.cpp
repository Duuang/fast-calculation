#include "Question.h"
#include "Fraction.h"
#include <random>
#include <iostream>
#include <string>
#include <stdlib.h>

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

	j = Random(0,num-1);
	if (j/2 == 0)
		symbol = '+';
	else if (j/2 == 1)
		symbol = '-';
	else if (j/2 == 2)
		symbol = '*';
	else if (j/2 == 3)
		symbol = '/';
	else if (n == OPERATOR_1)
		symbol = '^';
	else
		symbol = "**";
	return symbol;
}
 int Question::QuestionGenerator::GenerateOne(Question &question)
 {
	 if(question.number_type == ALL_INTEGER)		//纯整数

	 {
		 string questions;
		 string operate_num1;
		 string operate_num2;
		 string symbol;

		 int operate_number = Random(2,5);
		 int num1 = Random(1,20);
		 int num2 = Random(1,20);
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
				 num2 = Random(1,30);
				 _itoa_s(num2, zhuanhuan, 10);
				 operate_num2 = zhuanhuan;
				 operate_num1 = questions;
				 int bracket = Random(0,2);
				 if (bracket == 2)
					 operate_num1 = '(' + operate_num1 + ')';
				 questions = operate_num1 + ' ' + symbol + ' ' + operate_num2;

			 }
		 }
		 (question.question_str + question.amount)->append(questions);
		 question.amount++;
		 return 1;

	 }
	 else if (question.number_type == ALL_FRACTION)			//纯小数
	 {
		 string questions;
		 int numerator;
		 int denominator;
		 int operate_number = Random(2,5);

		 Fraction fraction1;
		 numerator = Random(1, 10);
		 denominator = Random(1,10);
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
		 denominator = Random(1,10);
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
				 denominator = Random(1,10);
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
		 (question.question_str + question.amount)->append(questions);
		 question.amount++;
		 return 1;
	 }
	 else									//混合
	{
		string questions;
		string operate1;
		string operate2;
		string symbol;
		int operate_number = Random(2, 5);

		int flag;
		flag = Random(0,1);
		if (flag == 0)
		{
			int num;
			num = Random(1, 20);
			char zhuanhuan[100];
			_itoa_s(num, zhuanhuan, 10);
			operate1 = zhuanhuan;

		 }
		else
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

		}
		else
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
				flag = Random(0,1);
				if (flag == 0)
				{
					int num;
					num = Random(1, 20);
					char zhuanhuan[100];
					_itoa_s(num, zhuanhuan, 10);
					operate2 = zhuanhuan;

				}
				else
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
		(question.question_str + question.amount)->append(questions);
		question.amount++;
		return 1;

	 }//else 



    
 }

