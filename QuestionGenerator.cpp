#include "Question.h"
#include "Fraction.h"
#include <random>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

char Question::QuestionGenerator::operate_char()
{
	 char symbol[1];
	 int j,num=4;
	 
	 j=rand()%num;
	 if(j==0) symbol[0]='+';
    else if(j==1) symbol[0]='-';
    else if(j==2) symbol[0]='*';
    else symbol[0]='/';
	    return symbol[0];
 } 
 int Question::QuestionGenerator::GenerateOne(Question &question)
 {
	 if(question.number_type == ALL_INTEGER)		//纯整数

	 {
		 string question;
		 string operate_num1;
		 string operate_num2;
		 char symbol;

		 int operate_number = rand() % 3 + 2;
		 int num1 = rand() % 99 + 1;
		 int num2 = rand() % 99 + 1;
		 symbol = operate_char();

		 char zhuanhuan[100];
		 itoa(num1, zhuanhuan, 10);
		 operate_num1 = zhuanhuan;
		 itoa(num2, zhuanhuan, 10);
		 operate_num2 = zhuanhuan;
		 question = operate_num1 + ' ' + symbol + ' ' + operate_num2;

		 if (operate_number > 2)
		 {
			 for (; operate_number > 2; operate_number--)
			 {
				 symbol = operate_char();
				 num2 = rand() % 99 + 1;
				 itoa(num2, zhuanhuan, 10);
				 operate_num2 = zhuanhuan;
				 operate_num1 = question;
				 int bracket = rand() % 3;
				 if (bracket == 2)
					 operate_num1 = '(' + operate_num1 + ')';
				 question = operate_num1 + ' ' + symbol + ' ' + operate_num2;

			 }
		 }
		 (question.question_str + question.amount)->append(question);
		 question.amount++;
		 return 1;

	 }
	 else if (question.number_type == ALL_FRACTION)			//纯小数
	 {
		 string question;
		 int numerator;
		 int denominator;
		 int operate_number = rand() % 9 + 2;

		 Fraction fraction1;
		 numerator = rand() % 99 + 1;
		 denominator = rand() % 99 + 1;
		 if (numerator > denominator)
		 {
			 int buffer = numerator;
			 numerator = denominator;
			 denominator = buffer;
		 }
		 fraction1.Set(numerator, denominator);

		 Fraction fraction2;
		 numerator = rand() % 99 + 1;
		 denominator = rand() % 99 + 1;
		 if (numerator > denominator)
		 {
			 int buffer = numerator;
			 numerator = denominator;
			 denominator = buffer;
		 }
		 fraction2.Set(numerator, denominator);

		 char symbol = operate_char();
		 string operate_fraction1 = fraction1.ToString();
		 string operate_fraction2 = fraction2.ToString();
		 question = operate_fraction1 + ' ' + symbol + ' ' + operate_fraction2;
		 if (operate_number > 2)
		 {
			 for (; operate_number > 2; operate_number--)
			 {
				 symbol = operate_char();
				 numerator = rand() % 99 + 1;
				 denominator = rand() % 99 + 1;
				 if (numerator > denominator)
				 {
					 int buffer = numerator;
					 numerator = denominator;
					 denominator = buffer;
				 }
				 fraction2.Set(numerator, denominator);
				 operate_fraction2 = fraction2.ToString();
				 operate_fraction1 = question;
				 int bracket = rand() % 3;
				 if (bracket == 2)
					 operate_fraction1 = '(' + operate_fraction1 + ')';
				 question = operate_fraction1 + ' ' + symbol + ' ' + operate_fraction2;

			 }
		 }
		 (question.question_str + question.amount)->append(question);
		 question.amount++;
		 return 1;
	 }
	 else									//混合
	{
		string question;
		string operate1;
		string operate2;
		char symbol;
		int operate_number = rand() % 3 + 2;

		int flag;
		flag = rand() % 2;
		if (flag == 0)
		{
			int num;
			num = rand() % 99 + 1;
			char zhuanhuan[100];
			itoa(num1, zhuanhuan, 10);
			operate1 = zhuanhuan;

		 }
		else
		{
			Fraction fraction;
			int numerator = rand() % 99 + 1;
			int denominator = rand() % 99 + 1;
			if (numerator > denominator)
			{
				int buffer = numerator;
				numerator = denominator;
				denominator = buffer;
			}
			fraction.Set(numerator, denominator);
			operate1 = fraction.ToString();
		}


		flag = rand() % 2;
		if (flag == 0)
		{
			int num;
			num = rand() % 99 + 1;
			char zhuanhuan[100];
			itoa(num1, zhuanhuan, 10);
			operate2 = zhuanhuan;

		}
		else
		{
			Fraction fraction;
			int numerator = rand() % 99 + 1;
			int denominator = rand() % 99 + 1;
			if (numerator > denominator)
			{
				int buffer = numerator;
				numerator = denominator;
				denominator = buffer;
			}
			fraction.Set(numerator, denominator);
			operate2 = fraction.ToString();
		}

		symbol = operate_char();
		question = operate1 + ' ' + symbol + ' ' + operate2;

		if (operate_number > 2)
		{
			for (; operate_number > 2; operate_number--)
			{
				symbol = operate_char();
				flag = rand() % 2;
				if (flag == 0)
				{
					int num;
					num = rand() % 99 + 1;
					char zhuanhuan[100];
					itoa(num1, zhuanhuan, 10);
					operate2 = zhuanhuan;

				}
				else
				{
					Fraction fraction;
					int numerator = rand() % 99 + 1;
					int denominator = rand() % 99 + 1;
					if (numerator > denominator)
					{
						int buffer = numerator;
						numerator = denominator;
						denominator = buffer;
					}
					fraction.Set(numerator, denominator);
					operate2 = fraction.ToString();
				}
				operate1 = question;
				int bracket = rand() % 3;
				if (bracket == 2)
					operate1 = '(' + operate_num1 + ')';
				question = operate1 + ' ' + symbol + ' ' + operate2;

			}
		}
		(question.question_str + question.amount)->append(question);
		question.amount++;
		return 1;

	 }//else 



    
 }

