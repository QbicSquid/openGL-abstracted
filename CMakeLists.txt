cmake_minimum_required(VERSION 3.21.3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(abstracted)

file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
add_executable(${CMAKE_PROJECT_NAME} ${sources})

find_package(OpenGL REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC OpenGL::GL)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC GLEW)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
                          "${PROJECT_SOURCE_DIR}/src")

#add_subdirectory(sub_dir_to_add)

