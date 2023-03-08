CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(PRIVATE_MODULE_NAME programming_questions_test)

project(${PRIVATE_MODULE_NAME})

add_definitions(-D LINUX_OS)

SET(SRC_FILES
        "test_case_OK1.c"
        "test_case_OK2.c"
        "test_case_HJ1.c"
        "test_case_HJ2.c"
        "test_case_HJ3.c"
        "test_case_HJ4.c"
        "test_case_HJ5.c"
        "test_case_HJ6.c")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(${PRIVATE_MODULE_NAME} main.c ${SRC_FILES})

target_link_libraries(${PRIVATE_MODULE_NAME} -lpthread -lm)