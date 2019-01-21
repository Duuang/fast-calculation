#include "QtGuiApplication.h"
#include <QDialog>
#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>
#include <QThread>
#include <QCoreApplication>
#include <QTime>

QtGuiApplication::QtGuiApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.comboBox->addItem("整数运算");
    ui.comboBox->addItem("分数运算");
    ui.comboBox->addItem("整数分数混合");
    ui.next_question_button->setDisabled(true);
    ui.submit_button->setDisabled(true);
    connect(ui.history_button, SIGNAL(clicked()), this, SLOT(ShowHistory()));
    connect(ui.start_button, SIGNAL(clicked()), this, SLOT(StartExercises()));
    connect(ui.submit_button, SIGNAL(clicked()), this, SLOT(SubmitAnswer()));
    connect(ui.next_question_button, SIGNAL(clicked()), this, SLOT(NextQuestion()));
    connect(this, SIGNAL(NoTimeSignal()), this, SLOT(RunOutOfTime()));

    timer_thread_amount = 0;

}

void QtGuiApplication::StartTimer(int seconds) {
printf("thread created, timer_thread_amount = %d\n", timer_thread_amount);
  for (int i = seconds; i >= 1; i--) {
    if (timer_thread_amount > 1 && i != seconds) {
      printf("thread destroyed, timer_thread_amount = %d\n", timer_thread_amount);
      timer_thread_amount--;

      return;
    }
    ui.countdown_lable->setText(QString::number(i));
    Sleep(1000);
  }
  ui.countdown_lable->setText(QString::number(0));
  printf("emit signal \n");
  emit NoTimeSignal();
  printf("thread destroyed \n");
  timer_thread_amount--;
}

void QtGuiApplication::ShowHistory() {
  historydialog = new HistoryDialog(this);
  historydialog->show();
  //ui.label->setText("aaaaaaaa");
}
void QtGuiApplication::StartExercises() {
  ui.start_button->setDisabled(true);
  int amount = ui.question_amount_lineedit->text().toInt();
  std::cout << "amount: "<<amount << std::endl;
  bool if_pow = ui.checkBox->isChecked();
  int combobox_index = ui.comboBox->currentIndex();
  /*
  question.SetType((enum Question::NumberType)(combobox_index + 1), if_pow);
  question.GenerateAndSave(amount);

  ui.textBrowser->insertPlainText(QString::fromStdString(question.GetNextQuestion() + "\n"));*/
  //����
  ui.textBrowser->setText("aaaaaaaa\naaaaaaaa");

  ui.next_question_button->setEnabled(true);
  ui.submit_button->setEnabled(true);

  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  timer_thread_amount++;
}

void QtGuiApplication::SubmitAnswer() {
  ui.submit_button->setDisabled(true);
  ui.next_question_button->setDisabled(true);
  //�ж϶Բ���
  ui.right_wrong_label->setText("正确");

  QTime dieTime = QTime::currentTime().addMSecs(1000);
  while(QTime::currentTime() < dieTime)
  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

  ui.right_wrong_label->setText("");
  ui.submit_button->setEnabled(true);
  ui.next_question_button->setEnabled(true);
  //����һ����
  ui.textBrowser->setText("aaaaaaaa\naaaaaaaa");

  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  timer_thread_amount++;
}


void QtGuiApplication::NextQuestion() {
  //����һ����
  ui.textBrowser->setText("aaaaaaaa\naaaaaaaa");

  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  printf("a\n");
  timer_thread_amount++;
}


void QtGuiApplication::RunOutOfTime() {

  printf("Out of time\n");
}
