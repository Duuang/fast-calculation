#include "HistoryDialog.h"
#include "QtGuiApplication.h"
#include <QMessageBox>
#include <QDialog>
#include <stdio.h>
#include <iostream>
using namespace std;

HistoryDialog::HistoryDialog(QWidget *parent) :
  QDialog(parent) {
  //从主窗口对象获得历史文件的FILE*指针
  fp = ((QtGuiApplication*)parent)->fp_history;
  //指向主窗口对象的指针
  mainwindow = (QtGuiApplication*)parent;
  ui.setupUi(this);
  //清除历史记录按钮
  connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ClearHistory()));
  //按行读取文件内容到textBrowser
  char buffer[1008];
  rewind(fp);
  while (fgets(buffer, 1005, fp) != NULL) {
    ui.textBrowser->insertPlainText(QString::fromLocal8Bit(buffer));
  }
}

void HistoryDialog::ClearHistory() {
  fclose(fp);
  //重新以w+打开文件，清除文件内容
  errno_t err;
  err = fopen_s(&fp, "history.txt", "w+");
  if (fp == NULL) {
    printf("文件打开出错\n");
    return;
  }
  //更新主窗口对象中的fp值（是它的友元类，直接访问私有数据）
  mainwindow->fp_history = fp;
  QMessageBox::information(this, u8"成功", u8"历史记录清除成功！", QMessageBox::Yes);
}