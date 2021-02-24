//
// Created by loghin on 24.02.2021.
//

 #include "Settings.h"

Settings * Settings::pInstance = nullptr;

decltype(Settings::allResolutions) Settings::allResolutions = {
    { "4:3", {
        { 640, 480 },
        { 800, 600 },
        { 1024, 768 },
        { 1280, 960 },
        { 1440, 1080 }
    } } ,
    { "16:9", {
        { 1280, 720 },
        { 1366, 768 },
        { 1600, 900 },
        { 1920, 1080 },
        { 2560, 1440 },
        { 3840, 2160 },
    } }
};

#include <QGuiApplication>
#include <QScreen>
auto Settings::loadResolutions() noexcept -> void {
    auto screenResolution = QGuiApplication::screens()[0]->size();

    allResolutions.entries().forEach([this, &screenResolution](auto & pair){
        if ( pair.getFirst().get() <= screenResolution.width() && pair.getSecond().get() <= screenResolution.height() )
            this->availableResolutions.emplace( pair.getFirst().get(), pair.getSecond().get() );
    });
}