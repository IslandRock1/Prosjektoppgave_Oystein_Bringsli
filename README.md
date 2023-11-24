# 3D Particle Simulator (Work in progress)

This is a physically based simulator that renders and simulates particle collision and gravity in 3D.
The project is largely based on a previous project of mine for a similar simulation in 2D.

### Current state
As of 22.11.23 the simulation library is in working condition. It still needs a lot in terms of being user firendly, and a lot of optimization.

### Todo:
    Implement better searching algorithm for particle collisions.
    Implement a way to save picture/video that scales when simuation can not run at 60 FPS

### How to build?
This simulation uses threepp to render. Witch means you might need these in the CMake build profile:
    
    -DVCPKG_TARGET_TRIPLET=x64-mingw-[DYNAMIC|STATIC]
    -DVCPKG_HOST_TRIPLET=x64-mingw-[DYNAMIC|STATIC]

### Notes on implementation
This simulation is built to act as an 80% physically based simulation, and 20% visually belivable/pleasing. This means that some of the friction and gravity calculation will not be 100% physicly accurate. This simulation also uses verlet integration, witch is also not perfectly accurate.

### Controls
You can change the max number of particles during runtime by using the "U" and "I" keys. You can also move the spawning point by using WASDQE keys. To see the spawn point of particles hold "G"
