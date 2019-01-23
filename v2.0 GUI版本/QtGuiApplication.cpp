#include "QtGuiApplication.h"
#include <QDialog>
#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>
#include <Windows.h>
#include <QThread>
#include <QCoreApplication>
#include <QTime>
#include <QMessageBox>

QtGuiApplication::QtGuiApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.comboBox->addItem(u8"��������");
    ui.comboBox->addItem(u8"��������");
    ui.comboBox->addItem(u8"���������������");
    ui.comboBox_2->addItem(u8"�޳˷�");
    ui.comboBox_2->addItem(u8"�г˷����� ^��ʾ");
    ui.comboBox_2->addItem(u8"�г˷�����**��ʾ");
    ui.next_question_button->setDisabled(true);
    ui.submit_button->setDisabled(true);
    connect(ui.history_button, SIGNAL(clicked()), this, SLOT(ShowHistory()));
    connect(ui.start_button, SIGNAL(clicked()), this, SLOT(StartExercises()));
    connect(ui.submit_button, SIGNAL(clicked()), this, SLOT(SubmitAnswer()));
    connect(ui.next_question_button, SIGNAL(clicked()), this, SLOT(NextQuestion()));
    connect(this, SIGNAL(NoTimeSignal()), this, SLOT(RunOutOfTime()));

    errno_t err;
    err = fopen_s(&fp_history, "history.txt", "a+");
    if (fp_history == NULL) {
      ui.history_button->setDisabled(true);
      printf("���ļ�ʧ��\n");
    }
    timer_thread_amount = 0;
    
}

QtGuiApplication::~QtGuiApplication() {
  if (current_index != question_amount) {
    fputs("����δ��ɣ�������;�˳�\n", fp_history);
  }
  if (fp_history != NULL)
    fclose(fp_history);
}

//
//��ʱ������������һ���¼�ʱ���̣߳������⵽����̣߳���ʱ��˳������
//
void QtGuiApplication::StartTimer(int seconds) {
  for (int i = seconds; i >= 1; i--) {
    if (timer_thread_amount > 1 && i != seconds) {
    //�������������1�룬���������߳���>1�������ٴ��̣߳������߳���-1
      timer_thread_amount--;
      return;
    }
    ui.countdown_lable->setText(QString::number(i));
    Sleep(1000);
  }
  ui.countdown_lable->setText(QString::number(0));
  //�����źţ�������ʱ����Ĳۺ���
  emit NoTimeSignal();
  //�߳��������٣������߳���-1
  timer_thread_amount--;
}

//
//�������Զ���Ի�����ʾ��ʷ��¼
//
void QtGuiApplication::ShowHistory() {
  historydialog = new HistoryDialog(this);
  historydialog->show();
}

//
//
//
void QtGuiApplication::StartExercises() {
  ui.start_button->setDisabled(true);
  //��ȡ��Ŀ������Ϣ
  int amount = ui.question_amount_lineedit->text().toInt();
  int combobox_index = ui.comboBox->currentIndex();
  int if_pow = ui.comboBox_2->currentIndex();

  if (amount < 1 || amount > 1000) {
    QMessageBox::information(this, u8"��������", u8"������1-1000����Ŀ����", QMessageBox::Yes);
    ui.start_button->setEnabled(true);
    return;
  }
  //����Question�����Ŀ��Ϣ
  question.SetType((enum Question::NumberType)(combobox_index + 1), (enum Question::IfPowOperator)if_pow);
  question.GenerateAndSave(amount);
  question_amount = amount;
  current_index = 0;
  current_score = 0;
  
  fprintf_s(fp_history, "��ʼ���ԣ��� %d ��\n", question_amount);
  //����һ����
  ui.index_label->setText(u8"��ǰ��Ŀ�� " + QString::number(current_index + 1) + " / " + QString::number(amount));
  ui.score_label->setText(u8"��ǰ�÷֣� " + QString::number(current_score));
  ui.textBrowser->setText(QString::fromStdString(question.GetQuestion(current_index) + "\n"));
  
  ui.next_question_button->setEnabled(true);
  ui.submit_button->setEnabled(true); 
  //������ʱ���߳�
  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  timer_thread_amount++;
}

//
//
//
void QtGuiApplication::SubmitAnswer() {
  ui.submit_button->setDisabled(true);
  ui.next_question_button->setDisabled(true);
  //�ж϶Բ���
  if (question.Calculate(current_index).ToString() == ui.answer_lineedit->text().toStdString()) {
    ui.right_wrong_label->setText(u8"��");
    current_score += 10;
    ui.score_label->setText(u8"��ǰ�÷֣� " + QString::number(current_score));
    fprintf_s(fp_history, "��%d�⣬ %s�� ����ȷ\n", current_index + 1, question.GetQuestion(current_index).data());
  } else {
    fprintf_s(fp_history, "��%d�⣬ %s�� �𰸴��� ӦΪ%s\n", current_index + 1, question.GetQuestion(current_index).data(), question.Calculate(current_index).ToString().data());
    ui.right_wrong_label->setText(u8"X");
  }
  //��ʱ1�룬��ʾ�Ի��Ǵ�
  QTime dieTime = QTime::currentTime().addMSecs(1000);
  while(QTime::currentTime() < dieTime)
  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
  ui.right_wrong_label->setText("");
  
  
  //����Ѿ�����������Ŀ���򵯳���ʾ����ֹ��ʱ���̣߳���ֹ������ʱ����
  if (current_index == question_amount - 1) {
    current_index++;
    timer_thread_amount++;
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    ui.right_wrong_label->setText("");
    timer_thread_amount--;
    fprintf_s(fp_history, "������ɣ�����Ϊ��%d\n", current_score);
    QMessageBox::information(this, u8"���", u8"�����������Ŀ��\n������ " + QString::number(current_score), QMessageBox::Yes);
    ui.start_button->setEnabled(true);
    return;
  }
  
  current_index++;
  //������Ŀ��ŵ�label 
  ui.index_label->setText(u8"��ǰ��Ŀ�� " + QString::number(current_index + 1) + " / " + QString::number(question_amount));
  //����һ����
  ui.textBrowser->setText(QString::fromStdString(question.GetQuestion(current_index) + "\n"));

  ui.submit_button->setEnabled(true);
  ui.next_question_button->setEnabled(true);
  //������ʱ���߳�
  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  timer_thread_amount++;
}

//
//
//
void QtGuiApplication::NextQuestion() {
  ui.submit_button->setDisabled(true);
  ui.next_question_button->setDisabled(true);
  fprintf_s(fp_history, "��%d�⣬ %s�� ����δ��\n", current_index + 1, question.GetQuestion(current_index).data());
  //����Ѿ�����������Ŀ���򵯳���ʾ����ֹ��ʱ���̣߳���ֹ������ʱ����
  if (current_index == question_amount - 1) {
    current_index++;
    timer_thread_amount++;
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    timer_thread_amount--;
    fprintf_s(fp_history, "������ɣ�����Ϊ��%d\n", current_score);
    QMessageBox::information(this, u8"���", u8"�����������Ŀ��\n������ " + QString::number(current_score), QMessageBox::Yes);
    ui.start_button->setEnabled(true);
    return;
  }
  
  current_index++;
  //������Ŀ��ŵ�label 
  ui.index_label->setText(u8"��ǰ��Ŀ�� " + QString::number(current_index + 1) + " / " + QString::number(question_amount));
  //����һ����
  ui.textBrowser->setText(QString::fromStdString(question.GetQuestion(current_index) + "\n"));

  ui.submit_button->setEnabled(true);
  ui.next_question_button->setEnabled(true);
  //������ʱ���߳�
  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  timer_thread_amount++;
}

//
//
//
void QtGuiApplication::RunOutOfTime() {
  fprintf_s(fp_history, "��%d�⣬ %s�� ��ʱδ��\n", current_index + 1, question.GetQuestion(current_index).data());
  QMessageBox::information(this, u8"��ʱ", u8"��ʱ��", QMessageBox::Yes);

  //����Ѿ�����������Ŀ���򵯳���ʾ����ֹ��ʱ���̣߳���ֹ������ʱ����
  if (current_index == question_amount - 1) {
    current_index++;
    timer_thread_amount++;
    Sleep(1000);
    timer_thread_amount--;
    fprintf_s(fp_history, "������ɣ�����Ϊ��%d\n", current_score);
    QMessageBox::information(this, u8"���", u8"�����������Ŀ��\n������ " + QString::number(current_score), QMessageBox::Yes);
    ui.start_button->setEnabled(true);
    return;
  }
  
  current_index++;
  //������Ŀ��ŵ�label 
  ui.index_label->setText(u8"��ǰ��Ŀ�� " + QString::number(current_index + 1) + " / " + QString::number(question_amount));
  //����һ����
  ui.textBrowser->setText(QString::fromStdString(question.GetQuestion(current_index) + "\n"));

  ui.submit_button->setEnabled(true);
  ui.next_question_button->setEnabled(true);
  //������ʱ���߳�
  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  timer_thread_amount++;
}