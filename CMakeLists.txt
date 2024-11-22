# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(FinalProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    Source/gameManager.cpp
    Source/health.cpp
    Source/main.cpp
    Source/player.cpp
)

# Add header files (optional, for IDE support)
set(HEADERS
    Source/gameManager.h
    Source/health.h
    Source/player.h
)

# Include the third-party libraries
include_directories(Source ThirdParty/gtest/include ThirdParty/raylib/include)

# Option 1: Use Raylib system-wide (if installed)
find_package(raylib QUIET) # Use system-installed Raylib if available

if (NOT raylib_FOUND) # If Raylib is not found, use the third-party folder
    add_subdirectory(ThirdParty/raylib)
endif()

# Option 2: Add gtest from the third-party folder
add_subdirectory(ThirdParty/gtest)

# Add executable for the main program
add_executable(FinalProject ${SOURCES})

# Link Raylib to the main executable
if (raylib_FOUND)
    target_link_libraries(FinalProject raylib)
else()
    target_link_libraries(FinalProject raylib_static)
endif()

# Add test executable
add_executable(Test Tests/Test.cpp ${SOURCES})

# Link gtest and Raylib to the test executable
target_link_libraries(Test gtest gtest_main raylib_static)

# Include directories for Raylib
if (raylib_FOUND)
    target_include_directories(FinalProject PRIVATE ${RAYLIB_INCLUDE_DIRS})
    target_include_directories(Test PRIVATE ${RAYLIB_INCLUDE_DIRS})
endif()