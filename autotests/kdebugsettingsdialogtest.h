/*
    SPDX-FileCopyrightText: 2015-2023 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later

*/

#pragma once

#include <QObject>

class KDebugSettingsDialogTest : public QObject
{
    Q_OBJECT
public:
    explicit KDebugSettingsDialogTest(QObject *parent = nullptr);
    ~KDebugSettingsDialogTest() override;
private Q_SLOTS:
    void shouldHaveDefaultValue();
};
