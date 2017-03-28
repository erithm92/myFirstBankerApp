TEMPLATE = app
TARGET = Virtual_Banker_HW3_Erith_and_Tandy

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    user.cpp \
    savings.cpp \
    checkings.cpp \
    account.cpp \
    savingswindow.cpp \
    checkingswindow.cpp

HEADERS += \
    window.h \
    user.h \
    savings.h \
    checkings.h \
    account.h \
    savingswindow.h \
    checkingswindow.h
