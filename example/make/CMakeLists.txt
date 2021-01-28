cmake_minimum_required(VERSION 3.0.0)
project(test VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -g -Wall")

add_executable(example5 src/main.cpp)
target_sources(example5 INTERFACE src/utils.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(../../src)
include_directories(/usr/local/opt/freetype/include/freetype2)
find_library(FREETYPE_LIBRARY
    freetype
)
target_link_libraries(example5 PUBLIC ${FREETYPE_LIBRARY})
find_library(RAQM_LIBRARY
    raqm
    PATH ../../src/.libs
)
target_link_libraries(example5 PUBLIC ${RAQM_LIBRARY})