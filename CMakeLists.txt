cmake_minimum_required(VERSION 3.15)
project(Prosjektoppgave_Oystein_Bringsli)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(demo src/main.cpp
        include/Vec2.hpp
        src/Vec2.cpp)
target_link_libraries(demo PRIVATE threepp::threepp imgui::imgui)
