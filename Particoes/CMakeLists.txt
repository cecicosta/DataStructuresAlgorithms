cmake_minimum_required (VERSION 2.8.9)
project (EDAListasQ6)

set (SOURCES_DIR "${CMAKE_SOURCE_DIR}") 
set (HEADERS_DIR "${CMAKE_SOURCE_DIR}") 

# add the binary tree to the search path for include files
include_directories("${HEADERS_DIR}")

file(GLOB SOURCES "${SOURCES_DIR}/*.c")

# add the executable
add_executable(EDAListasQ6 ${SOURCES})
