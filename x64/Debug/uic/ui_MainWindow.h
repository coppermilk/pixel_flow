/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QLabel *activity_type_label;
    QLabel *deley_type_label;
    QComboBox *comboBoxActivityType;
    QComboBox *comboBoxTimer;
    QLabel *minutes_label;
    QSpacerItem *horizontalSpacer;
    QLabel *seconds_label;
    QGroupBox *groupBox;
    QLabel *label_6;
    QLabel *label_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_4;
    QLabel *label_4;
    QSlider *horizontalSliderMinGreenBrightness;
    QWidget *widgetMinPixelBrightnessColor;
    QSlider *horizontalSliderMinBlueBrightness;
    QSlider *horizontalSliderMinRedBrightness;
    QSpinBox *spinBox_5;
    QGroupBox *groupBox_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QSlider *horizontalSliderMaxBlueBrightness;
    QSpinBox *spinBox;
    QSpinBox *spinBox_3;
    QWidget *widgetMaxPixelBrightnessColor;
    QSlider *horizontalSliderMaxRedBrightness;
    QSlider *horizontalSliderMaxGreenBrightness;
    QGroupBox *name_text_activity;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;
    QLabel *label_pixel_board;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName("mainwindowClass");
        mainwindowClass->resize(714, 364);
        centralWidget = new QWidget(mainwindowClass);
        centralWidget->setObjectName("centralWidget");
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 691, 141));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName("groupBox_3");
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(11, 21, 201, 81));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        activity_type_label = new QLabel(layoutWidget1);
        activity_type_label->setObjectName("activity_type_label");

        gridLayout->addWidget(activity_type_label, 0, 0, 1, 1);

        deley_type_label = new QLabel(layoutWidget1);
        deley_type_label->setObjectName("deley_type_label");

        gridLayout->addWidget(deley_type_label, 1, 0, 1, 1);

        comboBoxActivityType = new QComboBox(layoutWidget1);
        comboBoxActivityType->setObjectName("comboBoxActivityType");

        gridLayout->addWidget(comboBoxActivityType, 0, 1, 1, 3);

        comboBoxTimer = new QComboBox(layoutWidget1);
        comboBoxTimer->setObjectName("comboBoxTimer");

        gridLayout->addWidget(comboBoxTimer, 1, 1, 1, 3);

        minutes_label = new QLabel(layoutWidget1);
        minutes_label->setObjectName("minutes_label");
        minutes_label->setLayoutDirection(Qt::LeftToRight);
        minutes_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(minutes_label, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 3, 1, 1);

        seconds_label = new QLabel(layoutWidget1);
        seconds_label->setObjectName("seconds_label");

        gridLayout->addWidget(seconds_label, 2, 2, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName("groupBox");
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(21, 87, 16, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(21, 59, 16, 16));
        spinBox_6 = new QSpinBox(groupBox);
        spinBox_6->setObjectName("spinBox_6");
        spinBox_6->setGeometry(QRect(126, 87, 39, 22));
        spinBox_6->setMaximum(255);
        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setGeometry(QRect(126, 31, 39, 22));
        spinBox_4->setMaximum(255);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(21, 31, 16, 16));
        horizontalSliderMinGreenBrightness = new QSlider(groupBox);
        horizontalSliderMinGreenBrightness->setObjectName("horizontalSliderMinGreenBrightness");
        horizontalSliderMinGreenBrightness->setGeometry(QRect(35, 59, 84, 22));
        horizontalSliderMinGreenBrightness->setMaximum(255);
        horizontalSliderMinGreenBrightness->setOrientation(Qt::Horizontal);
        widgetMinPixelBrightnessColor = new QWidget(groupBox);
        widgetMinPixelBrightnessColor->setObjectName("widgetMinPixelBrightnessColor");
        widgetMinPixelBrightnessColor->setGeometry(QRect(171, 31, 39, 78));
        widgetMinPixelBrightnessColor->setMinimumSize(QSize(39, 3));
        widgetMinPixelBrightnessColor->setAutoFillBackground(true);
        horizontalSliderMinBlueBrightness = new QSlider(groupBox);
        horizontalSliderMinBlueBrightness->setObjectName("horizontalSliderMinBlueBrightness");
        horizontalSliderMinBlueBrightness->setGeometry(QRect(35, 87, 84, 22));
        horizontalSliderMinBlueBrightness->setMaximum(255);
        horizontalSliderMinBlueBrightness->setOrientation(Qt::Horizontal);
        horizontalSliderMinRedBrightness = new QSlider(groupBox);
        horizontalSliderMinRedBrightness->setObjectName("horizontalSliderMinRedBrightness");
        horizontalSliderMinRedBrightness->setGeometry(QRect(35, 31, 84, 22));
        horizontalSliderMinRedBrightness->setMaximum(255);
        horizontalSliderMinRedBrightness->setOrientation(Qt::Horizontal);
        spinBox_5 = new QSpinBox(groupBox);
        spinBox_5->setObjectName("spinBox_5");
        spinBox_5->setGeometry(QRect(126, 59, 39, 22));
        spinBox_5->setMaximum(255);

        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setEnabled(true);
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(125, 59, 39, 22));
        spinBox_2->setMaximum(255);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(21, 87, 16, 16));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(21, 59, 16, 16));
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(21, 31, 16, 16));
        horizontalSliderMaxBlueBrightness = new QSlider(groupBox_2);
        horizontalSliderMaxBlueBrightness->setObjectName("horizontalSliderMaxBlueBrightness");
        horizontalSliderMaxBlueBrightness->setGeometry(QRect(35, 87, 84, 22));
        horizontalSliderMaxBlueBrightness->setMaximum(255);
        horizontalSliderMaxBlueBrightness->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(125, 31, 39, 22));
        spinBox->setMaximum(255);
        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(125, 87, 39, 22));
        spinBox_3->setMaximum(255);
        widgetMaxPixelBrightnessColor = new QWidget(groupBox_2);
        widgetMaxPixelBrightnessColor->setObjectName("widgetMaxPixelBrightnessColor");
        widgetMaxPixelBrightnessColor->setGeometry(QRect(170, 31, 39, 78));
        widgetMaxPixelBrightnessColor->setMinimumSize(QSize(39, 3));
        widgetMaxPixelBrightnessColor->setAutoFillBackground(true);
        horizontalSliderMaxRedBrightness = new QSlider(groupBox_2);
        horizontalSliderMaxRedBrightness->setObjectName("horizontalSliderMaxRedBrightness");
        horizontalSliderMaxRedBrightness->setGeometry(QRect(35, 31, 84, 22));
        horizontalSliderMaxRedBrightness->setMaximum(255);
        horizontalSliderMaxRedBrightness->setOrientation(Qt::Horizontal);
        horizontalSliderMaxGreenBrightness = new QSlider(groupBox_2);
        horizontalSliderMaxGreenBrightness->setObjectName("horizontalSliderMaxGreenBrightness");
        horizontalSliderMaxGreenBrightness->setGeometry(QRect(35, 59, 84, 22));
        horizontalSliderMaxGreenBrightness->setMaximum(255);
        horizontalSliderMaxGreenBrightness->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(groupBox_2);

        name_text_activity = new QGroupBox(centralWidget);
        name_text_activity->setObjectName("name_text_activity");
        name_text_activity->setGeometry(QRect(10, 170, 691, 131));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 190, 731, 98));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(12, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(32, 16777215));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(32, 16777215));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(32, 16777215));

        verticalLayout->addWidget(label_9);

        verticalSpacer = new QSpacerItem(12, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        label_pixel_board = new QLabel(layoutWidget2);
        label_pixel_board->setObjectName("label_pixel_board");
        label_pixel_board->setEnabled(true);
        label_pixel_board->setMinimumSize(QSize(10, 10));
        label_pixel_board->setMaximumSize(QSize(689, 91));

        horizontalLayout_2->addWidget(label_pixel_board);

        mainwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainwindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 714, 22));
        mainwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainwindowClass);
        mainToolBar->setObjectName("mainToolBar");
        mainwindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainwindowClass);
        statusBar->setObjectName("statusBar");
        mainwindowClass->setStatusBar(statusBar);

        retranslateUi(mainwindowClass);
        QObject::connect(horizontalSliderMaxRedBrightness, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
        QObject::connect(horizontalSliderMaxGreenBrightness, &QSlider::valueChanged, spinBox_2, &QSpinBox::setValue);
        QObject::connect(horizontalSliderMaxBlueBrightness, &QSlider::valueChanged, spinBox_3, &QSpinBox::setValue);
        QObject::connect(spinBox_3, &QSpinBox::valueChanged, horizontalSliderMaxBlueBrightness, &QSlider::setValue);
        QObject::connect(spinBox_2, &QSpinBox::valueChanged, horizontalSliderMaxGreenBrightness, &QSlider::setValue);
        QObject::connect(spinBox, &QSpinBox::valueChanged, horizontalSliderMaxRedBrightness, &QSlider::setValue);
        QObject::connect(horizontalSliderMinRedBrightness, &QSlider::valueChanged, spinBox_4, &QSpinBox::setValue);
        QObject::connect(horizontalSliderMinGreenBrightness, &QSlider::valueChanged, spinBox_5, &QSpinBox::setValue);
        QObject::connect(horizontalSliderMinBlueBrightness, &QSlider::valueChanged, spinBox_6, &QSpinBox::setValue);
        QObject::connect(spinBox_6, &QSpinBox::valueChanged, horizontalSliderMinBlueBrightness, &QSlider::setValue);
        QObject::connect(spinBox_5, &QSpinBox::valueChanged, horizontalSliderMinGreenBrightness, &QSlider::setValue);
        QObject::connect(spinBox_4, &QSpinBox::valueChanged, horizontalSliderMinRedBrightness, &QSlider::setValue);

        QMetaObject::connectSlotsByName(mainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowClass)
    {
        mainwindowClass->setWindowTitle(QCoreApplication::translate("mainwindowClass", "mainwindow", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("mainwindowClass", "Setting", nullptr));
        label_10->setText(QCoreApplication::translate("mainwindowClass", "Countdown", nullptr));
        activity_type_label->setText(QCoreApplication::translate("mainwindowClass", "Activity type", nullptr));
        deley_type_label->setText(QCoreApplication::translate("mainwindowClass", "Delay seconds", nullptr));
        minutes_label->setText(QCoreApplication::translate("mainwindowClass", "0", nullptr));
        seconds_label->setText(QCoreApplication::translate("mainwindowClass", "0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mainwindowClass", "Min brightness", nullptr));
        label_6->setText(QCoreApplication::translate("mainwindowClass", "B", nullptr));
        label_5->setText(QCoreApplication::translate("mainwindowClass", "G", nullptr));
        label_4->setText(QCoreApplication::translate("mainwindowClass", "R", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("mainwindowClass", "Max brightness", nullptr));
        label_3->setText(QCoreApplication::translate("mainwindowClass", "B", nullptr));
        label_2->setText(QCoreApplication::translate("mainwindowClass", "G", nullptr));
        label->setText(QCoreApplication::translate("mainwindowClass", "R", nullptr));
        name_text_activity->setTitle(QCoreApplication::translate("mainwindowClass", "GroupBox", nullptr));
        label_7->setText(QCoreApplication::translate("mainwindowClass", "Mon", nullptr));
        label_8->setText(QCoreApplication::translate("mainwindowClass", "Wed", nullptr));
        label_9->setText(QCoreApplication::translate("mainwindowClass", "Fri", nullptr));
        label_pixel_board->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainwindowClass: public Ui_mainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
