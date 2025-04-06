//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 09 Part F

#include <iostream>
#include <cmath>
using namespace std;

// Structure to store 3D coordinates
struct Coord3D {
    double x;
    double y;
    double z;
};

// Particle class to store position and velocity
class Particle {
public:
    Coord3D position;
    Coord3D velocity;
};

// Create a new particle with the given position and velocity
Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz) {
    Particle* p = new Particle;
    p->position.x = x;
    p->position.y = y;
    p->position.z = z;
    p->velocity.x = vx;
    p->velocity.y = vy;
    p->velocity.z = vz;
    return p;
}

// Set the velocity of the particle
void setVelocity(Particle *p, double vx, double vy, double vz) {
    p->velocity.x = vx;
    p->velocity.y = vy;
    p->velocity.z = vz;
}

// Get the current position of the particle
Coord3D getPosition(Particle *p) {
    return p->position;
}

// Update the particle's position based on its velocity and elapsed time
void move(Particle *p, double dt) {
    p->position.x += p->velocity.x * dt;
    p->position.y += p->velocity.y * dt;
    p->position.z += p->velocity.z * dt;
}

// Free the memory allocated for the particle
void deleteParticle(Particle *p) {
    delete p;
}

int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}