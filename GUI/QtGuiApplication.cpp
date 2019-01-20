#include "QtGuiApplication.h"

#include <QDialog>
QtGuiApplication::QtGuiApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.comboBox->addItem(u8"��������");
    ui.comboBox->addItem(u8"��������");
    ui.comboBox->addItem(u8"���������������");
    connect(ui.history_button, SIGNAL(clicked()), this, SLOT(ShowHistory()));
    connect(ui.start_button, SIGNAL(clicked()), this, SLOT(ShowHistory()));
    
}

void QtGuiApplication::ShowHistory() {
  historydialog = new HistoryDialog(this);
  historydialog->show();
  //ui.label->setText("aaaaaaaa");
}