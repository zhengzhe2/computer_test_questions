CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(Computer_Test)

add_definitions(-D LINUX_OS)

SET(SRC_FILES
        "test_case_HJ1.c"
        "test_case_OK1.c")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(programming_questions_test main.c ${SRC_FILES})