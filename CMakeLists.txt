cmake_minimum_required(VERSION 3.5)

project(sfml_drawer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS window graphics audio REQUIRED)

add_executable(sfml_drawer main.cpp game.cpp)

target_link_libraries(sfml_drawer sfml-window sfml-graphics sfml-audio)

