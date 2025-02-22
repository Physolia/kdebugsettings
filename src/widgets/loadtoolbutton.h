/*
    SPDX-FileCopyrightText: 2020-2023 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later

*/

#pragma once

#include <QToolButton>

#include "libkdebugsettings_private_export.h"
class LoadGroupMenu;
class LIBKDEBUGSETTINGS_EXPORT_TEST_EXPORT LoadToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit LoadToolButton(QWidget *parent = nullptr);
    ~LoadToolButton() override;

    void updateLoadGroupMenu();

    [[nodiscard]] QStringList groupNames() const;

Q_SIGNALS:
    void loadGroupRequested(const QString &fullPath);
    void loadFromFile();
    void manageGroupRequested();

private:
    LoadGroupMenu *const mLoadMenu;
};
