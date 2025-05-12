#include "proverka.h"

QString Click(int cnt)
{
    QString result;
    result += QString("Кнопка нажата: %1 раз(а)\n").arg(cnt);
    return result;
}
