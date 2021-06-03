cmake_minimum_required(VERSION 3.12)

project(c_impl)

# Define sources and executable
set(EXECUTABLE_NAME "c_impl")

file(GLOB source_files
    "${CMAKE_SOURCE_DIR}/src/*"
)

add_executable(${EXECUTABLE_NAME} ${source_files})

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

