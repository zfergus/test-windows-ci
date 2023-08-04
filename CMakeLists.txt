cmake_minimum_required(VERSION "3.14.0")

project(TestWindowsCI LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/recipes/")

# Generate position independent code by default
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

################################################################################
# Tests
################################################################################

add_executable(test test.cpp)

################################################################################
# Required Libraries
################################################################################

include(catch2)
target_link_libraries(test PUBLIC Catch2::Catch2WithMain)

include(json)
target_link_libraries(test PUBLIC nlohmann_json::nlohmann_json)

################################################################################
# Register tests
################################################################################

FetchContent_GetProperties(catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

# Register tests
set(PARSE_CATCH_TESTS_ADD_TO_CONFIGURE_DEPENDS ON)
catch_discover_tests(test)