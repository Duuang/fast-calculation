#pragma once
#include <QDialog>
#include "ui_show_history.h"

class HistoryDialog : public QDialog {
  Q_OBJECT

public:
  HistoryDialog(QWidget *parent = Q_NULLPTR);

private:
  Ui::HistoryDialog ui; 
};
