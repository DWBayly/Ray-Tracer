/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QGridLayout *gridLayout;
    QScrollArea *glWidgetArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *controlFrame;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QSlider *verticalSlider_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(911, 649);
        gridLayout = new QGridLayout(frmMain);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        glWidgetArea = new QScrollArea(frmMain);
        glWidgetArea->setObjectName(QStringLiteral("glWidgetArea"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glWidgetArea->sizePolicy().hasHeightForWidth());
        glWidgetArea->setSizePolicy(sizePolicy);
        glWidgetArea->setMinimumSize(QSize(580, 470));
        glWidgetArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        glWidgetArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        glWidgetArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 685, 629));
        glWidgetArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(glWidgetArea, 0, 1, 1, 1);

        controlFrame = new QFrame(frmMain);
        controlFrame->setObjectName(QStringLiteral("controlFrame"));
        controlFrame->setMinimumSize(QSize(200, 470));
        controlFrame->setMaximumSize(QSize(200, 16777215));
        controlFrame->setFrameShape(QFrame::StyledPanel);
        controlFrame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(controlFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 78, 54));
        pushButton_4 = new QPushButton(controlFrame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 590, 110, 32));
        layoutWidget = new QWidget(controlFrame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 159, 54));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(controlFrame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 150, 75, 23));
        pushButton_6 = new QPushButton(controlFrame);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(110, 150, 75, 23));
        pushButton_7 = new QPushButton(controlFrame);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 180, 75, 23));
        pushButton_8 = new QPushButton(controlFrame);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(110, 180, 75, 23));
        pushButton_9 = new QPushButton(controlFrame);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(20, 210, 75, 23));
        pushButton_10 = new QPushButton(controlFrame);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(110, 210, 75, 23));
        pushButton_11 = new QPushButton(controlFrame);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(20, 240, 75, 23));
        pushButton_12 = new QPushButton(controlFrame);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(110, 240, 75, 23));
        pushButton_13 = new QPushButton(controlFrame);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(20, 270, 75, 23));
        pushButton_14 = new QPushButton(controlFrame);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(110, 270, 75, 23));
        pushButton_15 = new QPushButton(controlFrame);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(20, 300, 75, 23));
        pushButton_16 = new QPushButton(controlFrame);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(110, 300, 75, 23));
        verticalSlider = new QSlider(controlFrame);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(10, 330, 22, 81));
        verticalSlider->setMaximum(255);
        verticalSlider->setSliderPosition(255);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider_2 = new QSlider(controlFrame);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(40, 330, 22, 81));
        verticalSlider_2->setMaximum(255);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_3 = new QSlider(controlFrame);
        verticalSlider_3->setObjectName(QStringLiteral("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(70, 330, 22, 81));
        verticalSlider_3->setMaximum(255);
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_4 = new QSlider(controlFrame);
        verticalSlider_4->setObjectName(QStringLiteral("verticalSlider_4"));
        verticalSlider_4->setGeometry(QRect(100, 330, 22, 81));
        verticalSlider_4->setMaximum(255);
        verticalSlider_4->setOrientation(Qt::Vertical);
        verticalSlider_5 = new QSlider(controlFrame);
        verticalSlider_5->setObjectName(QStringLiteral("verticalSlider_5"));
        verticalSlider_5->setGeometry(QRect(130, 330, 22, 81));
        verticalSlider_5->setMaximum(255);
        verticalSlider_5->setOrientation(Qt::Vertical);
        verticalSlider_6 = new QSlider(controlFrame);
        verticalSlider_6->setObjectName(QStringLiteral("verticalSlider_6"));
        verticalSlider_6->setGeometry(QRect(160, 330, 22, 81));
        verticalSlider_6->setMaximum(255);
        verticalSlider_6->setSliderPosition(255);
        verticalSlider_6->setOrientation(Qt::Vertical);
        label = new QLabel(controlFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 410, 16, 16));
        label_2 = new QLabel(controlFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 410, 16, 16));
        label_3 = new QLabel(controlFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 410, 16, 16));
        label_4 = new QLabel(controlFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 410, 16, 16));
        label_5 = new QLabel(controlFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 410, 16, 16));
        label_6 = new QLabel(controlFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(130, 410, 16, 16));
        label_7 = new QLabel(controlFrame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 420, 47, 13));
        label_8 = new QLabel(controlFrame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 420, 47, 13));
        label_9 = new QLabel(controlFrame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(70, 470, 91, 16));
        horizontalSlider = new QSlider(controlFrame);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 490, 160, 22));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setSliderPosition(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(controlFrame);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(40, 520, 160, 22));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setSliderPosition(0);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(controlFrame);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(40, 550, 160, 22));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(controlFrame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 490, 47, 13));
        label_11 = new QLabel(controlFrame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 520, 47, 13));
        label_12 = new QLabel(controlFrame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 550, 47, 13));
        pushButton_17 = new QPushButton(controlFrame);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 440, 75, 23));
        pushButton_18 = new QPushButton(controlFrame);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(110, 440, 75, 23));

        gridLayout->addWidget(controlFrame, 0, 0, 1, 1);


        retranslateUi(frmMain);
        QObject::connect(pushButton, SIGNAL(clicked()), frmMain, SLOT(openImage()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), frmMain, SLOT(saveImage()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), frmMain, SLOT(makeImage()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), frmMain, SLOT(close()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), frmMain, SLOT(zoomplus()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), frmMain, SLOT(zoomminus()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), frmMain, SLOT(xplus()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), frmMain, SLOT(yplus()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), frmMain, SLOT(xminus()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), frmMain, SLOT(yminus()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), frmMain, SLOT(lxplus()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), frmMain, SLOT(lxminus()));
        QObject::connect(pushButton_13, SIGNAL(clicked()), frmMain, SLOT(lyplus()));
        QObject::connect(pushButton_14, SIGNAL(clicked()), frmMain, SLOT(lyminus()));
        QObject::connect(pushButton_15, SIGNAL(clicked()), frmMain, SLOT(lzplus()));
        QObject::connect(pushButton_16, SIGNAL(clicked()), frmMain, SLOT(lzminus()));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), frmMain, SLOT(setL1R(int)));
        QObject::connect(verticalSlider_3, SIGNAL(valueChanged(int)), frmMain, SLOT(setL1B(int)));
        QObject::connect(verticalSlider_4, SIGNAL(sliderMoved(int)), frmMain, SLOT(setL2R(int)));
        QObject::connect(verticalSlider_5, SIGNAL(sliderMoved(int)), frmMain, SLOT(setL2G(int)));
        QObject::connect(verticalSlider_6, SIGNAL(sliderMoved(int)), frmMain, SLOT(setL2B(int)));
        QObject::connect(verticalSlider_2, SIGNAL(sliderMoved(int)), frmMain, SLOT(setL1G(int)));
        QObject::connect(pushButton_17, SIGNAL(clicked()), frmMain, SLOT(toggleS1()));
        QObject::connect(pushButton_18, SIGNAL(clicked()), frmMain, SLOT(toggleS2()));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), frmMain, SLOT(setSCR(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(sliderMoved(int)), frmMain, SLOT(setSCG(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(sliderMoved(int)), frmMain, SLOT(setSCB(int)));

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "QT skeleton - BW 2014", 0));
        pushButton->setText(QApplication::translate("frmMain", "open\n"
"image", 0));
        pushButton_4->setText(QApplication::translate("frmMain", "Quit", 0));
        pushButton_3->setText(QApplication::translate("frmMain", "make\n"
"image", 0));
        pushButton_2->setText(QApplication::translate("frmMain", "save\n"
"image", 0));
        pushButton_5->setText(QApplication::translate("frmMain", "Zoom+", 0));
        pushButton_6->setText(QApplication::translate("frmMain", "Zoom-", 0));
        pushButton_7->setText(QApplication::translate("frmMain", "xplus", 0));
        pushButton_8->setText(QApplication::translate("frmMain", "xminus", 0));
        pushButton_9->setText(QApplication::translate("frmMain", "yplus", 0));
        pushButton_10->setText(QApplication::translate("frmMain", "yminus", 0));
        pushButton_11->setText(QApplication::translate("frmMain", "Light1 x+", 0));
        pushButton_12->setText(QApplication::translate("frmMain", "Light1 x-", 0));
        pushButton_13->setText(QApplication::translate("frmMain", "Light1 y+", 0));
        pushButton_14->setText(QApplication::translate("frmMain", "Light1 y-", 0));
        pushButton_15->setText(QApplication::translate("frmMain", "Light1 z+", 0));
        pushButton_16->setText(QApplication::translate("frmMain", "Light1 z-", 0));
        label->setText(QApplication::translate("frmMain", "R", 0));
        label_2->setText(QApplication::translate("frmMain", "B", 0));
        label_3->setText(QApplication::translate("frmMain", "G", 0));
        label_4->setText(QApplication::translate("frmMain", "R", 0));
        label_5->setText(QApplication::translate("frmMain", "B", 0));
        label_6->setText(QApplication::translate("frmMain", "G", 0));
        label_7->setText(QApplication::translate("frmMain", "Light 1", 0));
        label_8->setText(QApplication::translate("frmMain", "Light 2", 0));
        label_9->setText(QApplication::translate("frmMain", "Sphere color", 0));
        label_10->setText(QApplication::translate("frmMain", "R", 0));
        label_11->setText(QApplication::translate("frmMain", "G", 0));
        label_12->setText(QApplication::translate("frmMain", "B", 0));
        pushButton_17->setText(QApplication::translate("frmMain", "on/off", 0));
        pushButton_18->setText(QApplication::translate("frmMain", "on/off", 0));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
