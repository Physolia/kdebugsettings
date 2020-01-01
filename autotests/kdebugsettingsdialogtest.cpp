/*
  Copyright (c) 2015-2020 Laurent Montel <montel@kde.org>

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

#include "kdebugsettingsdialogtest.h"
#include "../src/kdebugsettingsdialog.h"
#include "../src/categorywarning.h"
#include <QDialogButtonBox>
#include <QPushButton>
#include <QTabWidget>
#include <QStandardPaths>
#include <QTest>

KDebugSettingsDialogTest::KDebugSettingsDialogTest(QObject *parent)
    : QObject(parent)
{
    QStandardPaths::setTestModeEnabled(true);
}

KDebugSettingsDialogTest::~KDebugSettingsDialogTest()
{
}

void KDebugSettingsDialogTest::shouldHaveDefaultValue()
{
    KDebugSettingsDialog dlg;
    QDialogButtonBox *buttonBox = dlg.findChild<QDialogButtonBox *>(QStringLiteral("buttonbox"));
    QVERIFY(buttonBox);
    QCOMPARE(buttonBox->standardButtons(), QDialogButtonBox::RestoreDefaults | QDialogButtonBox::Ok | QDialogButtonBox::Cancel | QDialogButtonBox::Help | QDialogButtonBox::Apply);
    QTabWidget *tab = dlg.findChild<QTabWidget *>(QStringLiteral("tabwidget"));
    QVERIFY(tab);
    for (int i = 0; i < tab->count(); ++i) {
        const QString objName = tab->widget(i)->objectName();
        const bool hasCorrectName = (objName == QLatin1String("kdeapplicationsettingspage"))
                                    || (objName == QLatin1String("customsettingspage"))
                                    || (objName == QLatin1String("environmentsettingsrulespage"));
        QVERIFY(hasCorrectName);
    }
    QPushButton *saveAs = buttonBox->findChild<QPushButton *>(QStringLiteral("saveas_button"));
    QVERIFY(saveAs);
    QPushButton *load = buttonBox->findChild<QPushButton *>(QStringLiteral("load_button"));
    QVERIFY(load);
    QPushButton *insertCategories = buttonBox->findChild<QPushButton *>(QStringLiteral("insert_button"));
    QVERIFY(insertCategories);
    CategoryWarning *categoryWarning = dlg.findChild<CategoryWarning *>(QStringLiteral("categorywarning"));
    QVERIFY(categoryWarning);
    QVERIFY(!categoryWarning->isVisible());
}

QTEST_MAIN(KDebugSettingsDialogTest)
