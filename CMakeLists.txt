cmake_minimum_required(VERSION 3.21)

project(lost-souls)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(target ${PROJECT_NAME})

file(GLOB SOURCE_FILES
    src/main.cpp
    src/*/*.cpp
)

add_executable(${target}
    ${SOURCE_FILES}
)

target_include_directories(${target}
    PRIVATE src
)