/*
  Copyright (c) 2015 Montel Laurent <montel@kde.org>

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

#ifndef KDEBUGSETTINGSUTIL_H
#define KDEBUGSETTINGSUTIL_H

#include <QString>
#include "kdebugsettingsdialog.h"
namespace KDebugSettingsUtil
{
void readLoggingCategories(const QString &filename, Category::List &categoriesList, bool checkCategoryList = false);
Category::List readLoggingQtCategories(const QString &filename);
Category parseLineKdeLoggingCategory(QString line);
Category parseLineLoggingQtCategory(QString line);
Category::List readLoggingCategoriesForInserting(const QString &filename, Category::List &categoriesList);
}

#endif // KDEBUGSETTINGSUTIL_H
