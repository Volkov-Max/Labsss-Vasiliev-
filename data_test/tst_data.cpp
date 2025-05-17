#include <QtTest>
#include "datavalidator.h"

class data : public QObject
{
    Q_OBJECT

private slots:
    void test_validDates();
    void test_invalidDates();
};

void data::test_validDates()
{
    QVERIFY(DataValidator::isValidDate("2024.10.01"));
    QVERIFY(DataValidator::isValidDate("1999.12.31"));
    QVERIFY(DataValidator::isValidDate("2000.06.15"));
}

void data::test_invalidDates()
{
    QVERIFY(!DataValidator::isValidDate("2024.13.01"));
    QVERIFY(!DataValidator::isValidDate("2024.00.10"));
    QVERIFY(!DataValidator::isValidDate("2024.02.32"));
    QVERIFY(!DataValidator::isValidDate("2024.2.2"));
    QVERIFY(!DataValidator::isValidDate("abcd.ef.gh"));
    QVERIFY(!DataValidator::isValidDate(""));
}

QTEST_APPLESS_MAIN(data)
#include "tst_data.moc"
