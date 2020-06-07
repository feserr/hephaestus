cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

set(NAME hephaestus)
set(REPO_VERSION 1.0.0)

project(${NAME} VERSION ${REPO_VERSION} DESCRIPTION "Utils library")

set(CMAKE_C_STANDARD 99)

# Set the debug or relese mode.
if (CMAKE_BUILD_TYPE MATCHES Debug)
  # Debug level
  add_definitions(-DDEBUG)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
  # Optimization level
else ()
  message(FATAL_ERROR "Set the build type with -DCMAKE_BUILD_TYPE=<type>")
endif()

set(SOURCE_FILES
  src/log.c)

set(HEADER_PATHS include)
set(HEADER_FILES
  include/hephaestus/log.h)

include_directories(${HEADER_PATHS})

add_library(${NAME} SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_library(hephaestus::hephaestus ALIAS ${NAME})

# Set the debug or relese mode.
if (CMAKE_BUILD_TYPE MATCHES Debug)
  # Debug level
  add_definitions(-DDEBUG)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
  # Optimization level
else ()
  message(FATAL_ERROR "Set the build type with -DCMAKE_BUILD_TYPE=<type>")
endif()

include(GenerateExportHeader)
generate_export_header(${NAME})

target_include_directories(${NAME}
  PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})