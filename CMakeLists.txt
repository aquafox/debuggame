cmake_minimum_required (VERSION 2.8)
project (debuggame)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
# The version number.
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")
 
# configure a header file to pass some of the CMake settings
# to the source code
#configure_file (
#  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
#  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
#  )

# source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.c)
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/*.h)


# This project uses smart pointers, sdl needs a macro, tmxparser uses miniz instead of zlib, compile Ness-Engine statically.
add_definitions(-DSDL_MAIN_HANDLED -DUSE_MINIZ -DNESSENGINE_STATIC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

 
# add the executable
add_executable(debuggame ${SOURCES} ${HEADERS})

# Requird SDL2, SDL2_image, SDL2_ttf, tinyxml2
find_package(TinyXML2 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
set(LIBS ${LIBS} ${SDL2_LIBRARY})

include_directories(${SDLIMAGE_INCLUDE_DIR})
set(LIBS ${LIBS} ${SDLIMAGE_LIBRARY})

include_directories(${SDL2TTF_INCLUDE_DIR})
set(LIBS ${LIBS} ${SDL2TTF_LIBRARY})

include_directories(${TINYXML2_INCLUDE_DIRS})
set(LIBS ${LIBS} ${TINYXML2_LIBRARIES})

target_link_libraries(debuggame ${LIBS})