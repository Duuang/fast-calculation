#include "Question.h"
#include "stack"
#include "iostream"
#include "fstream"
#include "cstdlib"
#include "Fraction.h"
using namespace std;

int Question::QuestionCalculator::lev(char c)
{
	if (c == '(' || c == ')')
	{
		return 0;
	}
	if (c == '+'|| c == '-')
	{
		return 1;
	}
	if (c == '*'|| c == '/')
	{
		return 2;
	}
	if (c == '^') return 3;
	return -1;
}

Fraction Question::QuestionCalculator::cal(Fraction a, Fraction b, char x)
{
	if (x == '+')
		return a.Add(b);
	if (x == '-')
		return a.Subtract(b);
	if (x == '*')
		return a.Multiply(b);
	if (x == '/')
		return a.DividedBy(b);
	if (x == '^')
	{
		int exp = b.GetNumerator();
		return a.Power(exp);
	}
	Fraction error(1000, 1000);
	return error;
}

string Question::QuestionCalculator::PostfixExpressionGenerate(string ques)
{
	int i = 0;
	string pos_ques;
	stack<char> symstack;
	while (ques[i] != '\0')
	{
		if (ques[i] == ' ');
		if (ques[i] >= '0' && ques[i] <= '9')
		{
			while (ques[i] >= '0' && ques[i] <= '9')
			{
				pos_ques = pos_ques + ques[i];
				i++;
			}
			if (ques[i] == ' ' || ques[i] == '\0')
			{
				pos_ques = pos_ques + ' ';
				if (ques[i] == '\0')
					break;
			}
			if(ques[i] == '/')
			{
				pos_ques = pos_ques + ques[i];
			}
		}
		if(ques[i] == '(' || ques[i] == ')' || ques[i] == '+' || ques[i] == '-' || ques[i] == '*' || (ques[i] == '/' && (ques[i + 1] < '0' || ques[i + 1] > '9')) ) 
		{
			if (symstack.empty())
				symstack.push(ques[i]);
			else {
				if (ques[i] == '(')
				{
					symstack.push(ques[i]);
				}
				else {
					if (ques[i] == ')')
					{
						while (symstack.top() != '(')
						{
							pos_ques = pos_ques + symstack.top() + ' ';
							symstack.pop();
						}
						symstack.pop();
					}
					else {
						int l1, l2;
						l1 = lev(ques[i]);
						l2 = lev(symstack.top());
						while (l1 <= l2)
						{
							pos_ques = pos_ques + symstack.top() + ' ';
							symstack.pop();
							if (symstack.empty()) break;
							else l2 = symstack.top();
						}
						symstack.push(ques[i]);
					}
				}	
			}
		}
		i++;
	}
	while (!symstack.empty())
	{
		pos_ques = pos_ques + symstack.top() + ' ';
		symstack.pop();
	}
	return pos_ques;
}

Fraction Question::QuestionCalculator::Calculate(int index, Question &question) {
  //。。。。具体实现内容
	string ques = question.question_str[index];
	string pos_ques;

	//中缀转后缀
	pos_ques = PostfixExpressionGenerate(ques);
	int i = 0;

	//根据后缀表达式求解
	stack<Fraction> opestack; //定义操作数栈，<>里内容待定
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
			}
			else {
				Fraction f(numerator, 1);
				fra = f;
			}
			opestack.push(fra);
		}
		else {
			Fraction o1, o2;
			o2 = opestack.top();
			opestack.pop();
			o1 = opestack.top();
			opestack.pop();
			Fraction o3;
			o3 = cal(o1, o2, pos_ques[i]);
			opestack.push(o3);
			i++;
		}
	}
	Fraction value = opestack.top();
	opestack.pop();
	
	//化简结果
	Fraction sim_value(value.Simplify());

	//写入文件
	fstream fileout;
	fileout.open("c:\\users\\10346\\Desktop\\TheResult");
/*	if (sim_value.IsInteger() == true)
	{
		fileout << "题目" << index << "的答案是" << sim_value.GetNumerator() << endl;
	}
	else
	{
		fileout << "题目" << index << "的答案是" << sim_value.GetNumerator() << "/" << sim_value.GetDenominator() << endl;
	}*/ 
	return sim_value;
}
