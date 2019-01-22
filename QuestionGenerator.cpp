#include "Question.h"
#include "Fraction.h"
#include <random>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

char Question::QuestionGenerator::operate_char()
{
	 char symbol[1];
	 int j;
	 j=rand()%4;
	 if(j==0) symbol[0]='+';
    else if(j==1) symbol[0]='-';
    else if(j==2) symbol[0]='*';
    else symbol[0]='/';
    return symbol[0];
 } 
 int Question::QuestionGenerator::Generate()
 {
 	string question;
 	string operate_num1;
 	string operate_num2;
 	char symbol;
 	
	int operate_number=rand()%9+2;
 	int num1=rand()%99+1;
    int num2=rand()%99+1;
    symbol=operate_char();
    char zhuanhuan[100];
    itoa(num1,zhuanhuan,10);
    operate_num1=zhuanhuan;
    itoa(num2,zhuanhuan,10);
    operate_num2=zhuanhuan;
    question=operate_num1+' '+symbol+' '+operate_num2;
    if(operate_number>2)
    {
    	for(;operate_number>2;operate_number--)
    	{
    		symbol=operate_char();
    		num2=rand()%99+1;
    		itoa(num2,zhuanhuan,10);
    		operate_num2=zhuanhuan;
    		operate_num1=question;
    		int bracket=rand()%3;
    		if(bracket==2)
    		operate_num1='('+operate_num1+')';
    		question=operate_num1+' '+symbol+' '+operate_num2;
    		
		}
	}
    (question.question_str + question.amount)->append(question);
  question.amount++;
  return 1;
	 

    
 }
