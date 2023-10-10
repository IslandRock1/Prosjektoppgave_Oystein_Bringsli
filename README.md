# 3D Particle Simulator (Work in progress)

This is a physically based simulator that renders and simulates particle collision and gravity in 3D.
The project is largely based on a previous project of mine for a similar simulation in 2D.

### Current state
As of 10.10.23 the project is still in the start phase, and not ready to be used.

### How to build?
This simulation uses threepp to render.

### Notes on implementation
This simulation is built to act as an 80% physicly based simulation, and 20% visually belivable/pleasing. This means that some of the friction and gravity calculation will not be 100% physicly accurate. This simulation also uses verlet integration, witch is also not perfectly accurate.