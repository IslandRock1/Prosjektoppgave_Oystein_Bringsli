cmake_minimum_required(VERSION 3.15)
project(Prosjektoppgave_Oystein_Bringsli)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

set(
        headers
        include/Vec2.hpp
        include/ThreeppHandler.hpp
)

set(
        sources
        src/main.cpp
        src/Vec2.cpp
        src/ThreeppHandler.cpp
)

add_executable(main ${sources} ${headers})

target_include_directories(main PUBLIC include)
target_link_libraries(main PRIVATE threepp::threepp)