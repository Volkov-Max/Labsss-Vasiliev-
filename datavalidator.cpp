#include "datavalidator.h"
#include <QRegularExpression>

bool DataValidator::isValidDate(const QString& date) {
    // Год: 4 цифры, Месяц: 01-12, День: 01-31
    QRegularExpression regex(R"(^(?:\d{4})\.(0[1-9]|1[0-2])\.(0[1-9]|[12][0-9]|3[01])$)");
    return regex.match(date).hasMatch();
}

bool DataValidator::isValidCarNumber(const QString& number) {
    // Формат: A000AA (одна буква, 3 цифры, 2 буквы)
    QRegularExpression regex(R"(^[A-Z]\d{3}[A-Z]{2}$)");
    return regex.match(number).hasMatch();
}
