/*
    SPDX-FileCopyrightText: 2015-2020 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later

*/

#include "environmentsettingsrulespage.h"
#include "environmentplaintextedit.h"
#include <QVBoxLayout>
#include <QLabel>
#include <KLocalizedString>

EnvironmentSettingsRulesPage::EnvironmentSettingsRulesPage(QWidget *parent)
    : QWidget(parent)
{
    auto mainLayout = new QVBoxLayout(this);
    auto lab = new QLabel(i18n("Rules:"), this);
    lab->setObjectName(QStringLiteral("label"));
    mRichTextEdit = new EnvironmentPlainTextEdit(this);
    mRichTextEdit->setReadOnly(true);
    mRichTextEdit->setObjectName(QStringLiteral("richtext"));
    mainLayout->addWidget(lab);
    mainLayout->addWidget(mRichTextEdit);
}

EnvironmentSettingsRulesPage::~EnvironmentSettingsRulesPage()
{
}

void EnvironmentSettingsRulesPage::setRules(const QString &rules)
{
    const QString information = QLatin1String("<qt><b>") + i18n("These rules cannot be edited with this application. You need to set them in QT_LOGGING_RULES variable directly.") + QLatin1String(
        "</b><qt>");
    QString newRules = rules;
    mRichTextEdit->setHtml(information + i18n("Current rules:") + QStringLiteral("<br>") + newRules.replace(QLatin1Char('\n'), QLatin1String("<br>")));
}
