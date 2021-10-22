CMAKE_MINIMUM_REQUIRED (VERSION 3.0)

# Disable inplace builds to prevent source tree corruption.
IF (" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    MESSAGE (FATAL_ERROR "FATAL: Building inplace are not allowed. You should create a separate directory for Building.")
ENDIF ()

# Set cmake_install_prefix path
IF (NOT DEFINED CMAKE_INSTALL_PREFIX)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
ENDIF ()
MESSAGE (STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

IF (NOT DEFINED CMAKE_INSTALL_PREFIX)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
ENDIF ()

IF (CMAKE_TOOLCHAIN_FILE)
    # get absolute path, but get_filename_component ABSOLUTE only refer with source dir, so find_file here :(
    get_filename_component(CMAKE_TOOLCHAIN_FILE_NAME ${CMAKE_TOOLCHAIN_FILE} NAME)
    find_file(CMAKE_TOOLCHAIN_FILE ${CMAKE_TOOLCHAIN_FILE_NAME} PATHS ${CMAKE_SOURCE_DIR} NO_DEFAULT_PATH)
    MESSAGE (STATUS "CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
ENDIF()

IF (NOT DEFINED CMAKE_BUILD_TYPE)
    SET (CMAKE_BUILD_TYPE Release CACHE STRING "Set build type")
ENDIF ()

PROJECT (shufacv)

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wextra -Wno-unused -Wfloat-equal -Wshadow -Wcast-qual -Wsign-compare -Wunreachable-code")
SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wextra -Wno-unused -Wfloat-equal -Wshadow -Wbad-function-cast -Wcast-qual -Wsign-compare -Waggregate-return -Wunreachable-code -Wstrict-prototypes")

ADD_DEFINITIONS (-std=gnu++11)

AUX_SOURCE_DIRECTORY (${CMAKE_SOURCE_DIR}/shufaCV SHUFACV_SRCS)

# Build NN shared library
ADD_LIBRARY (
    ${PROJECT_NAME}
    SHARED
    ${SHUFACV_SRCS}
)
TARGET_INCLUDE_DIRECTORIES (
    ${PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/shufaCV
)
# Build NN static library
ADD_LIBRARY (
    ${PROJECT_NAME}_static
    STATIC
    ${SHUFACV_SRCS}
)
TARGET_INCLUDE_DIRECTORIES (
    ${PROJECT_NAME}_static
    PUBLIC ${CMAKE_SOURCE_DIR}/shufaCV
)

# Report summary
INCLUDE ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/summary.cmake")

# Add install files
SET_TARGET_PROPERTIES (
    ${PROJECT_NAME}_static
    PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
)
INSTALL (
    TARGETS ${PROJECT_NAME}
    DESTINATION lib
)
INSTALL (
    TARGETS ${PROJECT_NAME}_static
    DESTINATION lib
)
