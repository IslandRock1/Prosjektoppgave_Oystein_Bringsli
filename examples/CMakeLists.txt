
add_executable(GravityBetweenParticles GravityBetweenParticles.cpp
        SimpleExample.cpp)
target_link_libraries(GravityBetweenParticles PRIVATE ParticleSim)

add_executable(GravityToGround GravityToGround.cpp)
target_link_libraries(GravityToGround PRIVATE ParticleSim)

add_executable(GravityToCenter GravityToCenter.cpp)
target_link_libraries(GravityToCenter PRIVATE ParticleSim)

add_executable(SimpleExample SimpleExample.cpp)
target_link_libraries(SimpleExample PRIVATE ParticleSim)