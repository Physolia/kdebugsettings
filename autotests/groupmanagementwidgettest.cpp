/*
  Copyright (c) 2020 Laurent Montel <montel@kde.org>

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

#include "groupmanagementwidgettest.h"
#include "groupmanagementwidget.h"
#include <QListView>
#include <QTest>
#include <QVBoxLayout>

QTEST_MAIN(GroupManagementWidgetTest)
GroupManagementWidgetTest::GroupManagementWidgetTest(QObject *parent)
    : QObject(parent)
{

}

void GroupManagementWidgetTest::shouldHaveDefaultValues()
{
    GroupManagementWidget w;
    auto mainLayout = w.findChild<QVBoxLayout *>(QStringLiteral("mainLayout"));
    QVERIFY(mainLayout);
    QCOMPARE(mainLayout->contentsMargins(), {});

    auto mListView = w.findChild<QListView *>(QStringLiteral("mListView"));
    QVERIFY(mListView);
    QCOMPARE(mListView->selectionMode(), QAbstractItemView::MultiSelection);
}
