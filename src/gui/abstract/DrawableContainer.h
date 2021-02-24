//
// Created by loghin on 23.02.2021.
//

#ifndef CN_21_DRAWABLECONTAINER_H
#define CN_21_DRAWABLECONTAINER_H

class DrawableContainer {
public:
    virtual auto initialise () noexcept -> DrawableContainer & = 0;
    virtual auto createComponents () noexcept -> DrawableContainer & = 0;
    virtual auto alignComponents () noexcept -> DrawableContainer & = 0;
    virtual auto styleComponents () noexcept -> DrawableContainer & = 0;
    virtual auto connectComponents () noexcept -> DrawableContainer & = 0;
};

#endif //CN_21_DRAWABLECONTAINER_H
