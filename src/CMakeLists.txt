set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
qt5_wrap_ui(SOURCES QMainInterface.ui)

include_directories(Algorihtms)
include_directories(ConsoleApplication)
include_directories(InputOutput)
include_directories(QtApplication)

add_executable(${BINARY}_run ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Widgets)
target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Core)
target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Gui)