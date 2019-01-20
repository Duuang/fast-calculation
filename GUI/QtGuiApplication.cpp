#include "QtGuiApplication.h"

#include <QDialog>
QtGuiApplication::QtGuiApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.comboBox->addItem(u8"整数运算");
    ui.comboBox->addItem(u8"分数运算");
    ui.comboBox->addItem(u8"整数分数混合运算");
    connect(ui.history_button, SIGNAL(clicked()), this, SLOT(ShowHistory()));
    connect(ui.start_button, SIGNAL(clicked()), this, SLOT(ShowHistory()));
    
}

void QtGuiApplication::ShowHistory() {
  historydialog = new HistoryDialog(this);
  historydialog->show();
  //ui.label->setText("aaaaaaaa");
}