
add_library(ParticleSim
        Vec3.cpp
        Particle.cpp
        ThreeppHandler.cpp
        ParticleHandler.cpp
        GravityControl.cpp
        MyKeyListener.cpp
)

target_include_directories(ParticleSim PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ParticleSim PUBLIC threepp::threepp)