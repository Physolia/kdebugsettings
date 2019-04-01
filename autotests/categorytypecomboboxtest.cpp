/*
  Copyright (c) 2015-2019 Montel Laurent <montel@kde.org>

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU Library General Public License as published by
  the Free Software Foundation; either version 2 of the License, or (at your
  option) any later version.

  This library is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
  License for more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to the
  Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.

*/

#include "categorytypecomboboxtest.h"
#include "../src/categorytypecombobox.h"
#include <QTest>

CategoryTypeComboBoxTest::CategoryTypeComboBoxTest(QObject *parent)
    : QObject(parent)
{
}

CategoryTypeComboBoxTest::~CategoryTypeComboBoxTest()
{
}

void CategoryTypeComboBoxTest::shouldHaveDefaultValue()
{
    CategoryTypeComboBox w(true);
    QCOMPARE(w.count(), 4);

    CategoryTypeComboBox w2(false);
    QCOMPARE(w2.count(), 5);
}

void CategoryTypeComboBoxTest::shouldSetType_data()
{
    QTest::addColumn<LoggingCategory::LoggingType>("input");

    QTest::newRow("all") <<  LoggingCategory::All;
    QTest::newRow("info") <<  LoggingCategory::Info;
    QTest::newRow("warning") << LoggingCategory::Warning;
    QTest::newRow("critical") << LoggingCategory::Critical;
    QTest::newRow("off") << LoggingCategory::Off;
}

void CategoryTypeComboBoxTest::shouldSetType()
{
    QFETCH(LoggingCategory::LoggingType, input);
    CategoryTypeComboBox w(false);
    w.setType(input);
    QCOMPARE(w.type(), input);
}

void CategoryTypeComboBoxTest::shouldVerifyItNotDefault()
{
    CategoryTypeComboBox w(true);
    w.setType(LoggingCategory::All);
    QVERIFY(w.loggingCategoryIsNotDefault());

    w.setType(LoggingCategory::Info);
    QVERIFY(!w.loggingCategoryIsNotDefault());

    w.setType(LoggingCategory::Warning);
    QVERIFY(w.loggingCategoryIsNotDefault());

    w.setType(LoggingCategory::Debug);
    QVERIFY(w.loggingCategoryIsNotDefault());

    w.setType(LoggingCategory::Critical);
    QVERIFY(w.loggingCategoryIsNotDefault());
}

void CategoryTypeComboBoxTest::shouldChangeDefaultCategory()
{
    CategoryTypeComboBox w(true);
    w.setDefaultCategories(LoggingCategory::All);
    w.setType(LoggingCategory::All);
    QVERIFY(!w.loggingCategoryIsNotDefault());

    w.setDefaultCategories(LoggingCategory::Critical);
    w.setType(LoggingCategory::Critical);
    QVERIFY(!w.loggingCategoryIsNotDefault());

    w.setType(LoggingCategory::Debug);
    QVERIFY(w.loggingCategoryIsNotDefault());
}

void CategoryTypeComboBoxTest::shouldVerifyThatDefaultCategoryIsCorrect()
{
    CategoryTypeComboBox w(true);
    w.setDefaultCategories(LoggingCategory::All);
    QCOMPARE(w.defaultCategories(), LoggingCategory::All);

    w.setDefaultCategories(LoggingCategory::Critical);
    QCOMPARE(w.defaultCategories(), LoggingCategory::Critical);

    w.setDefaultCategories(LoggingCategory::Debug);
    QCOMPARE(w.defaultCategories(), LoggingCategory::Debug);
}

QTEST_MAIN(CategoryTypeComboBoxTest)
