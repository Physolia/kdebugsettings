/*
    SPDX-FileCopyrightText: 2023 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "loggingcategorymodel.h"

LoggingCategoryModel::LoggingCategoryModel(QObject *parent)
    : QAbstractListModel{parent}
{
    mRoleNames.insert(Qt::DisplayRole, "display");
    mRoleNames.insert(DescriptionRole, "description");
    mRoleNames.insert(CategoryNameRole, "categoryName");
    mRoleNames.insert(IdentifierNameRole, "identifierName");
    mRoleNames.insert(DefaultCategoryRole, "defaultCategory");
    mRoleNames.insert(DisplayRuleRole, "displayRule");
    mRoleNames.insert(LoggingTypeRole, "loggingType");
}

LoggingCategoryModel::~LoggingCategoryModel() = default;

int LoggingCategoryModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0; // flat model
    }
    return mLoggingCategories.count();
}

QVariant LoggingCategoryModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= mLoggingCategories.count()) {
        return {};
    }

    const LoggingCategory &category = mLoggingCategories.at(index.row());
    switch (role) {
    case DescriptionRole:
        return category.description;
    case CategoryNameRole:
        return category.categoryName;
    case IdentifierNameRole:
        return category.identifierName;
    case Qt::ToolTipRole:
        return category.generateToolTip();
    case DefaultCategoryRole:
        return category.defaultSeverityType;
    case Qt::DisplayRole:
    case DisplayRuleRole:
        return category.generateDisplayRule();
    case LoggingTypeRole:
        return category.loggingType;
    }
    return {};
}

void LoggingCategoryModel::setLoggingCategories(const LoggingCategory::List &list)
{
    beginResetModel();
    mLoggingCategories = list;
    endResetModel();
}

void LoggingCategoryModel::clear()
{
    if (!mLoggingCategories.isEmpty()) {
        beginResetModel();
        mLoggingCategories.clear();
        endResetModel();
    }
}

QHash<int, QByteArray> LoggingCategoryModel::roleNames() const
{
    return mRoleNames;
}
