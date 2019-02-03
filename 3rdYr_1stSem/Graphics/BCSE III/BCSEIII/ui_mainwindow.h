/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *draw_dda;
    QRadioButton *draw_line;
    QRadioButton *midpoint_circle;
    QPushButton *set_point1;
    QRadioButton *draw_circle;
    QSpinBox *ellipse_a;
    QRadioButton *draw_ellipse;
    QPushButton *set_point2;
    QSpinBox *ellipse_b;
    QSpinBox *circle_radius;
    QCheckBox *enable_polygon;
    QPushButton *Draw;
    QWidget *tab_2;
    QRadioButton *fillPink;
    QRadioButton *fillGreen;
    QRadioButton *fillLYellow;
    QRadioButton *fillDYellow;
    QRadioButton *fillDBlue;
    QRadioButton *fillLBlue;
    QPushButton *floodFill;
    QPushButton *boundaryFill;
    QPushButton *scanLine;
    QWidget *tab_3;
    QSpinBox *translate_x;
    QSpinBox *translate_y;
    QPushButton *translate;
    QDoubleSpinBox *rotation;
    QPushButton *rotate;
    QPushButton *scale;
    QDoubleSpinBox *scale_x;
    QDoubleSpinBox *scale_y;
    QPushButton *reflection;
    QPushButton *shear;
    QDoubleSpinBox *shear_x;
    QDoubleSpinBox *shear_y;
    QWidget *tab_4;
    QPushButton *lineClip;
    QPushButton *polygonClip;
    QWidget *tab_5;
    QPushButton *Bezier;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(999, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QStringLiteral("mouse_movement"));
        mouse_movement->setGeometry(QRect(720, 70, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(720, 50, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QStringLiteral("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(720, 140, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(730, 120, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QStringLiteral("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QStringLiteral("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QStringLiteral("show_axes"));
        show_axes->setGeometry(QRect(720, 10, 91, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(740, 630, 101, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(870, 70, 75, 23));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(870, 110, 78, 26));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(730, 220, 301, 401));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        draw_dda = new QRadioButton(tab);
        draw_dda->setObjectName(QStringLiteral("draw_dda"));
        draw_dda->setGeometry(QRect(20, 10, 82, 17));
        draw_line = new QRadioButton(tab);
        draw_line->setObjectName(QStringLiteral("draw_line"));
        draw_line->setGeometry(QRect(20, 40, 131, 17));
        midpoint_circle = new QRadioButton(tab);
        midpoint_circle->setObjectName(QStringLiteral("midpoint_circle"));
        midpoint_circle->setGeometry(QRect(20, 150, 131, 17));
        set_point1 = new QPushButton(tab);
        set_point1->setObjectName(QStringLiteral("set_point1"));
        set_point1->setGeometry(QRect(170, 10, 81, 23));
        draw_circle = new QRadioButton(tab);
        draw_circle->setObjectName(QStringLiteral("draw_circle"));
        draw_circle->setGeometry(QRect(20, 120, 131, 17));
        ellipse_a = new QSpinBox(tab);
        ellipse_a->setObjectName(QStringLiteral("ellipse_a"));
        ellipse_a->setGeometry(QRect(100, 80, 78, 26));
        draw_ellipse = new QRadioButton(tab);
        draw_ellipse->setObjectName(QStringLiteral("draw_ellipse"));
        draw_ellipse->setGeometry(QRect(20, 80, 99, 26));
        set_point2 = new QPushButton(tab);
        set_point2->setObjectName(QStringLiteral("set_point2"));
        set_point2->setGeometry(QRect(170, 40, 81, 23));
        ellipse_b = new QSpinBox(tab);
        ellipse_b->setObjectName(QStringLiteral("ellipse_b"));
        ellipse_b->setGeometry(QRect(190, 80, 78, 26));
        circle_radius = new QSpinBox(tab);
        circle_radius->setObjectName(QStringLiteral("circle_radius"));
        circle_radius->setGeometry(QRect(170, 140, 78, 26));
        enable_polygon = new QCheckBox(tab);
        enable_polygon->setObjectName(QStringLiteral("enable_polygon"));
        enable_polygon->setGeometry(QRect(20, 180, 82, 26));
        Draw = new QPushButton(tab);
        Draw->setObjectName(QStringLiteral("Draw"));
        Draw->setGeometry(QRect(20, 230, 221, 51));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        fillPink = new QRadioButton(tab_2);
        fillPink->setObjectName(QStringLiteral("fillPink"));
        fillPink->setGeometry(QRect(10, 220, 99, 26));
        fillGreen = new QRadioButton(tab_2);
        fillGreen->setObjectName(QStringLiteral("fillGreen"));
        fillGreen->setGeometry(QRect(10, 190, 61, 26));
        fillLYellow = new QRadioButton(tab_2);
        fillLYellow->setObjectName(QStringLiteral("fillLYellow"));
        fillLYellow->setGeometry(QRect(80, 220, 81, 26));
        fillDYellow = new QRadioButton(tab_2);
        fillDYellow->setObjectName(QStringLiteral("fillDYellow"));
        fillDYellow->setGeometry(QRect(160, 220, 99, 26));
        fillDBlue = new QRadioButton(tab_2);
        fillDBlue->setObjectName(QStringLiteral("fillDBlue"));
        fillDBlue->setGeometry(QRect(160, 190, 99, 26));
        fillLBlue = new QRadioButton(tab_2);
        fillLBlue->setObjectName(QStringLiteral("fillLBlue"));
        fillLBlue->setGeometry(QRect(80, 190, 71, 26));
        floodFill = new QPushButton(tab_2);
        floodFill->setObjectName(QStringLiteral("floodFill"));
        floodFill->setGeometry(QRect(10, 30, 231, 32));
        boundaryFill = new QPushButton(tab_2);
        boundaryFill->setObjectName(QStringLiteral("boundaryFill"));
        boundaryFill->setGeometry(QRect(10, 80, 231, 32));
        scanLine = new QPushButton(tab_2);
        scanLine->setObjectName(QStringLiteral("scanLine"));
        scanLine->setGeometry(QRect(10, 130, 221, 32));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        translate_x = new QSpinBox(tab_3);
        translate_x->setObjectName(QStringLiteral("translate_x"));
        translate_x->setGeometry(QRect(140, 10, 89, 26));
        translate_x->setMinimum(-999);
        translate_x->setMaximum(999);
        translate_y = new QSpinBox(tab_3);
        translate_y->setObjectName(QStringLiteral("translate_y"));
        translate_y->setGeometry(QRect(140, 50, 89, 26));
        translate_y->setMinimum(-999);
        translate_y->setMaximum(999);
        translate = new QPushButton(tab_3);
        translate->setObjectName(QStringLiteral("translate"));
        translate->setGeometry(QRect(20, 10, 84, 32));
        rotation = new QDoubleSpinBox(tab_3);
        rotation->setObjectName(QStringLiteral("rotation"));
        rotation->setGeometry(QRect(140, 120, 107, 26));
        rotation->setMinimum(-999);
        rotation->setMaximum(999);
        rotate = new QPushButton(tab_3);
        rotate->setObjectName(QStringLiteral("rotate"));
        rotate->setGeometry(QRect(20, 120, 84, 32));
        scale = new QPushButton(tab_3);
        scale->setObjectName(QStringLiteral("scale"));
        scale->setGeometry(QRect(20, 170, 84, 32));
        scale_x = new QDoubleSpinBox(tab_3);
        scale_x->setObjectName(QStringLiteral("scale_x"));
        scale_x->setGeometry(QRect(140, 170, 96, 26));
        scale_y = new QDoubleSpinBox(tab_3);
        scale_y->setObjectName(QStringLiteral("scale_y"));
        scale_y->setGeometry(QRect(140, 210, 96, 26));
        reflection = new QPushButton(tab_3);
        reflection->setObjectName(QStringLiteral("reflection"));
        reflection->setGeometry(QRect(20, 330, 84, 32));
        shear = new QPushButton(tab_3);
        shear->setObjectName(QStringLiteral("shear"));
        shear->setGeometry(QRect(20, 260, 84, 32));
        shear_x = new QDoubleSpinBox(tab_3);
        shear_x->setObjectName(QStringLiteral("shear_x"));
        shear_x->setGeometry(QRect(140, 260, 99, 26));
        shear_x->setMinimum(-99.99);
        shear_y = new QDoubleSpinBox(tab_3);
        shear_y->setObjectName(QStringLiteral("shear_y"));
        shear_y->setGeometry(QRect(140, 300, 99, 26));
        shear_y->setMinimum(-99.99);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        lineClip = new QPushButton(tab_4);
        lineClip->setObjectName(QStringLiteral("lineClip"));
        lineClip->setGeometry(QRect(60, 20, 171, 32));
        polygonClip = new QPushButton(tab_4);
        polygonClip->setObjectName(QStringLiteral("polygonClip"));
        polygonClip->setGeometry(QRect(60, 70, 171, 32));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        Bezier = new QPushButton(tab_5);
        Bezier->setObjectName(QStringLiteral("Bezier"));
        Bezier->setGeometry(QRect(70, 30, 151, 32));
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "    Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        show_axes->setText(QApplication::translate("MainWindow", "Show Axes", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "RESET", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Show Grid", nullptr));
        draw_dda->setText(QApplication::translate("MainWindow", "DDA Line", nullptr));
        draw_line->setText(QApplication::translate("MainWindow", "Bresenham Line", nullptr));
        midpoint_circle->setText(QApplication::translate("MainWindow", "Mid-Point Circle", nullptr));
        set_point1->setText(QApplication::translate("MainWindow", "Set point 1", nullptr));
        draw_circle->setText(QApplication::translate("MainWindow", "Bresenham Circle", nullptr));
        draw_ellipse->setText(QApplication::translate("MainWindow", "Ellipse", nullptr));
        set_point2->setText(QApplication::translate("MainWindow", "Set point 2", nullptr));
        enable_polygon->setText(QApplication::translate("MainWindow", "Polygon", nullptr));
        Draw->setText(QApplication::translate("MainWindow", "Draw", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Drawing", nullptr));
        fillPink->setText(QApplication::translate("MainWindow", "Pink", nullptr));
        fillGreen->setText(QApplication::translate("MainWindow", "Green", nullptr));
        fillLYellow->setText(QApplication::translate("MainWindow", "L_Yellow", nullptr));
        fillDYellow->setText(QApplication::translate("MainWindow", "D_Yellow", nullptr));
        fillDBlue->setText(QApplication::translate("MainWindow", "D_Blue", nullptr));
        fillLBlue->setText(QApplication::translate("MainWindow", "L_Blue", nullptr));
        floodFill->setText(QApplication::translate("MainWindow", "FloodFill", nullptr));
        boundaryFill->setText(QApplication::translate("MainWindow", "BoundaryFill", nullptr));
        scanLine->setText(QApplication::translate("MainWindow", "ScanLine", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Filling", nullptr));
        translate->setText(QApplication::translate("MainWindow", "Translate", nullptr));
        rotate->setText(QApplication::translate("MainWindow", "Rotate", nullptr));
        scale->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        reflection->setText(QApplication::translate("MainWindow", "Reflection", nullptr));
        shear->setText(QApplication::translate("MainWindow", "Shear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Transformation", nullptr));
        lineClip->setText(QApplication::translate("MainWindow", "Cohen-Sutherland", nullptr));
        polygonClip->setText(QApplication::translate("MainWindow", "Sutherland-Hodgeman", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Clipping", nullptr));
        Bezier->setText(QApplication::translate("MainWindow", "Cubic Bezier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Curve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
