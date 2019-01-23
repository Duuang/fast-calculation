#pragma once

#include <QtWidgets/QMainWindow>
#include <iostream>
#include <stdio.h>
#include "ui_QtGuiApplication.h"
#include "HistoryDialog.h"
#include "Question.h"

class QtGuiApplication : public QMainWindow
{
  Q_OBJECT

  friend class HistoryDialog;

public:
  QtGuiApplication(QWidget *parent = Q_NULLPTR);
  ~QtGuiApplication();

private:
  Ui::QtGuiApplicationClass ui;
  HistoryDialog *historydialog;
  Question question;
  int timer_thread_amount;
  FILE *fp_history;

  int question_amount;
  int current_index;
  int current_score;
  
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

