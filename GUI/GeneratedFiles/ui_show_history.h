/********************************************************************************
** Form generated from reading UI file 'show_history.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_HISTORY_H
#define UI_SHOW_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_HistoryDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *HistoryDialog)
    {
        if (HistoryDialog->objectName().isEmpty())
            HistoryDialog->setObjectName(QStringLiteral("HistoryDialog"));
        HistoryDialog->resize(523, 384);
        buttonBox = new QDialogButtonBox(HistoryDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 310, 131, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        tableView = new QTableView(HistoryDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(60, 40, 411, 231));
        pushButton = new QPushButton(HistoryDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(291, 310, 121, 34));

        retranslateUi(HistoryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HistoryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HistoryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoryDialog)
    {
        HistoryDialog->setWindowTitle(QApplication::translate("HistoryDialog", "\345\216\206\345\217\262\350\256\260\345\275\225", Q_NULLPTR));
        pushButton->setText(QApplication::translate("HistoryDialog", "\346\270\205\351\231\244\345\216\206\345\217\262\350\256\260\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HistoryDialog: public Ui_HistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_HISTORY_H
