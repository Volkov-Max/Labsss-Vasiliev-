#include "lineparser.h"
#include "datavalidator.h"
#include <QStringList>

Automobile* parseLineToCar(const QString& line) {
    QStringList tokens = line.split(';');
    if (tokens.size() < 2) return nullptr;

    QString date = tokens[0];
    QString number = tokens[1];

    if (!DataValidator::isValidDate(date) || !DataValidator::isValidCarNumber(number))
        return nullptr;

    if (tokens.size() == 2) {
        return new Automobile(date, number);
    } else if (tokens.size() == 3) {
        bool ok;
        int weight = tokens[2].toInt(&ok);
        if (!ok) return nullptr;
        return new Truck(date, number, weight);
    } else if (tokens.size() == 4) {
        bool ok;
        int speed = tokens[3].toInt(&ok);
        if (!ok) return nullptr;
        return new PassengerCar(date, number, tokens[2], speed);
    }

    return nullptr;
}
