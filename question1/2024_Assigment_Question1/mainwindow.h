// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();

private slots:
    void generateID();

private:
    Ui::MainWindow *ui;
    QString generateUniqueID(const QString& fullName);
    QString generateInitialKey(const QString& fullName);
};

#endif // MAINWINDOW_H
