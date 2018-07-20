#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QDebug>
#include <QInputDialog>

/* Constructor. Initializer list here calls superclass
 * constructor with any parent widget passed along, default
 * none. We also initialize the private member variable
 * 'ui' using initializer list. It is declared in header
 * as a private member var, a pointer.
 *
 * Signals are messages sent by an object. Slots are just
 * functions that receive signals. Slot/Signals must have
 * have same function signatures to work.
 *
 * We use connect() function to set up a signal/slot connection:
 * connect(sender, &Sender::signalName, receiver, &Receiver::slotName);
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mTasks()
{
    // need to call this to init all widgets used in the
    // mainWindow.ui design file.
    ui->setupUi(this);

    // Setup a connection using signal/slot mechanism, to call
    // addTask() function when our add task button clicked signal is emitted.
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
    // Call our method
    updateStatus();

}

MainWindow::~MainWindow()
{
    // Clean up the pointer
    delete ui;
}

/* Slot function for adding task */
void MainWindow::addTask()
{
    bool ok;

    // Static blocking function that display dialog to get task name.
    /* Signature:
     * QString QInputDialog::getText(QWidget *parent, const QString &title, const QString &label,
     *                               QLineEdit::EchoMode mode = QLineEdit::Normal,
     *                               const QString &text = QString(),
     *                               bool *ok = 0, ...)
     */
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new task";
        Task *task = new Task(name);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
        mTasks.append(task);
        // We can do this because task is a QWidget
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task *task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    /* Ownership transfer does not completely release the task
     * class ownership. What happens is that the task class's parent
     * becomes centralWidget, tasksLayout class's parent, but we don't
     * want that, we want to forget everything about this task, so
     * we explicitly set its parent to null and delete it here.
     */
    task->setParent(0);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task *task)
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount = 0;
    /* Using C++11 auto var feature here in for-loop to assign the
     * type and var name at each iteration of an iterable container.
     */
    for (auto t : mTasks) {
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int todoCount = mTasks.size() - completedCount;

    ui->statusLabel->setText(
                QString("Status: %1 todo / %2 completed")
                        .arg(todoCount)
                        .arg(completedCount));
}
