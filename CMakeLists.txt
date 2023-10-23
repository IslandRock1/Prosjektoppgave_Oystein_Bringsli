cmake_minimum_required(VERSION 3.15)
project(Prosjektoppgave_Oystein_Bringsli)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

set(
        headers
        include/Vec3.hpp
        include/Particle.hpp
        include/ThreeppHandler.hpp
        include/ParticleHandler.hpp
)

set(
        sources
        src/Vec3.cpp
        src/main.cpp
        src/Particle.cpp
        src/ThreeppHandler.cpp
        src/ParticleHandler.cpp
)

add_executable(main ${sources} ${headers})

target_include_directories(main PUBLIC include)
target_link_libraries(main PRIVATE threepp::threepp)