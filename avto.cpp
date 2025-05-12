#include "avto.h"
#include "lineparser.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Automobile::Automobile(const QString& date, const QString& carNumber)
    : date(date), carNumber(carNumber) {}

Automobile::~Automobile() {}

QString Automobile::getType() const {
    return "Автомобиль";
}

QStringList Automobile::toTableRow() const {
    return { getType(), carNumber, date, "-" };
}

PassengerCar::PassengerCar(const QString& date, const QString& carNumber, const QString& color, int speed)
    : Automobile(date, carNumber), color(color), speed(speed) {}

QString PassengerCar::getType() const {
    return "Легковая";
}

QStringList PassengerCar::toTableRow() const {
    return { getType(), carNumber, date, QString("Цвет: %1, Скорость: %2").arg(color).arg(speed) };
}

Truck::Truck(const QString& date, const QString& carNumber, int weight)
    : Automobile(date, carNumber), weight(weight) {}

QString Truck::getType() const {
    return "Грузовик";
}

QStringList Truck::toTableRow() const {
    return { getType(), carNumber, date, QString("Вес: %1 кг").arg(weight) };
}


