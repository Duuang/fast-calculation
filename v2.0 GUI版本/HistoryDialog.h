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
  //ָ�������ڵ�ָ��
  QtGuiApplication *mainwindow;
  //��ʷ��¼�ļ���ָ�룬�������ڶ����е�fp_history���
  FILE *fp;
  Ui::HistoryDialog ui;

private slots:
  //�����ʷ��¼
  void ClearHistory();
};
