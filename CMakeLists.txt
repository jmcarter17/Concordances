cmake_minimum_required(VERSION 3.12)
project(Concordances)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib)
add_subdirectory(tests)

set(Sources main.cpp)

add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} PRIVATE ConcordancesLib)