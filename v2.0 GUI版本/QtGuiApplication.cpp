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
    ui.comboBox->addItem(u8"整数运算");
    ui.comboBox->addItem(u8"分数运算");
    ui.comboBox->addItem(u8"整数分数混合运算");
    ui.comboBox_2->addItem(u8"无乘方");
    ui.comboBox_2->addItem(u8"有乘方，用 ^表示");
    ui.comboBox_2->addItem(u8"有乘方，用**表示");
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
      printf("打开文件失败\n");
    }
    timer_thread_amount = 0;
    
}

QtGuiApplication::~QtGuiApplication() {
  if (current_index != question_amount) {
    fputs("测试未完成，程序中途退出\n", fp_history);
  }
  if (fp_history != NULL)
    fclose(fp_history);
}

//
//计时器函数，创建一个新计时器线程，如果检测到多个线程，则按时间顺序销毁
//
void QtGuiApplication::StartTimer(int seconds) {
  for (int i = seconds; i >= 1; i--) {
    if (timer_thread_amount > 1 && i != seconds) {
    //如果创建超过了1秒，而且现有线程数>1，则销毁此线程，并把线程数-1
      timer_thread_amount--;
      return;
    }
    ui.countdown_lable->setText(QString::number(i));
    Sleep(1000);
  }
  ui.countdown_lable->setText(QString::number(0));
  //发送信号，引发超时处理的槽函数
  emit NoTimeSignal();
  //线程自行销毁，并把线程数-1
  timer_thread_amount--;
}

//
//创建新自定义对话框，显示历史记录
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
  //获取题目设置信息
  int amount = ui.question_amount_lineedit->text().toInt();
  int combobox_index = ui.comboBox->currentIndex();
  int if_pow = ui.comboBox_2->currentIndex();

  if (amount < 1 || amount > 1000) {
    QMessageBox::information(this, u8"错误数量", u8"请输入1-1000的题目数量", QMessageBox::Yes);
    ui.start_button->setEnabled(true);
    return;
  }
  //设置Question类的题目信息
  question.SetType((enum Question::NumberType)(combobox_index + 1), (enum Question::IfPowOperator)if_pow);
  question.GenerateAndSave(amount);
  question_amount = amount;
  current_index = 0;
  current_score = 0;
  
  fprintf_s(fp_history, "开始测试，共 %d 题\n", question_amount);
  //出第一道题
  ui.index_label->setText(u8"当前题目： " + QString::number(current_index + 1) + " / " + QString::number(amount));
  ui.score_label->setText(u8"当前得分： " + QString::number(current_score));
  ui.textBrowser->setText(QString::fromStdString(question.GetQuestion(current_index) + "\n"));
  
  ui.next_question_button->setEnabled(true);
  ui.submit_button->setEnabled(true); 
  //启动计时器线程
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
  //判断对不对
  if (question.Calculate(current_index).ToString() == ui.answer_lineedit->text().toStdString()) {
    ui.right_wrong_label->setText(u8"√");
    current_score += 10;
    ui.score_label->setText(u8"当前得分： " + QString::number(current_score));
    fprintf_s(fp_history, "第%d题， %s， 答案正确\n", current_index + 1, question.GetQuestion(current_index).data());
  } else {
    fprintf_s(fp_history, "第%d题， %s， 答案错误， 应为%s\n", current_index + 1, question.GetQuestion(current_index).data(), question.Calculate(current_index).ToString().data());
    ui.right_wrong_label->setText(u8"X");
  }
  //延时1秒，显示对还是错
  QTime dieTime = QTime::currentTime().addMSecs(1000);
  while(QTime::currentTime() < dieTime)
  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
  ui.right_wrong_label->setText("");
  
  
  //如果已经做完所有题目，则弹出提示，终止计时器线程，防止触发超时处理
  if (current_index == question_amount - 1) {
    current_index++;
    timer_thread_amount++;
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    ui.right_wrong_label->setText("");
    timer_thread_amount--;
    fprintf_s(fp_history, "测试完成，分数为：%d\n", current_score);
    QMessageBox::information(this, u8"完成", u8"已完成所有题目！\n分数： " + QString::number(current_score), QMessageBox::Yes);
    ui.start_button->setEnabled(true);
    return;
  }
  
  current_index++;
  //更新题目编号的label 
  ui.index_label->setText(u8"当前题目： " + QString::number(current_index + 1) + " / " + QString::number(question_amount));
  //出下一道题
  ui.textBrowser->setText(QString::fromStdString(question.GetQuestion(current_index) + "\n"));

  ui.submit_button->setEnabled(true);
  ui.next_question_button->setEnabled(true);
  //启动计时器线程
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
  fprintf_s(fp_history, "第%d题， %s， 跳过未做\n", current_index + 1, question.GetQuestion(current_index).data());
  //如果已经做完所有题目，则弹出提示，终止计时器线程，防止触发超时处理
  if (current_index == question_amount - 1) {
    current_index++;
    timer_thread_amount++;
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    timer_thread_amount--;
    fprintf_s(fp_history, "测试完成，分数为：%d\n", current_score);
    QMessageBox::information(this, u8"完成", u8"已完成所有题目！\n分数： " + QString::number(current_score), QMessageBox::Yes);
    ui.start_button->setEnabled(true);
    return;
  }
  
  current_index++;
  //更新题目编号的label 
  ui.index_label->setText(u8"当前题目： " + QString::number(current_index + 1) + " / " + QString::number(question_amount));
  //出下一道题
  ui.textBrowser->setText(QString::fromStdString(question.GetQuestion(current_index) + "\n"));

  ui.submit_button->setEnabled(true);
  ui.next_question_button->setEnabled(true);
  //启动计时器线程
  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  timer_thread_amount++;
}

//
//
//
void QtGuiApplication::RunOutOfTime() {
  fprintf_s(fp_history, "第%d题， %s， 超时未做\n", current_index + 1, question.GetQuestion(current_index).data());
  QMessageBox::information(this, u8"超时", u8"超时！", QMessageBox::Yes);

  //如果已经做完所有题目，则弹出提示，终止计时器线程，防止触发超时处理
  if (current_index == question_amount - 1) {
    current_index++;
    timer_thread_amount++;
    Sleep(1000);
    timer_thread_amount--;
    fprintf_s(fp_history, "测试完成，分数为：%d\n", current_score);
    QMessageBox::information(this, u8"完成", u8"已完成所有题目！\n分数： " + QString::number(current_score), QMessageBox::Yes);
    ui.start_button->setEnabled(true);
    return;
  }
  
  current_index++;
  //更新题目编号的label 
  ui.index_label->setText(u8"当前题目： " + QString::number(current_index + 1) + " / " + QString::number(question_amount));
  //出下一道题
  ui.textBrowser->setText(QString::fromStdString(question.GetQuestion(current_index) + "\n"));

  ui.submit_button->setEnabled(true);
  ui.next_question_button->setEnabled(true);
  //启动计时器线程
  std::thread thread_timer(std::bind(&QtGuiApplication::StartTimer, this, 20));
  thread_timer.detach();
  timer_thread_amount++;
}