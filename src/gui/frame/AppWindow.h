//
// Created by loghin on 23.02.2021.
//

#ifndef CN_21_APPWINDOW_H
#define CN_21_APPWINDOW_H

#include <QWidget>
#include <abstract/DrawableContainer.h>

class AppWindow final : public QWidget, public DrawableContainer {
    Q_OBJECT

private:
    QWidget * pCentralWidget { nullptr };
    QLayout * pCentralLayout { nullptr };

public:
    AppWindow ( ) noexcept : QWidget(nullptr) { }
    ~AppWindow() noexcept final;

    auto initialise () noexcept -> AppWindow & final {
        return this
            ->createComponents()
            .alignComponents()
            .styleComponents()
            .connectComponents();
    }

    auto createComponents () noexcept -> AppWindow & final;
    auto alignComponents () noexcept -> AppWindow & final;
    auto styleComponents () noexcept -> AppWindow & final;
    auto connectComponents () noexcept -> AppWindow & final;
};


#endif //CN_21_APPWINDOW_H
