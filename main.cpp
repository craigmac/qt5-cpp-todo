#include "mainWindow.h"
#include <QApplication>

/* A cross-platform todo-app using C++ (some C++11 features like lambda, and
 * auto types) and Qt 5 Framework. Open the .pro file in Qt Creator
 * and build for your system. You will have to choose a kit to build
 * with first (clang if OS X, gcc 64-bit for Linux, android/ios kits if
 * you have them installed).
 *
 * Dev environment details:
 * QtCreator 4.6.2 (Based on Qt 5.10.1 (GCC 5.3.1 20160406 (Red Hat 5.3.1-6), 64 bit))
 * Lubuntu 18.04 LTS
 *
 * Demonstrates:
 * 1. Qt dynamic layout boxes in both horizontal and vertical directions
 * 2. Qt dynamic spacers in both horizontal or vertical directions
 * 3. Qt's signal/slots mechanism for event-driven programming
 * 4. Styling UI elements at runtime (strikethrough on text)
 * 5. Inheritance-based memory management (Qt's efforts here mostly,
 * although we do clean up a couple times explicitly)
 * 6. Simple OOP principles
 * 7. MVC-like pattern (.ui files hold UI design in Qt XML-style format,
 * and the cpp files hold logic)
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
