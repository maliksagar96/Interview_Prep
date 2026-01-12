/*
13. What are the advantages of using friend classes?

*/

#include <iostream>

using namespace std;

class Mechanic;

class Engine {
    int fuelLevel;

    friend class Mechanic;
};


class Mechanic {
    public:
    void refuel(Engine &e) {
        e.fuelLevel = 100;
        cout<<"Fuel level = "<<e.fuelLevel<<endl;
    }

    void checkFuel(Engine &e) {
        cout<<"e.fuelLevel = "<<e.fuelLevel<<endl;
    }

};

using namespace std;

int main() {

    Engine car;
    Mechanic bob;
    bob.refuel(car);
    


    return 0;
}