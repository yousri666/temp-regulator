cmake_minimum_required(VERSION 3.14)
project(Thermostat LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

set(TARGET_NAME test_thermostat)

#find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${TARGET_NAME} Thermostat.cpp Thermostat_test.cpp)

target_link_libraries(${TARGET_NAME} GTest::gtest_main gmock pthread)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${TARGET_NAME})
