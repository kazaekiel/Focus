cmake_minimum_required(VERSION 3.16)

project(Focus VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)


set(SOURCES
    src/main.cpp
    src/domain/PomodoroTimer.cpp
    src/utils/casters.cpp)

set(HEADERS
    src/domain/PomodoroTimer.h
    src/utils/casters.h)

qt_add_executable(appFocus ${SOURCES} ${HEADERS})

qt_add_qml_module(appFocus
    URI Focus
    QML_FILES
        qml/Main.qml
        SOURCES src/viewmodels/timerviewmodel.h src/viewmodels/timerviewmodel.cpp
        SOURCES src/utils/casters.h src/utils/casters.cpp
        QML_FILES qml/Configuration.qml
        QML_FILES qml/TimerPage.qml
)

target_include_directories(appFocus PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appFocus PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appFocus
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFocus
    PRIVATE Qt6::Quick
)

install(TARGETS appFocus
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
