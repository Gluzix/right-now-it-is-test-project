cmake_minimum_required(VERSION 3.16)

project(Project_1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appProject_1
    main.cpp
    MainManager.cpp
    MainManager.h
    ImageModel.cpp
    ImageModel.h
    ImageItem.cpp
    ImageItem.h
    ImageReader.cpp
    ImageReader.h
    ImageItemData.h
    VideoCreator.h
    VideoCreator.cpp
    FfmpegHandler.h
    FfmpegHandler.cpp
)

qt_add_qml_module(appProject_1
    URI Project_1
    VERSION 1.0
    QML_FILES Main.qml
    MainView.qml
    MainViewItem.qml
    ImageDialog.qml
    trashcan-svgrepo-com.svg
    attach-svgrepo-com.svg
    video-file-svgrepo-com.svg
    zoom-out-svgrepo-com.svg
    zoom-in-svgrepo-com.svg
)

find_path(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h)
find_library(AVCODEC_LIBRARY avcodec)

find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h)
find_library(AVFORMAT_LIBRARY avformat)

find_path(AVUTIL_INCLUDE_DIR libavutil/avutil.h)
find_library(AVUTIL_LIBRARY avutil)

find_path(AVDEVICE_INCLUDE_DIR libavdevice/avdevice.h)
find_library(AVDEVICE_LIBRARY avdevice)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appProject_1 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appProject_1
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appProject_1 PRIVATE ${AVCODEC_INCLUDE_DIR} ${AVFORMAT_INCLUDE_DIR} ${AVUTIL_INCLUDE_DIR} ${AVDEVICE_INCLUDE_DIR})


target_link_libraries(appProject_1
    PRIVATE Qt6::Quick ${AVCODEC_LIBRARY} ${AVFORMAT_LIBRARY} ${AVUTIL_LIBRARY} ${AVDEVICE_LIBRARY}
)

include(GNUInstallDirs)
install(TARGETS appProject_1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
