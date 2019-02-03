#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
    void paint_pixel(int x, int y, QRgb &qrgb_obj);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static int scale_factor;
    static int polygon;

private slots:
    void on_show_axes_clicked();

    void on_Draw_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_spinBox_valueChanged(int arg1);

    void bresenham_line(QPoint &p1, QPoint &p2);

    void bresenham_circle(QPoint &p, int radius);

    void drawCircle(int x, int y, int xc, int yc, QRgb& qrgb_obj);

    void ellipse_draw(QPoint& p, int a, int b);

    void drawEllipse(int x, int y, int xc, int yc, QRgb& qrgb_obj);

    void dda_line(QPoint &p1, QPoint &p2);

    void midPoint_circle(QPoint &p, int radius);

    void on_enable_polygon_toggled(bool checked);

    void on_floodFill_clicked();

    void floodFill(int x,int y,QRgb& qrgb_obj);

    void on_boundaryFill_clicked();

    void boundaryFill(int x, int y, QRgb& qrgb_obj, QRgb& replace_rgb);

    void on_scanLine_clicked();

    int checkLeak(int x1, int x2, int col);

    void paintLines(int x1, int x2, int col, QRgb& qrgb_obj);

    void on_translate_clicked();

    void on_rotate_clicked();

    void on_scale_clicked();

    void on_reflection_clicked();

    void on_shear_clicked();

    void on_lineClip_clicked();

    void on_polygonClip_clicked();

    void suthHodgClip(int poly_points[][2], int poly_size, int clipper_points[][2], int clipper_size);

    int x_intersect(int x1, int y1, int x2, int y2,
                    int x3, int y3, int x4, int y4);

    int y_intersect(int x1, int y1, int x2, int y2,
                    int x3, int y3, int x4, int y4);

    void clip(int poly_points[][2], int &poly_size,
              int x1, int y1, int x2, int y2);


    void on_Bezier_clicked();

private:
    QVector<QPoint> start_vertex;
    QVector<QPoint> end_vertex;
    Ui::MainWindow *ui;
    QPoint p1,p2;
    void point(int,int);
};

#endif // MAINWINDOW_H
