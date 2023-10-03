cmake_minimum_required(VERSION 3.15)
project(Prosjektoppgave_Øystein_Bringsli)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(demo main.cpp)
target_link_libraries(demo PRIVATE threepp::threepp imgui::imgui)
