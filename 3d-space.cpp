//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 09 

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {   //class type that represents coordinates in 3D
public:
    double x;
    double y;
    double z;
};

//Task A
double length(Coord3D *p) { // get values from Cord3D object that p points to
    double x = p->x; //p is a memory address of where 3D object is located
    double y = p->y;  //coordinates of point p
    double z = p->z;

    return sqrt(x * x + y * y + z * z);
}
//Task B
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    if (length(p1) > length(p2)) {
        return p1;
    } else {
        return p2;
    }
}

//Task C
void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x = ppos->x + pvel->x * dt; //dereference ppos to get object
    ppos->y = ppos->y +pvel->y *dt; //uses dot operator for pvel as well
    ppos->z = ppos->z +pvel->z *dt;
}
//Task E
Coord3D* createCoord3D(double x, double y, double z){ // allocate memory and initialize
    Coord3D* coord = new Coord3D; //make a call to new a block of memory that holds a 3d object
//returns memory address of the block
    coord->x = x;
    coord->y = y; //dereference to get object, then get data members of obj
    coord->z = z;

    return coord;
}

void deleteCoord3D(Coord3D *p) { // free memory
    delete p;
    p = nullptr;  
}
int main() {
//Task A
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};
    cout << "Length of point P: " << length(&pointP) << endl; // would print 37.4166
//Task B
    cout << "Address of Point P: " << &pointP << endl;
    cout << "Address of Point Q: " << &pointQ << endl;
    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
    cout << "The point further from the origin is at: " << ans << endl;
//Task C
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};
    move(&pos, &vel, 2.0); // object pos gets changed
    cout << "New position coordinates: " << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4
//Task E
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z); //ppos is the memory address of where it is stored
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;
    //dereference to get object
    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);


}