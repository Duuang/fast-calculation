#include "Question.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
  Question question;
  question.SetType(Question::NumberType::ALL_INTEGER, Question::IfPowOperator::OPERATOR_2);
  /*question.question_str[0];
  question.question_str[1];
  question.amount = 0;
  Question::QuestionGenerator tmp;
  int a = tmp.IfSame(question, "2 + 1 + 1");
  question.question_str[0] = "2 + 1 + 1";
  question.amount++;
   a = tmp.IfSame(question, "2 + (1 + 1)");*/
   //question.question_str[0] = "((20 + 12) / 15) * 23";
//   ((20 + 12) / 15) * 23
//15
//15 - 4 / 12
//44/3
//7 - 5 / 11
//72/11
//   

   question.GenerateAndSave(100);

  for (int i = 0; i < 100; i++) {
  //cout << question. << endl;
    cout << question.GetQuestion(i) << endl;
    cout << question.Calculate(i).ToString() << endl;
  }
  system("pause");
}