cmake_minimum_required(VERSION 3.21)

set(CMAKE_GENERATOR_PLATFORM x64)

project(lost-souls)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(target ${PROJECT_NAME})

set(CMAKE_PDB_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

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