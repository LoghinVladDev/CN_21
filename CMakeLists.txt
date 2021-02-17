cmake_minimum_required(VERSION 3.17)
project(CN_21)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "/home/loghin/Qt6/6.0.1/gcc_64")

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS})

if(Qt${QT_VERSION}_FOUND)

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)

    add_executable(${PROJECT_NAME} main.cpp)

    if (NOT CMAKE_PREFIX_PATH)
        message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
                "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
    endif ()

    target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

endif()