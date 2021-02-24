//
// Created by loghin on 23.02.2021.
//

#include <AppWindow.h>
#include <LabSelectorPanel.h>
#include <QLayout>

AppWindow::~AppWindow() noexcept {
    this->pCentralLayout->removeWidget(this->pCentralWidget);

    delete this->pCentralWidget;
    delete this->pCentralLayout;
}

auto AppWindow::createComponents() noexcept -> AppWindow & {
    auto pNewCentralWidget = new LabSelectorPanel(this);
    pNewCentralWidget->initialise();

    this->pCentralWidget = pNewCentralWidget;
    this->pCentralLayout = new QVBoxLayout(this);

    return * this;
}

auto AppWindow::alignComponents() noexcept -> AppWindow & {
    this->setLayout(this->pCentralLayout);
    this->pCentralLayout->addWidget(this->pCentralWidget);

    return * this;
}

auto AppWindow::styleComponents() noexcept -> AppWindow & {
    return * this;
}

auto AppWindow::connectComponents() noexcept -> AppWindow & {
    return * this;
}