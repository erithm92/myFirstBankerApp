#include "Window.h"
#include "User.h"
#include "LoginWindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
QApplication app (argc, argv);

Checkings defaultCheckings;
Savings defaultSavings;
User defaultUser(defaultCheckings, defaultSavings);

LoginWindow loginWindow;
loginWindow.buildWindow(defaultUser);
loginWindow.show();

CheckingsWindow checkingsWindow;
    checkingsWindow.setUser(defaultUser);
    checkingsWindow.buildWindow();

SavingsWindow savingsWindow;
    savingsWindow.setUser(defaultUser);
    savingsWindow.buildWindow();

    TransferWindow transWindow;
    transWindow.buildWindow(defaultUser);

Window window;
    window.buildWindow(defaultUser);
    window.setCheckWindow(checkingsWindow);
    window.setSaveWindow(savingsWindow);
    window.setTransWindow(transWindow);
    //window.show();

QObject::connect(&transWindow, SIGNAL(fundsTransferred(bool)), &window, SLOT(transUpdate())); // <Tandy> This updates Window after a transfer

return app.exec();
}
