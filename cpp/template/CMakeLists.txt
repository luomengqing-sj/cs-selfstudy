cmake_minimum_required(VERSION 3.16)
project(template CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-fsanitize=address,undefined -g)
add_link_options(-fsanitize=address,undefined)

add_executable(demo src/main.cpp)
