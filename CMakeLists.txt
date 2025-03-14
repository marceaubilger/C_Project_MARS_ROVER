cmake_minimum_required(VERSION 3.27)
project(MARC C)

set(CMAKE_C_STANDARD 11)

# Set debugging
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create the build/ directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

file(GLOB SRC_FILES src/*.c)

add_executable(main main.c ${SRC_FILES})

target_include_directories(main PRIVATE src/)

add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/maps ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/maps
    COMMENT "Copying maps folder to output directory"
)

add_custom_target(main_exec
    DEPENDS main
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/./main
    COMMENT "Build and run"
)
