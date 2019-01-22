#include "Question.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
  Question question;
  question.GenerateAndSave(10);
  for (int i = 0; i < 10; i++) {
    cout << question.GetQuestion(i) << endl;
    cout << question.Calculate(i).ToString() << endl;
  }
}