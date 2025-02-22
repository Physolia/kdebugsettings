/*
    SPDX-FileCopyrightText: 2015-2023 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later

*/

#include "configurecustomsettingwidgettest.h"
#include "configurecustomsettingwidget.h"
#include <KLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QSignalSpy>
#include <QTest>

ConfigureCustomSettingWidgetTest::ConfigureCustomSettingWidgetTest(QObject *parent)
    : QObject(parent)
{
}

ConfigureCustomSettingWidgetTest::~ConfigureCustomSettingWidgetTest() = default;

void ConfigureCustomSettingWidgetTest::shouldHaveDefaultValue()
{
    ConfigureCustomSettingWidget w;
    auto lab = w.findChild<QLabel *>(QStringLiteral("category_label"));
    QVERIFY(lab);

    auto categoryLineEdit = w.findChild<KLineEdit *>(QStringLiteral("category_lineedit"));
    QVERIFY(categoryLineEdit);
    QVERIFY(categoryLineEdit->trapReturnKey());
    QVERIFY(categoryLineEdit->isClearButtonEnabled());

    auto enableCategory = w.findChild<QCheckBox *>(QStringLiteral("enable_category"));
    QVERIFY(enableCategory);

    lab = w.findChild<QLabel *>(QStringLiteral("categorytype_label"));
    QVERIFY(lab);
    auto categoryType = w.findChild<QComboBox *>(QStringLiteral("categorytype_combobox"));
    QVERIFY(categoryType);
    QCOMPARE(categoryType->count(), 4);
}

void ConfigureCustomSettingWidgetTest::shouldRestoreRules_data()
{
    QTest::addColumn<QString>("input");

    QTest::newRow("empty") << QString();
    QTest::newRow("validrule") << QStringLiteral("foo.warning=true");
    QTest::newRow("validrule2") << QStringLiteral("foo=true");
    QTest::newRow("validrule3") << QStringLiteral("foo=false");
    QTest::newRow("validrule3*") << QStringLiteral("*.warning=false");
}

void ConfigureCustomSettingWidgetTest::shouldRestoreRules()
{
    QFETCH(QString, input);
    ConfigureCustomSettingWidget w;
    w.setRule(input);
    QCOMPARE(input, w.rule());
}

void ConfigureCustomSettingWidgetTest::shouldEmitSignalWhenWeChangeLogName()
{
    ConfigureCustomSettingWidget w;
    auto categoryLineEdit = w.findChild<KLineEdit *>(QStringLiteral("category_lineedit"));
    QVERIFY(categoryLineEdit);
    QSignalSpy spy(&w, &ConfigureCustomSettingWidget::enableButton);
    categoryLineEdit->setText(QStringLiteral("bla"));
    QCOMPARE(spy.count(), 1);
    QCOMPARE(spy.at(0).at(0).toBool(), true);
    categoryLineEdit->clear();
    QCOMPARE(spy.count(), 2);
    QCOMPARE(spy.at(1).at(0).toBool(), false);

    categoryLineEdit->setText(QStringLiteral(" "));
    QCOMPARE(spy.count(), 3);
    QCOMPARE(spy.at(2).at(0).toBool(), false);
}

QTEST_MAIN(ConfigureCustomSettingWidgetTest)

#include "moc_configurecustomsettingwidgettest.cpp"
