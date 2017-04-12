#include "Window.h"
#include "User.h"
#include <QApplication>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Checkings defaultCheckings;
 Savings defaultSavings;
 User defaultUser(defaultCheckings, defaultSavings);

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
     window.show();

 return app.exec();
}
