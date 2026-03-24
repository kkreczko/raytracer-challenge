cmake_minimum_required(VERSION 3.14)
project(raytracer_challenge)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# add_library()
# target_include_directories()

add_executable(main src/main.cpp)
# target_link_libraries()

include(GoogleTest)
# gtest_discover_tests()
