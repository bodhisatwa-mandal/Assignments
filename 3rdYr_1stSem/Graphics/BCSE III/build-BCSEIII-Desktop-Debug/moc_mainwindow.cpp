/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BCSEIII/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[264];
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
QT_MOC_LITERAL(21, 261, 2) // "p2"

    },
    "MainWindow\0Mouse_Pressed\0\0showMousePosition\0"
    "QPoint&\0pos\0paint_pixel\0x\0y\0QRgb&\0"
    "qrgb_obj\0on_show_axes_clicked\0"
    "on_Draw_clicked\0on_set_point1_clicked\0"
    "on_set_point2_clicked\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_spinBox_valueChanged\0"
    "arg1\0bresenham_line\0p1\0p2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    1,   70,    2, 0x0a /* Public */,
       6,    3,   73,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,
      15,    0,   84,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,
      17,    1,   86,    2, 0x08 /* Private */,
      19,    2,   89,    2, 0x08 /* Private */,

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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
