//
// Created by loghin on 24.02.2021.
//

#ifndef CN_21_SETTINGS_H
#define CN_21_SETTINGS_H

#include <LinkedList.hpp>
#include <Pair.hpp>
#include <HashMap.hpp>

class Settings {

private:
    static Settings * pInstance;
    static HashMap < String, LinkedList < Pair < uint32, uint32 > > > allResolutions;

    decltype(allResolutions) availableResolutions;

    auto loadResolutions() noexcept -> void;

    Settings () noexcept {
        this->loadResolutions();
    }

public:
    static auto getInstance () noexcept -> Settings & {
        if ( Settings::pInstance == nullptr )
            Settings::pInstance = new Settings();

        return * Settings::pInstance;
    }
};


#endif //CN_21_SETTINGS_H
