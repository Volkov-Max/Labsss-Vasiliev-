#include "fileparser.h"
#include "lineparser.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QList<Automobile*> parseFile(const QString& filename) {
    QList<Automobile*> cars;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Не удалось открыть файл:" << filename;
        return cars;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        Automobile* car = parseLineToCar(line);
        if (car) {
            cars.append(car);
        } else {
            qWarning() << "Строка пропущена (не прошла валидацию):" << line;
        }
    }

    file.close();
    return cars;
}
