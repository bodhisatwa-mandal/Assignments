/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[71];
    char stringdata0[806];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "Mouse_Pressed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "showMousePosition"
QT_MOC_LITERAL(4, 44, 7), // "QPoint&"
QT_MOC_LITERAL(5, 52, 3), // "pos"
QT_MOC_LITERAL(6, 56, 11), // "paint_pixel"
QT_MOC_LITERAL(7, 68, 1), // "x"
QT_MOC_LITERAL(8, 70, 1), // "y"
QT_MOC_LITERAL(9, 72, 5), // "QRgb&"
QT_MOC_LITERAL(10, 78, 8), // "qrgb_obj"
QT_MOC_LITERAL(11, 87, 20), // "on_show_axes_clicked"
QT_MOC_LITERAL(12, 108, 15), // "on_Draw_clicked"
QT_MOC_LITERAL(13, 124, 21), // "on_set_point1_clicked"
QT_MOC_LITERAL(14, 146, 21), // "on_set_point2_clicked"
QT_MOC_LITERAL(15, 168, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(16, 190, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(17, 214, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(18, 238, 4), // "arg1"
QT_MOC_LITERAL(19, 243, 14), // "bresenham_line"
QT_MOC_LITERAL(20, 258, 2), // "p1"
QT_MOC_LITERAL(21, 261, 2), // "p2"
QT_MOC_LITERAL(22, 264, 16), // "bresenham_circle"
QT_MOC_LITERAL(23, 281, 1), // "p"
QT_MOC_LITERAL(24, 283, 6), // "radius"
QT_MOC_LITERAL(25, 290, 10), // "drawCircle"
QT_MOC_LITERAL(26, 301, 2), // "xc"
QT_MOC_LITERAL(27, 304, 2), // "yc"
QT_MOC_LITERAL(28, 307, 12), // "ellipse_draw"
QT_MOC_LITERAL(29, 320, 1), // "a"
QT_MOC_LITERAL(30, 322, 1), // "b"
QT_MOC_LITERAL(31, 324, 11), // "drawEllipse"
QT_MOC_LITERAL(32, 336, 8), // "dda_line"
QT_MOC_LITERAL(33, 345, 15), // "midPoint_circle"
QT_MOC_LITERAL(34, 361, 25), // "on_enable_polygon_toggled"
QT_MOC_LITERAL(35, 387, 7), // "checked"
QT_MOC_LITERAL(36, 395, 20), // "on_floodFill_clicked"
QT_MOC_LITERAL(37, 416, 9), // "floodFill"
QT_MOC_LITERAL(38, 426, 23), // "on_boundaryFill_clicked"
QT_MOC_LITERAL(39, 450, 12), // "boundaryFill"
QT_MOC_LITERAL(40, 463, 11), // "replace_rgb"
QT_MOC_LITERAL(41, 475, 19), // "on_scanLine_clicked"
QT_MOC_LITERAL(42, 495, 9), // "checkLeak"
QT_MOC_LITERAL(43, 505, 2), // "x1"
QT_MOC_LITERAL(44, 508, 2), // "x2"
QT_MOC_LITERAL(45, 511, 3), // "col"
QT_MOC_LITERAL(46, 515, 10), // "paintLines"
QT_MOC_LITERAL(47, 526, 20), // "on_translate_clicked"
QT_MOC_LITERAL(48, 547, 17), // "on_rotate_clicked"
QT_MOC_LITERAL(49, 565, 16), // "on_scale_clicked"
QT_MOC_LITERAL(50, 582, 21), // "on_reflection_clicked"
QT_MOC_LITERAL(51, 604, 16), // "on_shear_clicked"
QT_MOC_LITERAL(52, 621, 19), // "on_lineClip_clicked"
QT_MOC_LITERAL(53, 641, 22), // "on_polygonClip_clicked"
QT_MOC_LITERAL(54, 664, 12), // "suthHodgClip"
QT_MOC_LITERAL(55, 677, 8), // "int[][2]"
QT_MOC_LITERAL(56, 686, 11), // "poly_points"
QT_MOC_LITERAL(57, 698, 9), // "poly_size"
QT_MOC_LITERAL(58, 708, 14), // "clipper_points"
QT_MOC_LITERAL(59, 723, 12), // "clipper_size"
QT_MOC_LITERAL(60, 736, 11), // "x_intersect"
QT_MOC_LITERAL(61, 748, 2), // "y1"
QT_MOC_LITERAL(62, 751, 2), // "y2"
QT_MOC_LITERAL(63, 754, 2), // "x3"
QT_MOC_LITERAL(64, 757, 2), // "y3"
QT_MOC_LITERAL(65, 760, 2), // "x4"
QT_MOC_LITERAL(66, 763, 2), // "y4"
QT_MOC_LITERAL(67, 766, 11), // "y_intersect"
QT_MOC_LITERAL(68, 778, 4), // "clip"
QT_MOC_LITERAL(69, 783, 4), // "int&"
QT_MOC_LITERAL(70, 788, 17) // "on_Bezier_clicked"

    },
    "MainWindow\0Mouse_Pressed\0\0showMousePosition\0"
    "QPoint&\0pos\0paint_pixel\0x\0y\0QRgb&\0"
    "qrgb_obj\0on_show_axes_clicked\0"
    "on_Draw_clicked\0on_set_point1_clicked\0"
    "on_set_point2_clicked\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_spinBox_valueChanged\0"
    "arg1\0bresenham_line\0p1\0p2\0bresenham_circle\0"
    "p\0radius\0drawCircle\0xc\0yc\0ellipse_draw\0"
    "a\0b\0drawEllipse\0dda_line\0midPoint_circle\0"
    "on_enable_polygon_toggled\0checked\0"
    "on_floodFill_clicked\0floodFill\0"
    "on_boundaryFill_clicked\0boundaryFill\0"
    "replace_rgb\0on_scanLine_clicked\0"
    "checkLeak\0x1\0x2\0col\0paintLines\0"
    "on_translate_clicked\0on_rotate_clicked\0"
    "on_scale_clicked\0on_reflection_clicked\0"
    "on_shear_clicked\0on_lineClip_clicked\0"
    "on_polygonClip_clicked\0suthHodgClip\0"
    "int[][2]\0poly_points\0poly_size\0"
    "clipper_points\0clipper_size\0x_intersect\0"
    "y1\0y2\0x3\0y3\0x4\0y4\0y_intersect\0clip\0"
    "int&\0on_Bezier_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  199,    2, 0x0a /* Public */,
       3,    1,  200,    2, 0x0a /* Public */,
       6,    3,  203,    2, 0x0a /* Public */,
      11,    0,  210,    2, 0x08 /* Private */,
      12,    0,  211,    2, 0x08 /* Private */,
      13,    0,  212,    2, 0x08 /* Private */,
      14,    0,  213,    2, 0x08 /* Private */,
      15,    0,  214,    2, 0x08 /* Private */,
      16,    0,  215,    2, 0x08 /* Private */,
      17,    1,  216,    2, 0x08 /* Private */,
      19,    2,  219,    2, 0x08 /* Private */,
      22,    2,  224,    2, 0x08 /* Private */,
      25,    5,  229,    2, 0x08 /* Private */,
      28,    3,  240,    2, 0x08 /* Private */,
      31,    5,  247,    2, 0x08 /* Private */,
      32,    2,  258,    2, 0x08 /* Private */,
      33,    2,  263,    2, 0x08 /* Private */,
      34,    1,  268,    2, 0x08 /* Private */,
      36,    0,  271,    2, 0x08 /* Private */,
      37,    3,  272,    2, 0x08 /* Private */,
      38,    0,  279,    2, 0x08 /* Private */,
      39,    4,  280,    2, 0x08 /* Private */,
      41,    0,  289,    2, 0x08 /* Private */,
      42,    3,  290,    2, 0x08 /* Private */,
      46,    4,  297,    2, 0x08 /* Private */,
      47,    0,  306,    2, 0x08 /* Private */,
      48,    0,  307,    2, 0x08 /* Private */,
      49,    0,  308,    2, 0x08 /* Private */,
      50,    0,  309,    2, 0x08 /* Private */,
      51,    0,  310,    2, 0x08 /* Private */,
      52,    0,  311,    2, 0x08 /* Private */,
      53,    0,  312,    2, 0x08 /* Private */,
      54,    4,  313,    2, 0x08 /* Private */,
      60,    8,  322,    2, 0x08 /* Private */,
      67,    8,  339,    2, 0x08 /* Private */,
      68,    6,  356,    2, 0x08 /* Private */,
      70,    0,  369,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,   20,   21,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,   23,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    7,    8,   26,   27,   10,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int, QMetaType::Int,   23,   29,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    7,    8,   26,   27,   10,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,   20,   21,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,   23,   24,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 9, 0x80000000 | 9,    7,    8,   10,   40,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   43,   44,   45,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,   43,   44,   45,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 55, QMetaType::Int, 0x80000000 | 55, QMetaType::Int,   56,   57,   58,   59,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   43,   61,   44,   62,   63,   64,   65,   66,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   43,   61,   44,   62,   63,   64,   65,   66,
    QMetaType::Void, 0x80000000 | 55, 0x80000000 | 69, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   56,   57,   43,   61,   44,   62,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->showMousePosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->paint_pixel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QRgb(*)>(_a[3]))); break;
        case 3: _t->on_show_axes_clicked(); break;
        case 4: _t->on_Draw_clicked(); break;
        case 5: _t->on_set_point1_clicked(); break;
        case 6: _t->on_set_point2_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->bresenham_line((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 11: _t->bresenham_circle((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->drawCircle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QRgb(*)>(_a[5]))); break;
        case 13: _t->ellipse_draw((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->drawEllipse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QRgb(*)>(_a[5]))); break;
        case 15: _t->dda_line((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 16: _t->midPoint_circle((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->on_enable_polygon_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_floodFill_clicked(); break;
        case 19: _t->floodFill((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QRgb(*)>(_a[3]))); break;
        case 20: _t->on_boundaryFill_clicked(); break;
        case 21: _t->boundaryFill((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QRgb(*)>(_a[3])),(*reinterpret_cast< QRgb(*)>(_a[4]))); break;
        case 22: _t->on_scanLine_clicked(); break;
        case 23: { int _r = _t->checkLeak((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->paintLines((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QRgb(*)>(_a[4]))); break;
        case 25: _t->on_translate_clicked(); break;
        case 26: _t->on_rotate_clicked(); break;
        case 27: _t->on_scale_clicked(); break;
        case 28: _t->on_reflection_clicked(); break;
        case 29: _t->on_shear_clicked(); break;
        case 30: _t->on_lineClip_clicked(); break;
        case 31: _t->on_polygonClip_clicked(); break;
        case 32: _t->suthHodgClip((*reinterpret_cast< int(*)[][2]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)[][2]>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 33: { int _r = _t->x_intersect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 34: { int _r = _t->y_intersect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 35: _t->clip((*reinterpret_cast< int(*)[][2]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 36: _t->on_Bezier_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 37;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
