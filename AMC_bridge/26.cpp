#include <iostream>
#include <cmath>

using namespace std;

class Vector {
    public:
    double x, y, z;

    double absolute()  {
        return sqrt(x*x + y*y + z*z);
    }

    Vector(double x, double y, double z):x(x),y(y),z(z) {}
};

class integers {
    public:
    int x;

    int absolute() {
        if(x >= 0) return x;
        return -x;
    }

    integers(int x):x(x){}

};

class Number: public integers, public Vector {
    public:
    Number(int id, double x, double y, double z) : integers(id), Vector(x, y, z) {}
};

int main() {
    Number num(1, 3.0, 4.0, 0.0);
    
    cout<<num.Vector::absolute()<<endl;

    return 0;
}