cmake_minimum_required(VERSION 3.23)
project(MidiPlayer)

set(CMAKE_CXX_STANDARD 11)

link_libraries(winmm)

file(GLOB_RECURSE QRC_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)

find_package(Qt6 COMPONENTS Widgets Core Gui REQUIRED)

qt_standard_project_setup()

if(MSVC)
    add_compile_options(/Zc:__cplusplus)
    add_compile_options(/permissive-)
    add_compile_options(/utf-8)
endif ()


set(QRC_SOURCE_FILES Resources.qrc)

qt_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

SOURCE_GROUP("Resource Files" FILES ${QRC_SOURCE_FILES})

include_directories(3rdparty/include)
aux_source_directory(3rdparty/src DIR_SRCS)

add_executable(MidiPlayer ${DIR_SRCS}
        main.cpp
        MIDIPlayer.cpp
        MIDIPlayer.h
        mainview.cpp
        mainview.h
        mainview.ui
        pianowidget.cpp
        pianowidget.h
        picturewidget.cpp
        picturewidget.h
        picturewidget.ui
        ${QRC_FILES}
)

target_link_libraries(MidiPlayer PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)