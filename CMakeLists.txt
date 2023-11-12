cmake_minimum_required(VERSION 3.15)
project(Prosjektoppgave_Oystein_Bringsli)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(examples)