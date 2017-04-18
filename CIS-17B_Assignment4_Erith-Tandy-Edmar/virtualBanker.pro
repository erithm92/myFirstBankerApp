TEMPLATE = app
TARGET = CIS-17B_BankingProgram_Erith-Tandy-Edmar

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    Account.cpp \
    Checkings.cpp \
    CheckingsWindow.cpp \
    Savings.cpp \
    SavingsWindow.cpp \
    User.cpp \
    Window.cpp \
    TransferWindow.cpp \
    LoginWindow.cpp

HEADERS += \
    Account.h \
    Checkings.h \
    CheckingsWindow.h \
    Savings.h \
    SavingsWindow.h \
    User.h \
    Window.h \
    TransferWindow.h \
    LoginWindow.h
