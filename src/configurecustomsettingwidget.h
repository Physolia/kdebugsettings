/*
    SPDX-FileCopyrightText: 2015-2020 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later

*/

#ifndef CONFIGURECUSTOMSETTINGWIDGET_H
#define CONFIGURECUSTOMSETTINGWIDGET_H

#include <QWidget>
#include "libkdebugsettings_private_export.h"
class KLineEdit;
class QCheckBox;
class CategoryTypeComboBox;
class LIBKDEBUGSETTINGS_EXPORT_TEST_EXPORT ConfigureCustomSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigureCustomSettingWidget(QWidget *parent = nullptr);
    ~ConfigureCustomSettingWidget() override;

    Q_REQUIRED_RESULT QString rule() const;
    void setRule(const QString &rule);

Q_SIGNALS:
    void enableButton(bool state);

private:
    void slotTextChanged(const QString &);

    KLineEdit *mCategoryLineEdit = nullptr;
    QCheckBox *mEnableCategory = nullptr;
    CategoryTypeComboBox *mCategoryType = nullptr;
};

#endif // CONFIGURECUSTOMSETTINGWIDGET_H
