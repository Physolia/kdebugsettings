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

#ifndef KDEAPPLICATIONDEBUGSETTINGPAGE_H
#define KDEAPPLICATIONDEBUGSETTINGPAGE_H

#include <QWidget>
#include "loggingcategory.h"
#include "libkdebugsettings_export.h"
class QPushButton;
class KDEApplicationTreeListWidget;
class KTreeWidgetSearchLine;
class LIBKDEBUGSETTINGS_EXPORT KDEApplicationDebugSettingPage : public QWidget
{
    Q_OBJECT
public:
    explicit KDEApplicationDebugSettingPage(QWidget *parent = nullptr);
    ~KDEApplicationDebugSettingPage() override;
    void fillList(const LoggingCategory::List &list);
    Q_REQUIRED_RESULT LoggingCategory::List rules(bool forceSavingAllRules) const;
    void insertCategories(const LoggingCategory::List &list);

    void restoreToDefault();

    void forceFocus();
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    void slotSelectAllDebug();
    void slotDeselectAllDebug();
    void slotDeselectAllMessages();

    KDEApplicationTreeListWidget *mTreeListWidget = nullptr;
    KTreeWidgetSearchLine *mTreeListWidgetSearchLine = nullptr;
    QPushButton *mEnableDebug = nullptr;
    QPushButton *mTurnOffDebug = nullptr;
    QPushButton *mTurnOffAllMessages = nullptr;
};

#endif // KDEAPPLICATIONDEBUGSETTINGPAGE_H
