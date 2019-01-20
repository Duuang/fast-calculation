#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication.h"
#include "HistoryDialog.h"

class QtGuiApplication : public QMainWindow
{
  Q_OBJECT

public:
  QtGuiApplication(QWidget *parent = Q_NULLPTR);

private:
  Ui::QtGuiApplicationClass ui;
  HistoryDialog *historydialog;
  
  
private slots:
  void ShowHistory();
  
  
};

