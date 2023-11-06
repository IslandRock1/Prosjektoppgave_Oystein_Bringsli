cmake_minimum_required(VERSION 3.15)
project(Prosjektoppgave_Oystein_Bringsli)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(examples)

add_library(ParticleSim
        src/Vec3.cpp
        src/Particle.cpp
        src/ThreeppHandler.cpp
        src/ParticleHandler.cpp
        src/GravityControl.cpp
)

target_include_directories(ParticleSim PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ParticleSim PUBLIC threepp::threepp)