#include <QApplication>
#include "window.h"
#include "user.h"
int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Savings defaultSavings;
 Checkings defaultCheckings;

 User defaultUser(defaultCheckings, defaultSavings);

 SavingsWindow savingsWindow;
 CheckingsWindow checkingsWindow;
 savingsWindow.setUser(defaultUser);
 savingsWindow.buildWindow();
 checkingsWindow.setUser(defaultUser);
 checkingsWindow.buildWindow();

 Window window;
 window.buildWindow(defaultUser);
 window.setCheckWindow(checkingsWindow);
 window.setSaveWindow(savingsWindow);
 window.show();

 return app.exec();
}
