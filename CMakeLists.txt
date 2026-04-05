cmake_minimum_required(VERSION 3.14)
project(raytracer_challenge)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(raytracer src/tuple.cpp src/canvas.cpp)
target_include_directories(raytracer PUBLIC src)

add_executable(projectiles src/projectiles.cpp)
target_link_libraries(projectiles PRIVATE raytracer)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE raytracer)

add_executable(raytracer_tests tests/test_tuple.cpp tests/test_canvas.cpp)
target_link_libraries(raytracer_tests PRIVATE raytracer GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(raytracer_tests)
