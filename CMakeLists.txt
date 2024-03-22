cmake_minimum_required(VERSION 3.24)

project(S24_Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(glfw)
add_subdirectory(myEngine)
add_subdirectory(S24_Dariel_Martinez)


set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Game)