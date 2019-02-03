#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
//#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <QVector>
#include <QDebug>
#define PI 3.14159265358
//#define scale_factor 10

//MainWindow::scale_factor=1;
const int MAX_POINTS = 20;
qint32 MainWindow::scale_factor=1;
qint32 MainWindow::polygon=0;
static QImage img=QImage(700,700,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::point(int x,int y)
{

    img.setPixel(x,y,qRgb(0,255,0));
    //ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::showMousePosition(QPoint &pos)
{
    ui->mouse_movement->setText(" X : "+QString::number(pos.x()/scale_factor-700/(2*scale_factor))+", Y : "+QString::number(pos.y()/scale_factor-700/(2*scale_factor)));
}
void MainWindow::Mouse_Pressed()
{
    ui->mouse_pressed->setText(" X : "+QString::number(ui->frame->x/scale_factor-700/(2*scale_factor))+", Y : "+QString::number(ui->frame->y/scale_factor-700/(2*scale_factor)));
    for(int i=0;i<scale_factor;i++)
        for(int j=0;j<scale_factor;j++)
            point((ui->frame->x/scale_factor)*scale_factor+i,(ui->frame->y/scale_factor)*scale_factor+j);
    ui->x_axis->move(0,ui->frame->y);
    ui->y_axis->move(ui->frame->x,0);
    ui->frame->setPixmap(QPixmap::fromImage(img));
    if(polygon==1)
    {
        p2.setX(p1.x());
        p2.setY(p1.y());
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        if(ui->draw_dda->isChecked())
        {
            dda_line(p1,p2);
        }
        if(ui->draw_line->isChecked())
        {
            bresenham_line(p1,p2);
        }
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}

void MainWindow::on_show_axes_clicked()
{
    if(ui->show_axes->isChecked())
    {
        ui->x_axis->show();
        ui->y_axis->show();
    }
    else{
        ui->x_axis->hide();
        ui->y_axis->hide();
    }
}
void MainWindow::on_set_point1_clicked()
{
    //if(ui->draw_line->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
    //}
}

void MainWindow::on_set_point2_clicked()
{
    //if(ui->draw_line->isChecked()){
        p2.setX(ui->frame->x);
        p2.setY(ui->frame->y);
    //}
}

void MainWindow::on_Draw_clicked()
{
    //QPainter painter(&img);
    //QPen pen;
    //pen.setWidth(scale_factor);
    //pen.setColor(Qt::red);
    if(ui->draw_circle->isChecked())
    {
        int r0=ui->circle_radius->value();
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        //painter.setPen(pen);
        //painter.drawEllipse(p1,r0,r0);
        bresenham_circle(p1,r0);
    }
    if(ui->midpoint_circle->isChecked())
    {
        int r0=ui->circle_radius->value();
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        midPoint_circle(p1,r0);
    }
    if(ui->draw_ellipse->isChecked())
    {
        int a=ui->ellipse_a->value();
        int b=ui->ellipse_b->value();
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        ellipse_draw(p1,a,b);
    }
    if(ui->draw_line->isChecked())
    {
        //painter.setPen(Qt::red);
        //painter.drawLine(p1,p2);
        bresenham_line(p1,p2);
    }
    if(ui->draw_dda->isChecked())
    {
        dda_line(p1,p2);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
    start_vertex=QVector<QPoint>();
    end_vertex=QVector<QPoint>();
}

void MainWindow::on_pushButton_2_clicked()
{
    int i,j;
    int height = ui->frame->height();
    int width = ui->frame->width();
    QRgb qrgb_obj=qRgb(255,255,255);
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
            img.setPixel(i,j,qRgb(0,0,0));
    for(i=0;i<height;i+=scale_factor)
        for(j=0;j<width;j++)
            img.setPixel(i,j,qRgb(127,127,127));
    for(j=0;j<width;j+=scale_factor)
        for(i=0;i<height;i++)
            img.setPixel(i,j,qRgb(127,127,127));
    for(i=0;i<=height-scale_factor;i+=scale_factor)
        paint_pixel(i,width/2,qrgb_obj);
    for(j=0;j<=width-scale_factor;j+=scale_factor)
        paint_pixel(height/2,j,qrgb_obj);
    ui->frame->setPixmap(QPixmap::fromImage(img));
    //start_vertex=QVector<QPoint>();
    //end_vertex=QVector<QPoint>();
}

void MainWindow::paint_pixel(int x, int y, QRgb& qrgb_obj)
{
    int i,j;
    for(i=0; i<scale_factor; i++)
        for(j=0; j<scale_factor; j++)
            img.setPixel(i+x,j+y,qrgb_obj);
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    scale_factor=arg1>0?arg1:1;
    on_pushButton_2_clicked();
}

void MainWindow::bresenham_line(QPoint& p1, QPoint& p2)
{
    int x1=p1.x()/scale_factor;
    int y1=p1.y()/scale_factor;
    int x2=p2.x()/scale_factor;
    int y2=p2.y()/scale_factor;
    start_vertex.push_back(QPoint(int(p1.x()/scale_factor), int(p1.y()/scale_factor)));
    end_vertex.push_back(QPoint(int(p2.x()/scale_factor), int(p2.y()/scale_factor)));
    QRgb qrgb_obj=qRgb(0,255,255);

    int dx=x2-x1;
    int dy=y2-y1;
    int ddx=(dx>0)?1:-1;
    int ddy=(dy>0)?1:-1;
    dx=abs(dx);
    dy=abs(dy);

    if(abs(dx)>=abs(dy))
    {
         int p=(dy<<1)-dx;
         int y=y1;

         for(int x=x1; x!=x2+ddx; x+=ddx)
         {
             paint_pixel(x*scale_factor,y*scale_factor,qrgb_obj);
             if(p>=0)
             {
                 y+=ddy;
                 p-=(dx<<1);
             }
             p+=(dy<<1);
         }
    }
    else
    {

        int p=(dx<<1)-dy;
        int x=x1;

        for(int y=y1; y!=y2+ddy; y+=ddy)
        {
            paint_pixel(x*scale_factor,y*scale_factor,qrgb_obj);
            if(p>=0)
            {
                x+=ddx;
                p-=(dy<<1);
            }
            p+=(dx<<1);
        }
    }
}

void MainWindow::bresenham_circle(QPoint &p, int radius)
{
    QRgb qrgb_obj=qRgb(255,225,0);
    int xc=p.x()/scale_factor;
    int yc=p.y()/scale_factor;
    int pk = 3 - 2*radius;
    int x=0,y=radius;
    while(x <= y)
    {
        drawCircle(x,y,xc,yc,qrgb_obj);
        x++;
        pk = pk + (4*x) + 6;
        if(pk > 0)
        {
            pk = pk - (4*y) + 4;
            y--;
        }
    }
}

void MainWindow::drawCircle(int x, int y, int xc, int yc, QRgb& qrgb_obj)
{
    x=x*scale_factor;
    y=y*scale_factor;
    xc=xc*scale_factor;
    yc=yc*scale_factor;
    paint_pixel(x+xc,y+yc,qrgb_obj);
    paint_pixel(-x+xc,y+yc,qrgb_obj);
    paint_pixel(x+xc, -y+yc,qrgb_obj);
    paint_pixel(-x+xc, -y+yc, qrgb_obj);
    paint_pixel(y+xc, x+yc, qrgb_obj);
    paint_pixel(y+xc, -x+yc, qrgb_obj);
    paint_pixel(-y+xc, x+yc, qrgb_obj);
    paint_pixel(-y+xc, -x+yc, qrgb_obj);
}

void MainWindow::ellipse_draw(QPoint& P, int a, int b)
{
    QRgb qrgb_obj=qRgb(255,0,255);
    int xc=P.x()/scale_factor;
    int yc=P.y()/scale_factor;
    double p=b*b-a*a*b+a*a/4;
    int x=0,y=b;
    while(2.0*b*b*x <= 2.0*a*a*y)       //Region 1
    {
        drawEllipse(x,y,xc,yc,qrgb_obj);
        if(p < 0)
        {
            x++;
            p = p+2*b*b*x+b*b;
        }
        else
        {
            x++;y--;
            p = p+2*b*b*x-2*a*a*y-b*b;
        }
    }

    p=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y >= 0)                        //Region 2
    {
        drawEllipse(x,y,xc,yc,qrgb_obj);
        if(p <= 0)
        {
            x++;y--;
            p = p+2*b*b*x-2*a*a*y+a*a;
        }
        else
        {
            y--;
            p = p-2*a*a*y+a*a;
        }
    }
}

void MainWindow::drawEllipse(int x, int y, int xc, int yc, QRgb& qrgb_obj)
{
    x=x*scale_factor;
    y=y*scale_factor;
    xc=xc*scale_factor;
    yc=yc*scale_factor;
    paint_pixel(xc+x,yc+y,qrgb_obj);
    paint_pixel(xc+x,yc-y,qrgb_obj);
    paint_pixel(xc-x,yc+y,qrgb_obj);
    paint_pixel(xc-x,yc-y,qrgb_obj);
}

void MainWindow::dda_line(QPoint& p1, QPoint& p2)
{
    int x1=p1.x()/scale_factor;
    int y1=p1.y()/scale_factor;
    int x2=p2.x()/scale_factor;
    int y2=p2.y()/scale_factor;
    start_vertex.push_back(QPoint(int(p1.x()/scale_factor), int(p1.y()/scale_factor)));
    end_vertex.push_back(QPoint(int(p2.x()/scale_factor), int(p2.y()/scale_factor)));

    QRgb qrgb_obj=qRgb(70,128,200);
    int dy=y2-y1;
    int dx=x2-x1;
    int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    double x_inc=1.0*dx/steps;
    double y_inc=1.0*dy/steps;
    double x=x1*scale_factor;
    double y=y1*scale_factor;
    for(int i=0; i<=steps; i++)
    {
        paint_pixel((int(x/scale_factor)*scale_factor),(int(y/scale_factor)*scale_factor),qrgb_obj);
        x=x+x_inc*scale_factor;
        y=y+y_inc*scale_factor;
    }
}

void MainWindow::midPoint_circle(QPoint &p, int radius)
{
    QRgb qrgb_obj=qRgb(128,128,0);
    int xc=p.x()/scale_factor;
    int yc=p.y()/scale_factor;

    int x=radius,y=0;
    int P=1-radius;
    while(x>=y)
    {
        drawCircle(x, y, xc, yc, qrgb_obj);
        y++;
        if(P<0)
            P=P+2*y+1;
        else
        {
            x--;
            P=P+2*y-2*x+1;
        }
        if(x<y)
            break;
    }
}


void MainWindow::on_enable_polygon_toggled(bool checked)
{
    if(checked==true)
    {
        polygon=1;
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
    }
    else
        polygon=0;
}

void MainWindow::on_floodFill_clicked()
{
    QRgb qrgb_obj=qRgb(150,200,100);
    floodFill(ui->frame->x/scale_factor, ui->frame->y/scale_factor, qrgb_obj);
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::floodFill(int x,int y, QRgb& qrgb_obj)
{
    //QColor clrCurrent( img.pixel( x*scale_factor+1, y*scale_factor+1 ) );
    if(x*scale_factor>=ui->frame->height() || x*scale_factor<0 || y*scale_factor>=ui->frame->width() || y*scale_factor<0)
        return;
    QRgb pixColor = img.pixel(x*scale_factor, y*scale_factor);
    if((qRed(pixColor)==0 && qGreen(pixColor)==255 && qBlue(pixColor)==0) || (qRed(pixColor)==255 && qGreen(pixColor)==255 && qBlue(pixColor)==255) || (qRed(pixColor)==127 && qGreen(pixColor)==127 && qBlue(pixColor)==127))
    {
        paint_pixel(x*scale_factor,y*scale_factor,qrgb_obj);
        floodFill(x+1,y,qrgb_obj);
        floodFill(x,y+1,qrgb_obj);
        floodFill(x-1,y,qrgb_obj);
        floodFill(x,y-1,qrgb_obj);
    }
}

void MainWindow::boundaryFill(int x, int y, QRgb& qrgb_obj, QRgb& replace_rgb)
{
    if(x*scale_factor>=ui->frame->height() || x*scale_factor<0 || y*scale_factor>=ui->frame->width() || y*scale_factor<0)
        return;
    QRgb pixColor = img.pixel(x*scale_factor, y*scale_factor);
    if(qRed(pixColor)==qRed(replace_rgb) && qGreen(pixColor)==qGreen(replace_rgb) && qBlue(pixColor)==qBlue(replace_rgb))
        return;
    else if(qRed(pixColor)==qRed(qrgb_obj) && qGreen(pixColor)==qGreen(qrgb_obj) && qBlue(pixColor)==qBlue(qrgb_obj))
        return;
    else
    {
        paint_pixel(x*scale_factor,y*scale_factor,qrgb_obj);
        boundaryFill(x+1,y,qrgb_obj,replace_rgb);
        boundaryFill(x,y+1,qrgb_obj,replace_rgb);
        boundaryFill(x-1,y,qrgb_obj,replace_rgb);
        boundaryFill(x,y-1,qrgb_obj,replace_rgb);
    }
}


void MainWindow::on_boundaryFill_clicked()
{
    QRgb replace_rgb;
    if(ui->fillGreen->isChecked())
        replace_rgb=qRgb(0,255,0);
    else if(ui->fillLBlue->isChecked())
        replace_rgb=qRgb(0,255,255);
    else if(ui->fillDBlue->isChecked())
        replace_rgb=qRgb(70,128,200);
    else if(ui->fillPink->isChecked())
        replace_rgb=qRgb(255,0,255);
    else if(ui->fillLYellow->isChecked())
        replace_rgb=qRgb(255,225,0);
    else if(ui->fillDYellow->isChecked())
        replace_rgb=qRgb(128,128,0);
    else
        return;
    QRgb qrgb_obj=qRgb(200,100,78);
    boundaryFill(ui->frame->x/scale_factor, ui->frame->y/scale_factor, qrgb_obj, replace_rgb);
    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_scanLine_clicked()
{
    QRgb qrgb_obj=qRgb(83,126,64);
    int x;
    for(int i=0; i<ui->frame->width()/scale_factor; i++)
    {
        x=-1;
        for(int j=0; j<ui->frame->height()/scale_factor; j++)
        {
            QRgb pixColor = img.pixel(j*scale_factor, i*scale_factor);
            if(!((qRed(pixColor)==255 && qGreen(pixColor)==255 && qBlue(pixColor)==255) || (qRed(pixColor)==127 && qGreen(pixColor)==127 && qBlue(pixColor)==127)))
            {
                if(x==-1)
                {
                    x=j;
                }
                else if(x==j-1)
                {
                    x=j;
                }
                else
                {
                    if(checkLeak(x,j,i))
                    {
                        paintLines(x,j,i,qrgb_obj);
                        x=-1;
                    }
                    else
                        x=j;
                }
            }
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}
int MainWindow::checkLeak(int x1, int x2, int col)
{
    int flag,x,j;
    QRgb pixColor;
    for(x=x1+1; x<x2; x++)
    {
        flag=0;
        pixColor = img.pixel(x*scale_factor, (col-1)*scale_factor);
        if((qRed(pixColor)==255 && qGreen(pixColor)==255 && qBlue(pixColor)==255) || (qRed(pixColor)==127 && qGreen(pixColor)==127 && qBlue(pixColor)==127))
            return 0;
        for(j=col+1; j<ui->frame->height()/scale_factor; j++)
        {
            pixColor = img.pixel(x*scale_factor, j*scale_factor);
            if(!((qRed(pixColor)==255 && qGreen(pixColor)==255 && qBlue(pixColor)==255) || (qRed(pixColor)==127 && qGreen(pixColor)==127 && qBlue(pixColor)==127)))
            {
                flag++;
                break;
            }
        }
        if(flag==0)
            return 0;
        //while(j+1<ui->frame->height())
        //{
         //    if()
        //}
    }

    return 1;

}
/*
int MainWindow::fillRecursive(int x1, int x2, int col, QRgb& qrgb_obj)
{
   if(col==)
}
*/
void MainWindow::paintLines(int x1, int x2, int col, QRgb& qrgb_obj)
{
    for(int x=x1+1; x<x2; x++)
    {
            paint_pixel(x*scale_factor, col*scale_factor, qrgb_obj);
    }
}

void MainWindow::on_translate_clicked()
{
    int dx = ui->translate_x->value();
    int dy = ui->translate_y->value();
    int width = ui->frame->width()/scale_factor;
    int height = ui->frame->height()/scale_factor;
    int x,y;
    QRgb arr[width][height];
    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++)
        {
            x=i-dx;
            y=j-dy;
            if(x<0)
                x+=width;
            if(y<0)
                y+=height;
            x%=width;
            y%=height;
            arr[i][j]=img.pixel(x*scale_factor, y*scale_factor);
        }
    on_pushButton_2_clicked();

    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++)
            if(!((qRed(arr[i][j])==255 && qGreen(arr[i][j])==255 && qBlue(arr[i][j])==255) || (qRed(arr[i][j])==127 && qGreen(arr[i][j])==127 && qBlue(arr[i][j])==127)))
                paint_pixel(i*scale_factor, j*scale_factor, arr[i][j]);

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_rotate_clicked()
{
    int curr_x=ui->frame->x/scale_factor;
    int curr_y=ui->frame->y/scale_factor;
    int width = ui->frame->width()/scale_factor;
    int height = ui->frame->height()/scale_factor;
    int x,y,temp_x,temp_y;
    double degree=ui->rotation->value();
    //curr_x=curr_y=0;
    QRgb arr[width][height];
    int visited[height][width];
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            visited[i][j]=0;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            x=i-curr_x;
            y=j-curr_y;
            //double temp_x=curr_x*cos(PI*degree/180)-curr_y*sin(PI*degree/180);
            //double temp_y=curr_x*sin(degree*PI/180)+curr_y*cos(degree*PI/180);
            temp_x=x*cos(PI*degree/180.0)-y*sin(PI*degree/180.0)+curr_x;
            temp_y=x*sin(degree*PI/180.0)+y*cos(degree*PI/180.0)+curr_y;
            x=temp_x;
            y=temp_y;
            /*
            while(x<0)
                x+=width;
            while(y<0)
                y+=height;
            x%=(width);
            y%=(height);
            */
            if(x>=0 && x<height && y>=0 && y<width)
            {
                arr[i][j]=img.pixel(x*scale_factor, y*scale_factor);
                visited[i][j]=1;
            }
        }
    on_pushButton_2_clicked();
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            if(visited[i][j] && !((qRed(arr[i][j])==255 && qGreen(arr[i][j])==255 && qBlue(arr[i][j])==255) || (qRed(arr[i][j])==127 && qGreen(arr[i][j])==127 && qBlue(arr[i][j])==127)))
                paint_pixel(i*scale_factor, j*scale_factor, arr[i][j]);

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_scale_clicked()
{
    int width = ui->frame->width();
    int height = ui->frame->height();
    int x_cent=height/(2*scale_factor);
    int y_cent=width/(2*scale_factor);
    double s_x=ui->scale_x->value();
    double s_y=ui->scale_y->value();
    s_x=(s_x)>0?s_x:1;
    s_y=(s_y)>0?s_y:1;
    int x,y;
    QRgb arr[height/scale_factor][width/scale_factor];
    int visited[height/scale_factor][width/scale_factor];
    for(int i=0; i<height/scale_factor; i++)
        for(int j=0; j<width/scale_factor; j++)
            visited[i][j]=0;
    for(int i=0; i<height/scale_factor; i++)
        for(int j=0; j<width/scale_factor; j++)
        {
            x=i-x_cent;
            y=j-y_cent;
            x=int(x/s_x-0.5);
            y=int(y/s_y-0.5);
            x+=x_cent;
            y+=y_cent;
            if(x>=0 && x<height/scale_factor && y>=0 && y<width/scale_factor)
            {
                arr[i][j]=img.pixel(x*scale_factor, y*scale_factor);
                visited[i][j]=1;
            }
        }
    on_pushButton_2_clicked();
    for(int i=0; i<height/scale_factor; i++)
        for(int j=0; j<width/scale_factor; j++)
            if(visited[i][j] && !((qRed(arr[i][j])==255 && qGreen(arr[i][j])==255 && qBlue(arr[i][j])==255) || (qRed(arr[i][j])==127 && qGreen(arr[i][j])==127 && qBlue(arr[i][j])==127)))
                paint_pixel(i*scale_factor, j*scale_factor, arr[i][j]);

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_reflection_clicked()
{
    int x1=p1.x()/scale_factor;
    int y1=p1.y()/scale_factor;
    int x2=p2.x()/scale_factor;
    int y2=p2.y()/scale_factor;
    /*
    int dx=1,dy=1;
    QRgb qrgb_line=qRgb(50,50,50);
    if(x1>x2)
        dx=-1;
    if(y1>y2)
        dy=-1;
    for(int i=x1;i!=x2+dx;i+=dx)
        for(int j=y1;j!=y2+dy;j+=dy)
            paint_pixel(i*scale_factor, j*scale_factor, qrgb_line);


    float a=(y1-y2)/(float)(x1*y2-y1*x2);
    float b=(y1-y2)/(float)(x1*y2-y1*x2);
    */
    float dx=float(x1-x2);
    float dy=float(y1-y2);
    float a=(dx*dx-dy*dy)/(dx*dx+dy*dy);
    float b=2*dx*dy/(dx*dx+dy*dy);
    int curr_x=ui->frame->x/scale_factor;
    int curr_y=ui->frame->y/scale_factor;
    int width = ui->frame->width()/scale_factor;
    int height = ui->frame->height()/scale_factor;
    int x,y,temp_x,temp_y;
    curr_x=curr_y=0;
    QRgb arr[width][height];
    int visited[height][width];
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            visited[i][j]=0;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            x=i-curr_x;
            y=j-curr_y;

            temp_x=int(a*(x-x1) + b*(y-y1) + x1);
            temp_y=int(b*(x-x1) - a*(y-y1) + y1);

            x=temp_x+curr_x;
            y=temp_y+curr_y;

            if(x<0)
                x+=width;
            if(y<0)
                y+=height;
            x%=width;
            y%=height;
            if(x>=0 && x<height && y>=0 && y<width)
            {
                arr[i][j]=img.pixel(x*scale_factor, y*scale_factor);
                visited[i][j]=1;
            }
        }

    on_pushButton_2_clicked();
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            if(visited[i][j] && !((qRed(arr[i][j])==255 && qGreen(arr[i][j])==255 && qBlue(arr[i][j])==255) || (qRed(arr[i][j])==127 && qGreen(arr[i][j])==127 && qBlue(arr[i][j])==127)))
                paint_pixel(i*scale_factor, j*scale_factor, arr[i][j]);

    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_shear_clicked()
{
    int curr_x=ui->frame->x/scale_factor;
    int curr_y=ui->frame->y/scale_factor;
    int width = ui->frame->width()/scale_factor;
    int height = ui->frame->height()/scale_factor;
    int x,y,temp_x,temp_y;
    double shear_x=ui->shear_x->value();
    double shear_y=ui->shear_y->value();
    //curr_x=curr_y=0;
    QRgb arr[width][height];
    int visited[height][width];
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            visited[i][j]=0;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            x=i-curr_x;
            y=j-curr_y;
            temp_x=x+int(y*shear_y);
            temp_y=y+int(x*shear_x);
            x=temp_x+curr_x;
            y=temp_y+curr_y;

            if(x<0)
                x+=width;
            if(y<0)
                y+=height;
            x%=width;
            y%=height;
            if(x>=0 && x<height && y>=0 && y<width)
            {
                arr[i][j]=img.pixel(x*scale_factor, y*scale_factor);
                visited[i][j]=1;
            }
        }
    on_pushButton_2_clicked();
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            if(visited[i][j] && !((qRed(arr[i][j])==255 && qGreen(arr[i][j])==255 && qBlue(arr[i][j])==255) || (qRed(arr[i][j])==127 && qGreen(arr[i][j])==127 && qBlue(arr[i][j])==127)))
                paint_pixel(i*scale_factor, j*scale_factor, arr[i][j]);

    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_lineClip_clicked()
{
    on_pushButton_2_clicked();
    int len=start_vertex.size();
    QVector<int> code1;
    QVector<int> code2;
    int code;

    int x_min=p1.x()/scale_factor;
    int x_max=p2.x()/scale_factor;
    int y_min=p1.y()/scale_factor;
    int y_max=p2.y()/scale_factor;
    int temp;
    if(x_min>x_max)
    {
        temp=x_min;
        x_min=x_max;
        x_max=temp;
    }
    if(y_min>y_max)
    {
        temp=y_min;
        y_min=y_max;
        y_max=temp;
    }

    int INSIDE = 0; // 0000
    int LEFT = 1;   // 0001
    int RIGHT = 2;  // 0010
    int BOTTOM = 4; // 0100
    int TOP = 8;    // 1000

    int i,x,y;
    for(i=0; i<len; i++)
    {
        x=start_vertex[i].x();
        y=start_vertex[i].y();
        code=INSIDE;
        if (x < x_min)       // to the left of rectangle
           code |= LEFT;
        else if (x > x_max)  // to the right of rectangle
           code |= RIGHT;
        if (y < y_min)       // below the rectangle
           code |= BOTTOM;
        else if (y > y_max)  // above the rectangle
           code |= TOP;
        code1.push_back(code);

        x=end_vertex[i].x();
        y=end_vertex[i].y();
        code=INSIDE;
        if (x < x_min)       // to the left of rectangle
           code |= LEFT;
        else if (x > x_max)  // to the right of rectangle
           code |= RIGHT;
        if (y < y_min)       // below the rectangle
           code |= BOTTOM;
        else if (y > y_max)  // above the rectangle
           code |= TOP;
        code2.push_back(code);
    }

    int first_code,second_code,x1,y1,x2,y2;
    bool accept;
    for(i=0; i<len; i++)
    {
        x1=start_vertex[i].x();
        y1=start_vertex[i].y();
        x2=end_vertex[i].x();
        y2=end_vertex[i].y();
        first_code=code1[i];
        second_code=code2[i];
        accept=false;

        while(true)
        {
            if(first_code==0 && second_code==0)
            {
                accept=true;
                break;
            }
            else if(first_code & second_code)
            {
                break;
            }
            else
            {
                int code_out;
                double x,y;
                if(first_code!=0)
                    code_out=first_code;
                else
                    code_out=second_code;
                // Find intersection point;
                // using formulas y = y1 + slope * (x - x1),
                // x = x1 + (1 / slope) * (y - y1)
                if (code_out & TOP)
                {
                     // point is above the clip rectangle
                     x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                     y = y_max;
                }
                else if (code_out & BOTTOM)
                {
                     // point is below the rectangle
                     x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                     y = y_min;
                }
                else if (code_out & RIGHT)
                {
                     // point is to the right of rectangle
                     y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                     x = x_max;
                }
                else if (code_out & LEFT)
                {
                     // point is to the left of rectangle
                     y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                     x = x_min;
                }

                // Now intersection point x,y is found
                // We replace point outside rectangle
                // by intersection point
                if (code_out == first_code)
                {
                     x1 = int(x);
                     y1 = int(y);
                     //first_code = computeCode(x1, y1);
                     code=INSIDE;
                     if (x1 < x_min)       // to the left of rectangle
                        code |= LEFT;
                     else if (x1 > x_max)  // to the right of rectangle
                        code |= RIGHT;
                     if (y1 < y_min)       // below the rectangle
                        code |= BOTTOM;
                     else if (y1 > y_max)  // above the rectangle
                        code |= TOP;
                     first_code=code;
                }
                else
                {
                     x2 = int(x);
                     y2 = int(y);
                     //second_code = computeCode(x1, y1);
                     code=INSIDE;
                     if (x2 < x_min)       // to the left of rectangle
                        code |= LEFT;
                     else if (x2 > x_max)  // to the right of rectangle
                        code |= RIGHT;
                     if (y2 < y_min)       // below the rectangle
                        code |= BOTTOM;
                     else if (y2 > y_max)  // above the rectangle
                        code |= TOP;
                     second_code=code;
                }
            }
        }
        if (accept)
            {
                QPoint a=QPoint(x1*scale_factor,y1*scale_factor);
                QPoint b=QPoint(x2*scale_factor,y2*scale_factor);
                if(ui->draw_dda->isChecked())
                    dda_line(a,b);
                else
                    bresenham_line(a,b);
            }
        else
        {
            /*
            start_vertex.erase(start_vertex.begin()+i);
            end_vertex.erase(end_vertex.begin()+i);
            code1.erase(code1.begin()+i);
            code2.erase(code2.begin()+i);
            i--;
            len--;
            */
        }
    }
    /*
    QPoint first_pt;
    QPoint second_pt;
    for(i=0; i<len; i++)
    {
        first_pt=QPoint(start_vertex[i].x()*scale_factor,start_vertex[i].y()*scale_factor);
        second_pt=QPoint(end_vertex[i].x()*scale_factor,end_vertex[i].y()*scale_factor);
        bresenham_line(first_pt,second_pt);
    }
    */
    QPoint temporary1,temporary2;
    if(ui->draw_dda->isChecked())
    {
        temporary1=QPoint(p1.x(),p1.y());
        temporary2=QPoint(p1.x(),p2.y());
        bresenham_line(temporary1,temporary2);
        temporary1=QPoint(p2.x(),p1.y());
        temporary2=QPoint(p2.x(),p2.y());
        bresenham_line(temporary1,temporary2);
        temporary1=QPoint(p1.x(),p1.y());
        temporary2=QPoint(p2.x(),p1.y());
        bresenham_line(temporary1,temporary2);
        temporary1=QPoint(p1.x(),p2.y());
        temporary2=QPoint(p2.x(),p2.y());
        bresenham_line(temporary1,temporary2);
    }
    else
    {
        temporary1=QPoint(p1.x(),p1.y());
        temporary2=QPoint(p1.x(),p2.y());
        dda_line(temporary1,temporary2);
        temporary1=QPoint(p2.x(),p1.y());
        temporary2=QPoint(p2.x(),p2.y());
        dda_line(temporary1,temporary2);
        temporary1=QPoint(p1.x(),p1.y());
        temporary2=QPoint(p2.x(),p1.y());
        dda_line(temporary1,temporary2);
        temporary1=QPoint(p1.x(),p2.y());
        temporary2=QPoint(p2.x(),p2.y());
        dda_line(temporary1,temporary2);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_polygonClip_clicked()
{
    on_pushButton_2_clicked();
    int poly_points[start_vertex.size()][2];
    int poly_size=start_vertex.size();
    int x_min=p1.x()/scale_factor;
    int x_max=p2.x()/scale_factor;
    int y_min=p1.y()/scale_factor;
    int y_max=p2.y()/scale_factor;
    int temp,i;
    if(x_min>x_max)
    {
        temp=x_min;
        x_min=x_max;
        x_max=temp;
    }
    if(y_min>y_max)
    {
        temp=y_min;
        y_min=y_max;
        y_max=temp;
    }

    int clipper_points[][2] = {{x_min,y_min}, {x_min,y_max},
                                  {x_max,y_max}, {x_max,y_min} };
    int clipper_size=4;
    for(i=0; i<poly_size; i++)
    {
        poly_points[i][0]=start_vertex[i].x();
        poly_points[i][1]=start_vertex[i].y();
    }
    QPoint temporary1,temporary2;
    if(ui->draw_dda->isChecked())
    {
        temporary1=QPoint(p1.x(),p1.y());
        temporary2=QPoint(p1.x(),p2.y());
        bresenham_line(temporary1,temporary2);
        temporary1=QPoint(p2.x(),p1.y());
        temporary2=QPoint(p2.x(),p2.y());
        bresenham_line(temporary1,temporary2);
        temporary1=QPoint(p1.x(),p1.y());
        temporary2=QPoint(p2.x(),p1.y());
        bresenham_line(temporary1,temporary2);
        temporary1=QPoint(p1.x(),p2.y());
        temporary2=QPoint(p2.x(),p2.y());
        bresenham_line(temporary1,temporary2);
    }
    else
    {
        temporary1=QPoint(p1.x(),p1.y());
        temporary2=QPoint(p1.x(),p2.y());
        dda_line(temporary1,temporary2);
        temporary1=QPoint(p2.x(),p1.y());
        temporary2=QPoint(p2.x(),p2.y());
        dda_line(temporary1,temporary2);
        temporary1=QPoint(p1.x(),p1.y());
        temporary2=QPoint(p2.x(),p1.y());
        dda_line(temporary1,temporary2);
        temporary1=QPoint(p1.x(),p2.y());
        temporary2=QPoint(p2.x(),p2.y());
        dda_line(temporary1,temporary2);
    }
    suthHodgClip(poly_points, poly_size, clipper_points, clipper_size);

    ui->frame->setPixmap(QPixmap::fromImage(img));
}


// Returns x-value of point of intersectipn of two
// lines
int MainWindow::x_intersect(int x1, int y1, int x2, int y2,
                int x3, int y3, int x4, int y4)
{
    int num = (x1*y2 - y1*x2) * (x3-x4) -
              (x1-x2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    return num/den;
}

// Returns y-value of point of intersectipn of
// two lines
int MainWindow::y_intersect(int x1, int y1, int x2, int y2,
                int x3, int y3, int x4, int y4)
{
    int num = (x1*y2 - y1*x2) * (y3-y4) -
              (y1-y2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    return num/den;
}

// This functions clips all the edges w.r.t one clip
// edge of clipping area
void MainWindow::clip(int poly_points[][2], int &poly_size,
          int x1, int y1, int x2, int y2)
{
    int new_points[MAX_POINTS][2], new_poly_size = 0;

    // (ix,iy),(kx,ky) are the co-ordinate values of
    // the points
    for (int i = 0; i < poly_size; i++)
    {
        // i and k form a line in polygon
        int k = (i+1) % poly_size;
        int ix = poly_points[i][0], iy = poly_points[i][1];
        int kx = poly_points[k][0], ky = poly_points[k][1];

        // Calculating position of first point
        // w.r.t. clipper line
        int i_pos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1);

        // Calculating position of second point
        // w.r.t. clipper line
        int k_pos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1);

        // Case 1 : When both points are inside
        if (i_pos < 0  && k_pos < 0)
        {
            //Only second point is added
            new_points[new_poly_size][0] = kx;
            new_points[new_poly_size][1] = ky;
            new_poly_size++;
        }

        // Case 2: When only first point is outside
        else if (i_pos >= 0  && k_pos < 0)
        {
            // Point of intersection with edge
            // and the second point is added
            new_points[new_poly_size][0] = x_intersect(x1,
                              y1, x2, y2, ix, iy, kx, ky);
            new_points[new_poly_size][1] = y_intersect(x1,
                              y1, x2, y2, ix, iy, kx, ky);
            new_poly_size++;

            new_points[new_poly_size][0] = kx;
            new_points[new_poly_size][1] = ky;
            new_poly_size++;
        }

        // Case 3: When only second point is outside
        else if (i_pos < 0  && k_pos >= 0)
        {
            //Only point of intersection with edge is added
            new_points[new_poly_size][0] = x_intersect(x1,
                              y1, x2, y2, ix, iy, kx, ky);
            new_points[new_poly_size][1] = y_intersect(x1,
                              y1, x2, y2, ix, iy, kx, ky);
            new_poly_size++;
        }

        // Case 4: When both points are outside
        else
        {
            //No points are added
        }
    }

    // Copying new points into original array
    // and changing the no. of vertices
    poly_size = new_poly_size;
    for (int i = 0; i < poly_size; i++)
    {
        poly_points[i][0] = new_points[i][0];
        poly_points[i][1] = new_points[i][1];
    }
}

// Implements Sutherland–Hodgman algorithm
void MainWindow::suthHodgClip(int poly_points[][2], int poly_size,
                  int clipper_points[][2], int clipper_size)
{
    //i and k are two consecutive indexes
    for (int i=0; i<clipper_size; i++)
    {
        int k = (i+1) % clipper_size;

        // We pass the current array of vertices, it's size
        // and the end points of the selected clipper line
        clip(poly_points, poly_size, clipper_points[i][0],
             clipper_points[i][1], clipper_points[k][0],
             clipper_points[k][1]);
    }
    for(int i=0; i<=poly_size; i++)
    {
        QPoint a=QPoint(poly_points[i%poly_size][0]*scale_factor,poly_points[i%poly_size][1]*scale_factor);
        QPoint b=QPoint(poly_points[(i+1)%poly_size][0]*scale_factor,poly_points[(i+1)%poly_size][1]*scale_factor);
        if(ui->draw_dda->isChecked())
            dda_line(a,b);
        else
            bresenham_line(a,b);
    }
}

void MainWindow::on_Bezier_clicked()
{
    QRgb qrgb_obj=qRgb(240,128,200);
    qDebug()<<start_vertex[0].x()<<" "<<start_vertex[0].y();
    int xc=ui->frame->width()/(2*scale_factor);
    int yc=ui->frame->height()/(2*scale_factor);
    double xu = 0.0 , yu = 0.0 , u = 0.0 ;
    for(u = 0.0 ; u <= 1.0 ; u += 0.0001)
    {
        xu = pow(1-u,3)*(end_vertex[0].x()-xc)+3*u*pow(1-u,2)*(end_vertex[1].x()-xc)+3*pow(u,2)*(1-u)*(end_vertex[2].x()-xc)+pow(u,3)*(start_vertex[2].x()-xc)+xc;
        yu = pow(1-u,3)*(end_vertex[0].y()-yc)+3*u*pow(1-u,2)*(end_vertex[1].y()-yc)+3*pow(u,2)*(1-u)*(end_vertex[2].y()-yc)+pow(u,3)*(start_vertex[2].y()-yc)+yc;
        paint_pixel(int(xu)*scale_factor, int(yu)*scale_factor, qrgb_obj) ;
    }

    ui->frame->setPixmap(QPixmap::fromImage(img));
}
