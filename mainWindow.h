#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVector>
#include <QMainWindow>
#include "task.h"

namespace Ui {
class MainWindow;
}

/* Inherits from QMainWindow. Q_OBJECT macro must be first thing
 * declared to setup some Qt magic stuff. We also declare a
 * pointer to a MainWindow class, member variable 'ui', this
 * will allow us to interact with our UI components (buttons, text
 * entries, etc.) from C++, as Qt will set it up for us.
 *
 * We set up our slots here too, to hook signals to.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateStatus();

public slots:
    void addTask();
    void removeTask(Task *task);
    void taskStatusChanged(Task *task);

private:
    Ui::MainWindow *ui;
    /* QVector is Qt container class for dynamic arrays, like std::vector
     * but more Qt specific features
     */
    QVector<Task*> mTasks;
};

#endif // MAINWINDOW_H
