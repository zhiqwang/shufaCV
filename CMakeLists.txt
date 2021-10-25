cmake_minimum_required(VERSION 3.15)

# Disable inplace builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "FATAL: Building inplace are not allowed. You should create a separate directory for Building.")
endif()

# Set cmake_install_prefix path
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
endif()
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
endif()

if(CMAKE_TOOLCHAIN_FILE)
  # get absolute path, but get_filename_component ABSOLUTE only refer with source dir, so find_file here :(
  get_filename_component(CMAKE_TOOLCHAIN_FILE_NAME ${CMAKE_TOOLCHAIN_FILE} NAME)
  find_file(CMAKE_TOOLCHAIN_FILE ${CMAKE_TOOLCHAIN_FILE_NAME} PATHS ${CMAKE_SOURCE_DIR} NO_DEFAULT_PATH)
  message(STATUS "CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Set build type")
endif()

project(shufacv)

option(SHUFACV_TEST "Build unit tests?" OFF)

add_compile_options (-Wextra -Wall -Wno-unused)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(${CMAKE_SOURCE_DIR}/shufaCV SHUFACV_SRCS)

# Build NN shared library
add_library(
  ${PROJECT_NAME}
  STATIC
  ${SHUFACV_SRCS}
)
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}/shufaCV
)
# Build NN static library
add_library(
  ${PROJECT_NAME}_static
  STATIC
  ${SHUFACV_SRCS}
)
target_include_directories(
  ${PROJECT_NAME}_static
  PUBLIC ${CMAKE_SOURCE_DIR}/shufaCV
)

# Report summary
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/summary.cmake")

# Add install files
set_target_properties(
  ${PROJECT_NAME}_static
  PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME}
)
install(
  TARGETS ${PROJECT_NAME}
  DESTINATION lib
)
install(
  TARGETS ${PROJECT_NAME}_static
  DESTINATION lib
)

# Unit tests
if(SHUFACV_TEST)
  enable_testing()
  find_package(GTest REQUIRED)

  macro(shufacv_add_test name)
    add_executable(test_${name} tests/test_${name}.cpp)
    target_link_libraries(test_${name} PRIVATE shufacv GTest::gtest)
    gtest_add_tests(TARGET test_${name})
  endmacro()

  shufacv_add_test(mat)

endif()
