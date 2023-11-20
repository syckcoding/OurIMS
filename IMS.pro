QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/Login   #通过路径添加子文件内容
INCLUDEPATH += $$PWD/Admin   #添加管理员文件夹
INCLUDEPATH += $$PWD/Teacher #添加教师文件夹
INCLUDEPATH += $$PWD/Student #添加学生文件夹

SOURCES += \
    Admin/admin.cpp \
    Login/email.cpp \
    Login/identity_choose.cpp \
    Login/main.cpp \
    Login/mainwindow.cpp \
    Login/register.cpp \
    Student/student.cpp \
    Teacher/teacher.cpp

HEADERS += \
    Admin/admin.h \
    Student/student.h \
    Teacher/teacher.h \
    creatConnection.h \
    Login/email.h \
    Login/identity_choose.h \
    Login/mainwindow.h \
    Login/register.h

FORMS += \
    Admin/admin.ui \
    Login/identity_choose.ui \
    Login/mainwindow.ui \
    Login/register.ui \
    Student/student.ui \
    Teacher/teacher.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
