/*
    SPDX-FileCopyrightText: 2015-2023 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later

*/

#include "customdebugsettingspage.h"
#include "customdebuglistview.h"
#include "loggingmanager.h"

#include <KLocalizedString>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

CustomDebugSettingsPage::CustomDebugSettingsPage(QWidget *parent)
    : QWidget(parent)
    , mEditRule(new QPushButton(i18n("Edit..."), this))
    , mRemoveRule(new QPushButton(i18n("Remove..."), this))
    , mSearchLineEdit(new QLineEdit(this))
    , mCustomDebugListView(new CustomDebugListView(this))
{
    auto mainLayout = new QVBoxLayout(this);

    auto horizontalLayout = new QHBoxLayout;
    horizontalLayout->setContentsMargins({});
    mainLayout->addLayout(horizontalLayout);

    auto vbox = new QVBoxLayout;
    horizontalLayout->addLayout(vbox);

    vbox->addWidget(mSearchLineEdit);
    mSearchLineEdit->setClearButtonEnabled(true);
    mSearchLineEdit->setObjectName(QStringLiteral("mSearchLineEdit"));
    mSearchLineEdit->setPlaceholderText(i18n("Search..."));
    vbox->addWidget(mCustomDebugListView);
    mCustomDebugListView->setObjectName(QStringLiteral("mCustomDebugListView"));

    mCustomDebugListView->setLoggingCategoryModel(LoggingManager::self().customCategoryModel());
    auto buttonLayout = new QVBoxLayout;
    horizontalLayout->addLayout(buttonLayout);

    auto addRulePushButton = new QPushButton(i18n("Add..."), this);
    addRulePushButton->setObjectName(QStringLiteral("add_rule"));
    buttonLayout->addWidget(addRulePushButton);
    connect(addRulePushButton, &QAbstractButton::clicked, mCustomDebugListView, &CustomDebugListView::slotAddRule);

    mEditRule->setObjectName(QStringLiteral("edit_rule"));
    buttonLayout->addWidget(mEditRule);
    connect(mEditRule, &QAbstractButton::clicked, mCustomDebugListView, &CustomDebugListView::editRule);

    mRemoveRule->setObjectName(QStringLiteral("remove_rule"));
    buttonLayout->addWidget(mRemoveRule);
    buttonLayout->addStretch();
    connect(mRemoveRule, &QAbstractButton::clicked, mCustomDebugListView, &CustomDebugListView::removeRules);
    updateButtons();
    mSearchLineEdit->installEventFilter(this);
    connect(mSearchLineEdit, &QLineEdit::textChanged, mCustomDebugListView, &CustomDebugListView::setFilterRuleStr);
    connect(mCustomDebugListView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CustomDebugSettingsPage::updateButtons);
    connect(mCustomDebugListView, &CustomDebugListView::updateButtonsRequested, this, &CustomDebugSettingsPage::updateButtons);
}

CustomDebugSettingsPage::~CustomDebugSettingsPage() = default;

bool CustomDebugSettingsPage::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress && obj == mSearchLineEdit) {
        auto key = static_cast<QKeyEvent *>(event);
        if ((key->key() == Qt::Key_Enter) || (key->key() == Qt::Key_Return)) {
            event->accept();
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);
}

void CustomDebugSettingsPage::updateButtons()
{
    mEditRule->setEnabled(mCustomDebugListView->selectionModel()->selection().indexes().count() == 1);
    mRemoveRule->setEnabled(mCustomDebugListView->selectionModel()->hasSelection());
}

LoggingCategory::List CustomDebugSettingsPage::rules() const
{
    return LoggingManager::self().customCategoryModel()->loggingCategories();
}

#include "moc_customdebugsettingspage.cpp"
