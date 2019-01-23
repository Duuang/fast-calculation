#include "HistoryDialog.h"
#include "QtGuiApplication.h"
#include <QMessageBox>
#include <QDialog>
#include <stdio.h>
#include <iostream>
using namespace std;

HistoryDialog::HistoryDialog(QWidget *parent) :
  QDialog(parent) {
  //�������ڶ�������ʷ�ļ���FILE*ָ��
  fp = ((QtGuiApplication*)parent)->fp_history;
  //ָ�������ڶ����ָ��
  mainwindow = (QtGuiApplication*)parent;
  ui.setupUi(this);
  //�����ʷ��¼��ť
  connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ClearHistory()));
  //���ж�ȡ�ļ����ݵ�textBrowser
  char buffer[1008];
  rewind(fp);
  while (fgets(buffer, 1005, fp) != NULL) {
    ui.textBrowser->insertPlainText(QString::fromLocal8Bit(buffer));
  }
}

void HistoryDialog::ClearHistory() {
  fclose(fp);
  //������w+���ļ�������ļ�����
  errno_t err;
  err = fopen_s(&fp, "history.txt", "w+");
  if (fp == NULL) {
    printf("�ļ��򿪳���\n");
    return;
  }
  //���������ڶ����е�fpֵ����������Ԫ�ֱ࣬�ӷ���˽�����ݣ�
  mainwindow->fp_history = fp;
  QMessageBox::information(this, u8"�ɹ�", u8"��ʷ��¼����ɹ���", QMessageBox::Yes);
}