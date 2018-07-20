# Demo "todo" cross-platform desktop application using C++ and Qt 5

A cross-platform todo-app using C++ (some C++11 features like lambda, and
auto types) and Qt 5 Framework. Open the .pro file in Qt Creator
and build for your system. You will have to choose a kit to build
with first (clang if OS X, gcc 64-bit for Linux, android/ios kits if
you have them installed).

## Demonstrates

  * Qt dynamic layout boxes in both horizontal and vertical directions
  * Qt dynamic spacers in both horizontal or vertical directions
  * Qt's signal/slots mechanism for event-driven programming
  * Styling UI elements at runtime (strikethrough on text)
  * Inheritance-based memory management (Qt's efforts here mostly,
  although we explicitly manage in a couple places)

## Dev-environment details:

  * QtCreator 4.6.2 (Based on Qt 5.10.1 (GCC 5.3.1 20160406 (Red Hat 5.3.1-6),
64 bit))
  * Lubuntu 18.04 LTS

