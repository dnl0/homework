cmake_minimum_required(VERSION 3.14)
project("IP Filter")

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ip_filter
  test.cc
  main.cpp
)

target_link_libraries(
  ip_filter
  GTest::gtest_main
)

add_test(NAME ip_filter COMMAND ip_filter)

include(GoogleTest)
gtest_discover_tests(ip_filter)
