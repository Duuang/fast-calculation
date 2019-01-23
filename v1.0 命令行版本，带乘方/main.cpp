#include "Question.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main(int argc, char *argv[]) {
  Question question;
  //无命令行参数的情况，分步提示用户输入参数
  if (argc == 1) {
    int count = 0;
    cout << "请输入生成的题目数字种类，0为纯整数，1为纯分数，2为整数分数混合\n";
    int number_type = -1;
    cin >> number_type;
    while (number_type < 0 || number_type > 2) {
      cout << "错误数值\n";
      cin >> number_type;
    }
    cout << "请输入生成的题目的乘方种类，0为不带乘方，1为用^表示乘方，2为用**表示乘方\n";
    int if_pow = -1;
    cin >> if_pow;
    while (if_pow < 0 || if_pow > 2) {
      cout << "错误数值\n";
      cin >> if_pow;
    }
    cout << "请输入生成的题目的数量，1~1000\n";
    int amount = -1;
    cin >> amount;
    while (amount < 1 || amount > 1000) {
      cout << "错误数值\n";
      cin >> amount;
    }
    question.SetType((enum Question::NumberType) (number_type + 1), (enum Question::IfPowOperator) if_pow);
    question.GenerateAndSave(amount);
    for (int i = 0; i < amount; i++) {
      cout << "题目" << i + 1 << "为： " << question.GetQuestion(i) << "    请输入答案：" << endl;
      string answer;
      cin >> answer;
      if (answer == question.Calculate(i).ToString()) {
        cout << "正确\n";
        count++;
      } else {
        cout << "错误，答案应为" << question.Calculate(i).ToString() << endl;
      }
    }
    cout << "正确题数：" << count << "\n错误题数：" << amount - count << endl;
  //有命令行参数的情况，如果输入参数错误，提示样例输入
  } else if (argc == 6) {
    int count = 0;
    if (strcmp(argv[1], "-generate") == 0 && strcmp(argv[3], "-settings") == 0
      && atoi(argv[2]) >= 1 && atoi(argv[2]) <= 1000 && atoi(argv[4]) >= 0 && atoi(argv[4]) <= 2
      && atoi(argv[5]) >= 0 && atoi(argv[5]) <= 2) {
      question.SetType((enum Question::NumberType) (atoi(argv[4]) + 1), (enum Question::IfPowOperator) atoi(argv[5]));
      question.GenerateAndSave(atoi(argv[2]));
      for (int i = 0; i < atoi(argv[2]); i++) {
        cout << "题目" << i + 1 << "为： " << question.GetQuestion(i) << "    请输入答案：" <<endl;
        string answer;
        cin >> answer;
        if (answer == question.Calculate(i).ToString()) {
          cout << "正确\n";
          count++;
        } else {
          cout << "错误，答案应为" << question.Calculate(i).ToString() << endl;
        }
      }
      cout << "正确题数：" << count << "\n错误题数：" << atoi(argv[2]) - count << endl;
    } else {
      printf("请输入正确的参数！\n命令行参数为：无参数，或者-generate 1~1000 -settings 0/1/2 0/1/2\n\
如：-generate 100 -settings 0 0\n其中第一个1~1000的数为生成题目数量，第2个0/1/2的参数代表题目为纯整数/纯分数/整数分数混合，\
第3个0/1/2的参数代表题目为无乘方/用^表示的乘方/用**表示的乘方\n");
    }
  } else {
    printf("请输入正确的参数！\n命令行参数为：无参数，或者-generate 1~1000 -settings 0/1/2 0/1/2\n\
如：-generate 100 -settings 0 0\n其中第一个1~1000的数为生成题目数量，第2个0/1/2的参数代表题目为纯整数/纯分数/整数分数混合，\
第3个0/1/2的参数代表题目为无乘方/用^表示的乘方/用**表示的乘方\n");
  }
  system("pause");
}