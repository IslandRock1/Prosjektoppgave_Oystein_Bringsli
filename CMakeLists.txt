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
        include/GravityControl.hpp
)

set(
        sources
        src/Vec3.cpp
        src/main.cpp
        src/Particle.cpp
        src/ThreeppHandler.cpp
        src/ParticleHandler.cpp
        src/GravityControl.cpp
)

add_subdirectory(src)
add_subdirectory(examples)

add_library(ParticleSim
        src/Vec3.cpp
        src/main.cpp
        src/Particle.cpp
        src/ThreeppHandler.cpp
        src/ParticleHandler.cpp
        src/GravityControl.cpp
)

#No idea if this is implemented right, probably not.
#Wanted to make an examples folder to showcase different configurations.
target_include_directories(ParticleSim
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

add_executable(main ${sources} ${headers})

target_include_directories(main PUBLIC include)
target_link_libraries(main PUBLIC threepp::threepp)
target_link_libraries(ParticleSim PUBLIC threepp::threepp)