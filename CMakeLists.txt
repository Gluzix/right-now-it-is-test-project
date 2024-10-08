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

target_link_libraries(appProject_1
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appProject_1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
