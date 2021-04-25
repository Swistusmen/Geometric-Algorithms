set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

qt5_wrap_ui(UI_SOURCES QMainInterface.ui)

add_executable(${BINARY}_run ${SOURCES} ${UI_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Widgets)
target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Core)
target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Gui)

add_library(${BINARY}_lib STATIC ${SOURCES})