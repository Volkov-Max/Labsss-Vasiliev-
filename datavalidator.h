#ifndef DATAVALIDATOR_H
#define DATAVALIDATOR_H

#include <QString>

class DataValidator {
public:
    static bool isValidDate(const QString& date);
    static bool isValidCarNumber(const QString& number);
};

#endif // DATAVALIDATOR_H
