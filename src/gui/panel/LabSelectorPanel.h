//
// Created by loghin on 23.02.2021.
//

#ifndef CN_21_LABSELECTORPANEL_H
#define CN_21_LABSELECTORPANEL_H

#include <AppWindow.h>
#include <QListWidget>

class LabSelectorPanel final : public QWidget, public DrawableContainer {
    Q_OBJECT

private:
    AppWindow   * pParent       { nullptr };
    QListWidget * pEntryList    { nullptr };

public:
    explicit LabSelectorPanel ( AppWindow * pParent ) noexcept : pParent(pParent) { }
    ~LabSelectorPanel() noexcept final;

    auto initialise() noexcept -> LabSelectorPanel &;
    auto createComponents() noexcept -> LabSelectorPanel &;
    auto alignComponents() noexcept -> LabSelectorPanel &;
    auto styleComponents() noexcept -> LabSelectorPanel &;
    auto connectComponents() noexcept -> LabSelectorPanel &;
};


#endif //CN_21_LABSELECTORPANEL_H
