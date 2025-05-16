#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "avto.h"
#include "fileparser.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include "proverka.h"
#include "QVBoxLayout"
#include "QHBoxLayout"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    model->setColumnCount(4);
    model->setHeaderData(0, Qt::Horizontal, "Тип");
    model->setHeaderData(1, Qt::Horizontal, "Номер");
    model->setHeaderData(2, Qt::Horizontal, "Дата");
    model->setHeaderData(3, Qt::Horizontal, "Доп. параметры");
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(3, 270);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::on_addButton_clicked()
{
    cnt++;
    updateClick();
    int newRow = model->rowCount();
    model->insertRow(newRow);

    for (int col = 0; col < model->columnCount(); ++col) {
        model->setItem(newRow, col, new QStandardItem(""));
    }
}


void MainWindow::on_delButton_clicked()
{
    cnt++;
    updateClick();
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Удаление", "Сначала выберите строку для удаления.");
        return;
    }

    model->removeRow(currentIndex.row());
}


void MainWindow::on_loadButton_clicked()
{
    cnt++;
    updateClick();
    QString fileName = QFileDialog::getOpenFileName(this, "Выбрать файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");
    if (fileName.isEmpty())
        return;
    QList<Automobile*> cars = parseFile(fileName);

    for (const auto& car : cars) {
        QStringList row = car->toTableRow();
        QList<QStandardItem*> items;
        for (const QString& value : row)
            items << new QStandardItem(value);
        model->appendRow(items);

        delete car;
    }
}


void MainWindow::on_saveButton_clicked()
{
    cnt++;
    updateClick();
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Text Files (*.txt)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи");
        return;
    }

    QTextStream out(&file);
    int rowCount = model->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QString type = model->item(row, 0)->text();
        QString number = model->item(row, 1)->text();
        QString date = model->item(row, 2)->text();
        QString extra = model->item(row, 3)->text();

        if (type == "Автомобиль") {
            out << date << ";" << number << "\n";
        } else if (type == "Грузовик") {
            QRegularExpression rx("Вес: (\\d+)");
            QRegularExpressionMatch match = rx.match(extra);
            if (match.hasMatch()) {
                out << date << ";" << number << ";" << match.captured(1) << "\n";
            }
        } else if (type == "Легковая") {
            QRegularExpression rx("Цвет: (.*), Скорость: (\\d+)");
            QRegularExpressionMatch match = rx.match(extra);
            if (match.hasMatch()) {
                out << date << ";" << number << ";" << match.captured(1) << ";" << match.captured(2) << "\n";
            }
        }
    }

    file.close();
    QMessageBox::information(this, "Готово", "Файл успешно сохранён.");
}


void MainWindow::on_fuldelButton_clicked()
{
    int gg1;
    cnt++;
    updateClick();
    model->removeRows(0, model->rowCount());
}

void MainWindow::updateClick()
{
    QString text = Click(cnt);
    ui->textEdit->setText(text);
}

