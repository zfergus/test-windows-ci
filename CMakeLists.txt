cmake_minimum_required(VERSION "3.14.0")

project(TestWindowsCI LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/recipes/")

# Set default minimum C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate position independent code by default
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(CTest)
enable_testing()

################################################################################
# Tests
################################################################################

add_executable(unit_tests test.cpp)

# Use C++17
target_compile_features(unit_tests PUBLIC cxx_std_17)

################################################################################
# Required Libraries
################################################################################

include(catch2)
target_link_libraries(unit_tests PUBLIC Catch2::Catch2WithMain)

include(json)
target_link_libraries(unit_tests PUBLIC nlohmann_json::nlohmann_json)

################################################################################
# Register tests
################################################################################

FetchContent_GetProperties(catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

# Register tests
set(PARSE_CATCH_TESTS_ADD_TO_CONFIGURE_DEPENDS ON)
catch_discover_tests(unit_tests)