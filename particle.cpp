//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 09 Part F

#include <iostream>
#include <cmath>
using namespace std;

class Particle {
    public:
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};
class Coord3D {   //class type that represents coordinates in 3D
public:
    double x;
    double y;
    double z;
};
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
    Particle* coord = new Particle; 
}

void setVelocity(Particle *p, double vx, double vy, double vz){
    p->vx = vx; // Set the velocity in the x direction
    p->vy = vy; // Set the velocity in the y direction
    p->vz = vz; // Set the velocity in the z direction
}

Coord3D getPosition(Particle *p){
    Coord3D position; // Create a Coord3D object to hold the position
    position.x = p->x; // Get the x position from the particle
    position.y = p->y; // Get the y position from the particle
    position.z = p->z; // Get the z position from the particle
    return position; // Return the position
}

void move(Particle *p, double dt){
    p->x = p->x * dt; //dereference ppos to get object
    p->y = p->y *dt; //uses dot operator for pvel as well
    p->z = p->z *dt;
}

void deleteParticle(Particle *p){
    delete p;
    p = nullptr;  
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