cmake_minimum_required(VERSION 3.12)
project(ConcordancesTests)

set(CMAKE_CXX_STANDARD 17)

include_directories(../lib)
set(Main main.cpp)
set(Sources
    ConcordanceParser.test.cpp
        )

add_subdirectory(vendor/catch)

add_executable(${PROJECT_NAME} ${Main} ${Sources})
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
target_link_libraries(${PROJECT_NAME} PRIVATE ConcordancesLib)