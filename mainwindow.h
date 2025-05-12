#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_delButton_clicked();

    void on_loadButton_clicked();

    void on_saveButton_clicked();

    void on_fuldelButton_clicked();

     void updateClick();

private:
    int cnt=0;
    QStandardItemModel *model;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
