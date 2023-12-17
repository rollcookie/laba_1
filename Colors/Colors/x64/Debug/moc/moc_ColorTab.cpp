/****************************************************************************
** Meta object code from reading C++ file 'ColorTab.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ColorTab.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSColorTabENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSColorTabENDCLASS = QtMocHelpers::stringData(
    "ColorTab",
    "colorChange",
    "",
    "pos",
    "type",
    "onButtonPress",
    "onSlider1",
    "onSlider2",
    "onSlider3",
    "onSlider4"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSColorTabENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[9];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[5];
    char stringdata5[14];
    char stringdata6[10];
    char stringdata7[10];
    char stringdata8[10];
    char stringdata9[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSColorTabENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSColorTabENDCLASS_t qt_meta_stringdata_CLASSColorTabENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "ColorTab"
        QT_MOC_LITERAL(9, 11),  // "colorChange"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 3),  // "pos"
        QT_MOC_LITERAL(26, 4),  // "type"
        QT_MOC_LITERAL(31, 13),  // "onButtonPress"
        QT_MOC_LITERAL(45, 9),  // "onSlider1"
        QT_MOC_LITERAL(55, 9),  // "onSlider2"
        QT_MOC_LITERAL(65, 9),  // "onSlider3"
        QT_MOC_LITERAL(75, 9)   // "onSlider4"
    },
    "ColorTab",
    "colorChange",
    "",
    "pos",
    "type",
    "onButtonPress",
    "onSlider1",
    "onSlider2",
    "onSlider3",
    "onSlider4"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSColorTabENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   55,    2, 0x08,    4 /* Private */,
       6,    1,   56,    2, 0x08,    5 /* Private */,
       7,    1,   59,    2, 0x08,    7 /* Private */,
       8,    1,   62,    2, 0x08,    9 /* Private */,
       9,    1,   65,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject ColorTab::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSColorTabENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSColorTabENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSColorTabENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ColorTab, std::true_type>,
        // method 'colorChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onButtonPress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSlider1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSlider2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSlider3'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSlider4'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ColorTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColorTab *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->colorChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->onButtonPress(); break;
        case 2: _t->onSlider1((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->onSlider2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->onSlider3((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onSlider4((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ColorTab::*)(int , int );
            if (_t _q_method = &ColorTab::colorChange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ColorTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSColorTabENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ColorTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ColorTab::colorChange(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
