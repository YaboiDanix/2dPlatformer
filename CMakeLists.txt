cmake_minimum_required(VERSION 4.3)
project(SFML_Starter)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML COMPONENTS Graphics Audio Window System CONFIG REQUIRED)
find_package(box2d CONFIG REQUIRED)

add_subdirectory(Starter)
add_subdirectory(Box2D_Starter)
