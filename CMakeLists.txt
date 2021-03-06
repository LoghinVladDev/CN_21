cmake_minimum_required(VERSION 3.17)
project(CN_21)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "/home/loghin/Qt6/6.0.1/gcc_64")

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS})

add_subdirectory(dependencies/dataStructures)
include_directories(dependencies/dataStructures/src)
include_directories(dependencies/dataStructures/src/collection)
include_directories(dependencies/dataStructures/src/collection/ordered)
include_directories(dependencies/dataStructures/src/collection/unordered)
include_directories(dependencies/dataStructures/src/exception)
include_directories(dependencies/dataStructures/src/primitive)

if(Qt${QT_VERSION}_FOUND)

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)

    set(
            GUI_DIRS
            src/gui
            src/gui/frame
            src/gui/panel
            src/gui/component
            src/gui/abstract
    )

    set(
            GUI_SRC
            src/gui/frame/AppWindow.cpp
            src/gui/frame/AppWindow.h
            src/gui/panel/LabSelectorPanel.cpp
            src/gui/panel/LabSelectorPanel.h
            src/gui/abstract/DrawableContainer.h
            src/gui/component/LabListItem.cpp
            src/gui/component/LabListItem.h
            src/gui/settings/Settings.cpp src/gui/settings/Settings.h)

    include_directories(${GUI_DIRS})

    add_executable(${PROJECT_NAME} main.cpp ${GUI_SRC} dependencies/dataStructures/src/primitive/String.cpp)

    if (NOT CMAKE_PREFIX_PATH)
        message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
                "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
    endif ()

    target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

endif()