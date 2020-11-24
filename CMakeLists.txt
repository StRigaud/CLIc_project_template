# cmake minimum version
cmake_minimum_required(VERSION 3.0)

# project name
project(clic_script)

# find required libraries
find_package(OpenCL REQUIRED)
find_package(TIFF REQUIRED)
find_package(CLIc REQUIRED)

# list source files
set( sources
  script.cpp
  )

# define compilation target and linkage
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} CLIc::CLIc)


