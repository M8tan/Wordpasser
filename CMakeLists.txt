cmake_minimum_required(VERSION 3.14)
project(cpp_add_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library
add_library(add_lib src/add.cpp)
target_include_directories(add_lib PUBLIC ${CMAKE_SOURCE_DIR}/src)

# use FetchContent to bring in GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# test executable
add_executable(test_add tests/test_add.cpp)
target_link_libraries(test_add PRIVATE add_lib gtest gtest_main)

# add test
add_test(NAME AddTest COMMAND test_add)

# generate XML when running ctest (ctest has --test-output= and gtest can output xml)
# We will run test executable directly in CI using GTEST_OUTPUT or gtest flag to produce XML
