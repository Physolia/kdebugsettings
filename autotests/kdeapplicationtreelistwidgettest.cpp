/*
  Copyright (c) 2015-2018 Montel Laurent <montel@kde.org>

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

#include "kdeapplicationtreelistwidgettest.h"
#include "../src/kdeapplicationtreelistwidget.h"
#include <qtest.h>
#include <QHeaderView>

KDEApplicationTreeListWidgetTest::KDEApplicationTreeListWidgetTest(QObject *parent) : QObject(parent)
{
}

KDEApplicationTreeListWidgetTest::~KDEApplicationTreeListWidgetTest()
{
}

void KDEApplicationTreeListWidgetTest::shouldHaveDefaultValue()
{
    KDEApplicationTreeListWidget w;
    QCOMPARE(w.topLevelItemCount(), 0);
    QVERIFY(w.header()->isHidden());
    QCOMPARE(w.columnCount(), 3);
}

QTEST_MAIN(KDEApplicationTreeListWidgetTest)
