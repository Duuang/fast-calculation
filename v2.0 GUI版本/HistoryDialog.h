#pragma once
#include <QDialog>
#include "QtGuiApplication.h"
#include "ui_show_history.h"
#include <iostream>
#include <stdio.h>

class QtGuiApplication;

class HistoryDialog : public QDialog {
  Q_OBJECT

public:
  HistoryDialog(QWidget *parent = NULL);
  
private:
  //指向主窗口的指针
  QtGuiApplication *mainwindow;
  //历史记录文件的指针，从主窗口对象中的fp_history获得
  FILE *fp;
  Ui::HistoryDialog ui;

private slots:
  //清除历史记录
  void ClearHistory();
};
