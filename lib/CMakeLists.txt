cmake_minimum_required(VERSION 3.12)
project(ConcordancesLib)

set(CMAKE_CXX_STANDARD 17)

include_directories(public )
set(Sources
        ConcordanceParser.cpp
)

set(Headers
        ConcordanceParser.h
)

add_library(ConcordancesLib ${Sources} ${Headers})
