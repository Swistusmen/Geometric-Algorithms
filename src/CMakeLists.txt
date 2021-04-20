set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ui)

set(SOURCES ${SOURCES})

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

add_executable(${BINARY}_run ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Widgets)
target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Core)
target_link_libraries(${CMAKE_PROJECT_NAME}_run Qt5::Gui)

add_library(${BINARY}_lib STATIC ${SOURCES})