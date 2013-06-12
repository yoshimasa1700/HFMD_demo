/****************************************************************************
** Meta object code from reading C++ file 'CRForest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HFMD_demo/source/CRForest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CRForest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CRForest_t {
    QByteArrayData data[15];
    char stringdata[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CRForest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CRForest_t qt_meta_stringdata_CRForest = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 14),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 29),
QT_MOC_LITERAL(4, 55, 14),
QT_MOC_LITERAL(5, 70, 13),
QT_MOC_LITERAL(6, 84, 20),
QT_MOC_LITERAL(7, 105, 20),
QT_MOC_LITERAL(8, 126, 4),
QT_MOC_LITERAL(9, 131, 9),
QT_MOC_LITERAL(10, 141, 13),
QT_MOC_LITERAL(11, 155, 7),
QT_MOC_LITERAL(12, 163, 27),
QT_MOC_LITERAL(13, 191, 13),
QT_MOC_LITERAL(14, 205, 8)
    },
    "CRForest\0detectedResult\0\0"
    "std::vector<detectionResult*>\0"
    "sendClassNames\0sendVoteImage\0"
    "cv::vector<cv::Mat*>\0checkWhatIShouldShow\0"
    "int*\0detection\0CTestDataset&\0testSet\0"
    "recieveWhatDialogWantToShow\0receiveConfig\0"
    "CConfig*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRForest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,
       4,    1,   52,    2, 0x05,
       5,    1,   55,    2, 0x05,
       7,    1,   58,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    1,   61,    2, 0x0a,
      12,    1,   64,    2, 0x0a,
      13,    1,   67,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 14,    2,

       0        // eod
};

void CRForest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CRForest *_t = static_cast<CRForest *>(_o);
        switch (_id) {
        case 0: _t->detectedResult((*reinterpret_cast< std::vector<detectionResult*>(*)>(_a[1]))); break;
        case 1: _t->sendClassNames((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->sendVoteImage((*reinterpret_cast< cv::vector<cv::Mat*>(*)>(_a[1]))); break;
        case 3: _t->checkWhatIShouldShow((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 4: _t->detection((*reinterpret_cast< CTestDataset(*)>(_a[1]))); break;
        case 5: _t->recieveWhatDialogWantToShow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->receiveConfig((*reinterpret_cast< CConfig*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CRForest::*_t)(std::vector<detectionResult*> ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRForest::detectedResult)) {
                *result = 0;
            }
        }
        {
            typedef void (CRForest::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRForest::sendClassNames)) {
                *result = 1;
            }
        }
        {
            typedef void (CRForest::*_t)(cv::vector<cv::Mat*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRForest::sendVoteImage)) {
                *result = 2;
            }
        }
        {
            typedef void (CRForest::*_t)(int * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRForest::checkWhatIShouldShow)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject CRForest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CRForest.data,
      qt_meta_data_CRForest,  qt_static_metacall, 0, 0}
};


const QMetaObject *CRForest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRForest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CRForest.stringdata))
        return static_cast<void*>(const_cast< CRForest*>(this));
    return QObject::qt_metacast(_clname);
}

int CRForest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CRForest::detectedResult(std::vector<detectionResult*> _t1)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< CRForest *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CRForest::sendClassNames(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CRForest::sendVoteImage(cv::vector<cv::Mat*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CRForest::checkWhatIShouldShow(int * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
