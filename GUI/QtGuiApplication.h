#pragma once

#include <QtWidgets/QMainWindow>
#include "C:\Users\cky\Documents\QtProjects\untitled1\GeneratedFiles\ui_QtGuiApplication.h"
#include "HistoryDialog.h"
#include "C:\Users\cky\source\repos\fast-calculation\fast-calculation\Question.h"

class QtGuiApplication : public QMainWindow
{
  Q_OBJECT

public:
  QtGuiApplication(QWidget *parent = Q_NULLPTR);

private:
  Ui::QtGuiApplicationClass ui;
  HistoryDialog *historydialog;
  //Question question;
  int timer_thread_amount;
  
  void StartTimer(int seconds);
signals:
  void NoTimeSignal();

private slots:
  void ShowHistory();
  void StartExercises();
  void SubmitAnswer();
  void NextQuestion();

  void RunOutOfTime();
};

