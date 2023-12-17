cmake_minimum_required(VERSION 3.10)

project(Main VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Jeans)

add_executable(Main main.cpp)

target_link_libraries(Main PUBLIC jeans)

target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/Jeans/"
                            )    
