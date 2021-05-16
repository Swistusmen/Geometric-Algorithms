set (CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\msvc2019_64\\lib\\cmake")
set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_qt ${SOURCES})
