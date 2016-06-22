/*
  Copyright (c) 2016 Montel Laurent <montel@kde.org>

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
#ifndef LOGGINGCATEGORY_H
#define LOGGINGCATEGORY_H

#include <QVector>
#include <QObject>
#include <QString>

struct LoggingCategory {
    LoggingCategory();

    enum LoggingType {
        All = 0,
        Info,
        Warning,
        Debug,
        Critical,
        Off
    };

    typedef QVector<LoggingCategory> List;
    bool operator ==(const LoggingCategory &other) const;
    bool isValid() const;

    QString createRule();
    QString createCustomRule();
    QString description;
    QString logName;
    LoggingType loggingType;
    bool enabled;
    bool undefinedType;

};
Q_DECLARE_TYPEINFO(LoggingCategory, Q_MOVABLE_TYPE);
Q_DECLARE_METATYPE(LoggingCategory)
Q_DECLARE_METATYPE(LoggingCategory::LoggingType)

#endif // LOGGINGCATEGORY_H
