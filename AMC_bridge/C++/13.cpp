/*
13. What are the advantages of using friend classes?
Ans - Friend Class can use the private members of that class. 

Que - Does friend need to appear in public, private or protected. 
Ans - Any of them is fine as long as the keyword friend is associated.

*/


#include <iostream> 

using namespace std;

class spy;

class myCar {

  public:
    myCar() {
      cout << "This is my car."<<endl;      
    }
    
  
    friend class spy;


  private:

  void secret() const{
    cout<< "I have no insurance.\n";
  }

    friend void revealSecrets(const myCar &car);      

};

class spy {
  
  public:
    void spillSecret(const myCar &car) {
      car.secret();
    }

};

void revealSecrets(const myCar &car) {
  car.secret();
}

int main() {

  myCar car;

  spy s1;
  s1.spillSecret(car);

  revealSecrets(car);

  return 0;
}