#include "Question.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main(int argc, char *argv[]) {
  Question question;
  //�������в�����������ֲ���ʾ�û��������
  if (argc == 1) {
    int count = 0;
    cout << "���������ɵ���Ŀ�������࣬0Ϊ��������1Ϊ��������2Ϊ�����������\n";
    int number_type = -1;
    cin >> number_type;
    while (number_type < 0 || number_type > 2) {
      cout << "������ֵ\n";
      cin >> number_type;
    }
    cout << "���������ɵ���Ŀ�ĳ˷����࣬0Ϊ�����˷���1Ϊ��^��ʾ�˷���2Ϊ��**��ʾ�˷�\n";
    int if_pow = -1;
    cin >> if_pow;
    while (if_pow < 0 || if_pow > 2) {
      cout << "������ֵ\n";
      cin >> if_pow;
    }
    cout << "���������ɵ���Ŀ��������1~1000\n";
    int amount = -1;
    cin >> amount;
    while (amount < 1 || amount > 1000) {
      cout << "������ֵ\n";
      cin >> amount;
    }
    question.SetType((enum Question::NumberType) (number_type + 1), (enum Question::IfPowOperator) if_pow);
    question.GenerateAndSave(amount);
    for (int i = 0; i < amount; i++) {
      cout << "��Ŀ" << i + 1 << "Ϊ�� " << question.GetQuestion(i) << "    ������𰸣�" << endl;
      string answer;
      cin >> answer;
      if (answer == question.Calculate(i).ToString()) {
        cout << "��ȷ\n";
        count++;
      } else {
        cout << "���󣬴�ӦΪ" << question.Calculate(i).ToString() << endl;
      }
    }
    cout << "��ȷ������" << count << "\n����������" << amount - count << endl;
  //�������в��������������������������ʾ��������
  } else if (argc == 6) {
    int count = 0;
    if (strcmp(argv[1], "-generate") == 0 && strcmp(argv[3], "-settings") == 0
      && atoi(argv[2]) >= 1 && atoi(argv[2]) <= 1000 && atoi(argv[4]) >= 0 && atoi(argv[4]) <= 2
      && atoi(argv[5]) >= 0 && atoi(argv[5]) <= 2) {
      question.SetType((enum Question::NumberType) (atoi(argv[4]) + 1), (enum Question::IfPowOperator) atoi(argv[5]));
      question.GenerateAndSave(atoi(argv[2]));
      for (int i = 0; i < atoi(argv[2]); i++) {
        cout << "��Ŀ" << i + 1 << "Ϊ�� " << question.GetQuestion(i) << "    ������𰸣�" <<endl;
        string answer;
        cin >> answer;
        if (answer == question.Calculate(i).ToString()) {
          cout << "��ȷ\n";
          count++;
        } else {
          cout << "���󣬴�ӦΪ" << question.Calculate(i).ToString() << endl;
        }
      }
      cout << "��ȷ������" << count << "\n����������" << atoi(argv[2]) - count << endl;
    } else {
      printf("��������ȷ�Ĳ�����\n�����в���Ϊ���޲���������-generate 1~1000 -settings 0/1/2 0/1/2\n\
�磺-generate 100 -settings 0 0\n���е�һ��1~1000����Ϊ������Ŀ��������2��0/1/2�Ĳ���������ĿΪ������/������/����������ϣ�\
��3��0/1/2�Ĳ���������ĿΪ�޳˷�/��^��ʾ�ĳ˷�/��**��ʾ�ĳ˷�\n");
    }
  } else {
    printf("��������ȷ�Ĳ�����\n�����в���Ϊ���޲���������-generate 1~1000 -settings 0/1/2 0/1/2\n\
�磺-generate 100 -settings 0 0\n���е�һ��1~1000����Ϊ������Ŀ��������2��0/1/2�Ĳ���������ĿΪ������/������/����������ϣ�\
��3��0/1/2�Ĳ���������ĿΪ�޳˷�/��^��ʾ�ĳ˷�/��**��ʾ�ĳ˷�\n");
  }
  system("pause");
}