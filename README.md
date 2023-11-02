# 3D Particle Simulator (Work in progress)

This is a physically based simulator that renders and simulates particle collision and gravity in 3D.
The project is largely based on a previous project of mine for a similar simulation in 2D.

### Current state
As of 10.10.23 the project is still in the start phase, and not ready to be used.

Update: As of 01.11.23 the project is runnable with three different example configurations. The configuration of particle spawn is very poorly designed currently, but will be better shortly.

### Todo:
    General cleanup and user excperience/configuring (Priority 1)
        Specificly add where particles are spawned, and if all particles should be created at start.
    Add KeyListener to be able to get user input while running (Priority 2)
    FPS and dt text is currently only time for particle calculation, and not rendering (Quick fix)
    Better README
    Fix border / Outline. Going to look at boid example from threepp
    Implement better searching algorithm for particle collisions (Most fun)
    Implement a way to save picture/video that scales when simuation can not run at 60 FPS

### How to build?
This simulation uses threepp to render.

### Notes on implementation
This simulation is built to act as an 80% physically based simulation, and 20% visually belivable/pleasing. This means that some of the friction and gravity calculation will not be 100% physicly accurate. This simulation also uses verlet integration, witch is also not perfectly accurate.
