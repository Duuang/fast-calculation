/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION_H
#define UI_QTGUIAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplicationClass
{
public:
    QWidget *centralWidget;
    QPushButton *submit_button;
    QTextBrowser *textBrowser;
    QLineEdit *answer_lineedit;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *start_button;
    QLineEdit *question_amount_lineedit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *history_button;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *countdown_lable;
    QPushButton *next_question_button;
    QLabel *right_wrong_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplicationClass)
    {
        if (QtGuiApplicationClass->objectName().isEmpty())
            QtGuiApplicationClass->setObjectName(QStringLiteral("QtGuiApplicationClass"));
        QtGuiApplicationClass->resize(712, 527);
        centralWidget = new QWidget(QtGuiApplicationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        submit_button = new QPushButton(centralWidget);
        submit_button->setObjectName(QStringLiteral("submit_button"));
        submit_button->setGeometry(QRect(210, 340, 112, 34));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(50, 200, 251, 81));
        answer_lineedit = new QLineEdit(centralWidget);
        answer_lineedit->setObjectName(QStringLiteral("answer_lineedit"));
        answer_lineedit->setGeometry(QRect(50, 340, 141, 31));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(460, 160, 105, 22));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(460, 100, 181, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 50, 81, 18));
        start_button = new QPushButton(centralWidget);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(490, 260, 131, 71));
        question_amount_lineedit = new QLineEdit(centralWidget);
        question_amount_lineedit->setObjectName(QStringLiteral("question_amount_lineedit"));
        question_amount_lineedit->setGeometry(QRect(550, 210, 113, 25));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 210, 91, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 310, 81, 18));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 80, 71, 41));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 170, 101, 16));
        history_button = new QPushButton(centralWidget);
        history_button->setObjectName(QStringLiteral("history_button"));
        history_button->setGeometry(QRect(480, 390, 151, 41));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(220, 90, 161, 18));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(220, 130, 181, 18));
        countdown_lable = new QLabel(centralWidget);
        countdown_lable->setObjectName(QStringLiteral("countdown_lable"));
        countdown_lable->setGeometry(QRect(120, 80, 61, 51));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        countdown_lable->setFont(font);
        next_question_button = new QPushButton(centralWidget);
        next_question_button->setObjectName(QStringLiteral("next_question_button"));
        next_question_button->setGeometry(QRect(210, 400, 151, 34));
        right_wrong_label = new QLabel(centralWidget);
        right_wrong_label->setObjectName(QStringLiteral("right_wrong_label"));
        right_wrong_label->setGeometry(QRect(340, 310, 81, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(22);
        right_wrong_label->setFont(font1);
        QtGuiApplicationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplicationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 712, 30));
        QtGuiApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplicationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplicationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplicationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplicationClass->setStatusBar(statusBar);

        retranslateUi(QtGuiApplicationClass);

        QMetaObject::connectSlotsByName(QtGuiApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplicationClass)
    {
        QtGuiApplicationClass->setWindowTitle(QApplication::translate("QtGuiApplicationClass", "QtGuiApplication", Q_NULLPTR));
        submit_button->setText(QApplication::translate("QtGuiApplicationClass", "\346\217\220\344\272\244\347\255\224\346\241\210", Q_NULLPTR));
        checkBox->setText(QApplication::translate("QtGuiApplicationClass", "\345\214\205\345\220\253\344\271\230\346\226\271", Q_NULLPTR));
        label->setText(QApplication::translate("QtGuiApplicationClass", "\351\242\230\347\233\256\350\256\276\347\275\256", Q_NULLPTR));
        start_button->setText(QApplication::translate("QtGuiApplicationClass", "\345\274\200\345\247\213\345\201\232\351\242\230", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtGuiApplicationClass", "\351\242\230\347\233\256\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtGuiApplicationClass", "\346\210\221\347\232\204\347\255\224\346\241\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtGuiApplicationClass", "\345\200\222\350\256\241\346\227\266\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("QtGuiApplicationClass", "\345\275\223\345\211\215\351\242\230\347\233\256\357\274\232", Q_NULLPTR));
        history_button->setText(QApplication::translate("QtGuiApplicationClass", "\347\255\224\351\242\230\345\216\206\345\217\262\350\256\260\345\275\225", Q_NULLPTR));
        label_6->setText(QApplication::translate("QtGuiApplicationClass", "\345\275\223\345\211\215\351\242\230\347\233\256\357\274\232?? / ??", Q_NULLPTR));
        label_7->setText(QApplication::translate("QtGuiApplicationClass", "\345\275\223\345\211\215\345\276\227\345\210\206\357\274\232 ??", Q_NULLPTR));
        countdown_lable->setText(QApplication::translate("QtGuiApplicationClass", "--", Q_NULLPTR));
        next_question_button->setText(QApplication::translate("QtGuiApplicationClass", "\344\270\215\344\274\232\345\201\232\357\274\214\344\270\213\344\270\200\351\242\230", Q_NULLPTR));
        right_wrong_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplicationClass: public Ui_QtGuiApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION_H
