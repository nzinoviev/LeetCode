set(TARGET_NAME "RomanToInteger")

add_executable(${TARGET_NAME} main.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE gtest gtest_main)