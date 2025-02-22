/*
    SPDX-FileCopyrightText: 2016-2023 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later

*/
#pragma once

#include "libkdebugsettingscore_export.h"
#include <QDebug>
#include <QList>
#include <QString>

struct LIBKDEBUGSETTINGSCORE_EXPORT LoggingCategory {
    enum LoggingType : char {
        All = 0,
        Info,
        Warning,
        Debug,
        Critical,
        Off,
        Undefined,
    };

    LoggingCategory();
    explicit LoggingCategory(const QString &description, const QString &logName, LoggingType loggingType, const QString &identifier, bool enabled)
        : description(description)
        , categoryName(logName)
        , identifierName(identifier)
        , loggingType(loggingType)
        , enabled(enabled)
    {
    }

    using List = QList<LoggingCategory>;
    [[nodiscard]] bool operator==(const LoggingCategory &other) const;
    [[nodiscard]] bool isValid() const;

    [[nodiscard]] QString createRule() const;
    [[nodiscard]] QString createCustomRule() const;
    [[nodiscard]] QString generateToolTip() const;
    [[nodiscard]] QString generateDisplayRule() const;

    QString description;
    QString categoryName;
    QString identifierName;
    LoggingType loggingType = Info;
    LoggingType defaultSeverityType = Info;
    bool enabled = true;

private:
    [[nodiscard]] QString convertCategoryTypeToString(LoggingCategory::LoggingType type) const;
};
LIBKDEBUGSETTINGSCORE_EXPORT QDebug operator<<(QDebug debug, const LoggingCategory &cat);

Q_DECLARE_TYPEINFO(LoggingCategory, Q_RELOCATABLE_TYPE);

Q_DECLARE_METATYPE(LoggingCategory)
Q_DECLARE_METATYPE(LoggingCategory::LoggingType)
