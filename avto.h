#ifndef AVTO_H
#define AVTO_H

#include <QString>
#include <QStringList>
#include <QList>

class Automobile {
protected:
    QString date;
    QString carNumber;
public:
    Automobile(const QString& date, const QString& carNumber);
    virtual ~Automobile();

    virtual QString getType() const;
    virtual QStringList toTableRow() const;
};

class PassengerCar : public Automobile {
private:
    QString color;
    int speed;
public:
    PassengerCar(const QString& date, const QString& carNumber, const QString& color, int speed);

    QString getType() const override;
    QStringList toTableRow() const override;
};

class Truck : public Automobile {
private:
    int weight;
public:
    Truck(const QString& date, const QString& carNumber, int weight);

    QString getType() const override;
    QStringList toTableRow() const override;
};

#endif // AVTO_H
