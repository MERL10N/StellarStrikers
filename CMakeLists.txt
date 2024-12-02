cmake_minimum_required(VERSION 3.29)
project(CS100_FinalProject)

set(CMAKE_CXX_STANDARD 17)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

# Add raylib to thirdparty folder
add_subdirectory(ThirdParty/raylib)

# Add googletest to thirdparty folder
add_subdirectory(ThirdParty/googletest)

include_directories(
  ${CMAKE_SOURCE_DIR}/ThirdParty/googletest/googletest/include/
  ${CMAKE_SOURCE_DIR}/ThirdParty/googletest/googlemock/include/
  ${CMAKE_SOURCE_DIR}/ThirdParty/raylib/raylib/include/
)


# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Source/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/Source/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

# Declaring our executable
add_executable(${PROJECT_NAME}
        Source/rocket.cpp
        Source/rocket.h)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Remove main.cpp from test sources
list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Declaring a separate test executable
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Tests/*.cpp")
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE gtest gtest_main raylib)
target_include_directories(${PROJECT_NAME}_tests PRIVATE ${PROJECT_INCLUDE})

# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/Assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable
# Setting ASSETS_PATH for the test executable
target_compile_definitions(${PROJECT_NAME}_tests PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/Assets/")