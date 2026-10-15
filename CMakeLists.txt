cmake_minimum_required(VERSION 3.31)

project(Exercise01 LANGUAGES CXX)

# Use C++17 without compiler-specific extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Paths
set(SRC_DIR    "${CMAKE_CURRENT_SOURCE_DIR}/Src")
if(CI_RUN)
    set(TESTS_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/Ex01_CI_TESTS")
else()
    set(TESTS_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/Tests")
endif()

# ------------------------------------------------------------------------------
# Required student / provided files
# ------------------------------------------------------------------------------

# Group the student .cpp and provided .h files in one variable
set(REQUIRED_FILES
    "${SRC_DIR}/Queue.cpp"
    "${SRC_DIR}/Queue.h"
    "${SRC_DIR}/Stack.cpp"
    "${SRC_DIR}/Stack.h"
    "${SRC_DIR}/Utils.cpp"
    "${SRC_DIR}/Utils.h"
    "${SRC_DIR}/LinkedList.cpp"
    "${SRC_DIR}/LinkedList.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/.gitignore"
)

foreach(file IN LISTS REQUIRED_FILES)
    if(NOT EXISTS "${file}")
        message(FATAL_ERROR
            "Required file '${file}' is missing.\n"
            "Make sure all required source and header files are present "
            "in the expected Src directory.")
    endif()
endforeach()

# ------------------------------------------------------------------------------
# Library with student implementations
# ------------------------------------------------------------------------------

add_library(exercise_sources STATIC
    ${REQUIRED_FILES}
)

target_include_directories(exercise_sources
    PUBLIC
        "${SRC_DIR}"
)

# ------------------------------------------------------------------------------
# Test executables
# ------------------------------------------------------------------------------

set(TEST_TARGETS
    Ex1Part1_Test1
    Ex1Part1_Test2
    Ex1Part2_Test1
    Ex1Part2_Test2
    Ex1Part2_Test3
)

foreach(test_target IN LISTS TEST_TARGETS)
    add_executable(${test_target}
        "${TESTS_DIR}/${test_target}.cpp"
    )

    target_link_libraries(${test_target}
        PRIVATE
            exercise_sources
    )
endforeach()

# ------------------------------------------------------------------------------
# CTest integration
# ------------------------------------------------------------------------------

enable_testing()

# Each test is a standalone executable with the same name as the test
add_test(NAME Ex1Part1_Test1 COMMAND Ex1Part1_Test1)
add_test(NAME Ex1Part1_Test2 COMMAND Ex1Part1_Test2)

set_tests_properties(
    Ex1Part1_Test1
    Ex1Part1_Test2
    PROPERTIES
        LABELS "part1"
        TIMEOUT 120
)

add_test(NAME Ex1Part2_Test1 COMMAND Ex1Part2_Test1)
add_test(NAME Ex1Part2_Test2 COMMAND Ex1Part2_Test2)
add_test(NAME Ex1Part2_Test3 COMMAND Ex1Part2_Test3)

set_tests_properties(
    Ex1Part2_Test1
    Ex1Part2_Test2
    Ex1Part2_Test3
    PROPERTIES
        LABELS "part2"
        TIMEOUT 120
)
