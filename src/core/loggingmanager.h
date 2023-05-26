/*
    SPDX-FileCopyrightText: 2023 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later

*/
#pragma once
#include "kdebugsettingsloadingcategories.h"
#include "libkdebugsettingscore_export.h"
#include "model/categorytypemodel.h"
#include "model/customloggingcategorymodel.h"
#include "model/kdeapplicationloggingcategorymodel.h"
#include <QObject>
class LIBKDEBUGSETTINGSCORE_EXPORT LoggingManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CustomLoggingCategoryModel *customCategoryModel READ customCategoryModel CONSTANT)
    Q_PROPERTY(KDEApplicationLoggingCategoryModel *qtKdeCategoryModel READ qtKdeCategoryModel CONSTANT)
    Q_PROPERTY(CategoryTypeModel *categoryTypeModel READ categoryTypeModel CONSTANT)
    Q_PROPERTY(bool foundOverrideRule READ foundOverrideRule CONSTANT)

public:
    static LoggingManager &self();

    ~LoggingManager() override;

    Q_REQUIRED_RESULT CustomLoggingCategoryModel *customCategoryModel() const;

    Q_REQUIRED_RESULT KDEApplicationLoggingCategoryModel *qtKdeCategoryModel() const;

    Q_REQUIRED_RESULT CategoryTypeModel *categoryTypeModel() const;

    Q_INVOKABLE Q_REQUIRED_RESULT QString environmentrules() const;

    Q_REQUIRED_RESULT bool foundOverrideRule() const;

    // Remove it when we will port kdebugsettings to models.
    Q_REQUIRED_RESULT KDebugSettingsLoadingCategories loggings() const;

    void readCategoriesFiles(const QString &path);

    Q_REQUIRED_RESULT KdeLoggingCategory::List categoriesList() const;

private:
    LIBKDEBUGSETTINGSCORE_NO_EXPORT explicit LoggingManager(QObject *parent = nullptr);
    LIBKDEBUGSETTINGSCORE_NO_EXPORT void updateLoggingCategories();
    CustomLoggingCategoryModel *const mCustomCategoryModel;
    KDEApplicationLoggingCategoryModel *const mQtKdeCategoryModel;
    CategoryTypeModel *const mCategoryTypeModel;
    KDebugSettingsLoadingCategories mLoggings;
};
