/*
    SPDX-FileCopyrightText: 2023 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once
#include "libkdebugsettings_export.h"
#include <QTreeView>

class LIBKDEBUGSETTINGS_EXPORT KDEApplicationListView : public QTreeView
{
    Q_OBJECT
public:
    explicit KDEApplicationListView(QWidget *parent = nullptr);
    ~KDEApplicationListView() override;
};
