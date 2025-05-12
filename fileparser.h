#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QString>
#include <QList>
#include "avto.h"

QList<Automobile*> parseFile(const QString& filename);

#endif // FILEPARSER_H
