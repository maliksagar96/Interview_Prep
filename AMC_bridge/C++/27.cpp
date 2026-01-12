/*

    This is the classic diamond problem.

    it makes a diamond. class Mammal and wingedAnimal are derived from animal. Bat is then derived from these 2 classes.

*/

#include <iostream>
using namespace std;

// Common base class
class Animal {
public:
    int age;
    Animal() { 
        cout << "Animal constructed\n"; 
        age = 5; 
    }
    void speak() {
        cout << "I am an animal, age " << age << endl;
    }
};

// Two intermediate classes inheriting from Animal
class Mammal : public Animal {
public:
    Mammal() { cout << "Mammal constructed\n"; }
};

class WingedAnimal : public Animal {
public:
    WingedAnimal() { cout << "WingedAnimal constructed\n"; }
};

// Derived class inheriting from both Mammal and WingedAnimal
class Bat : public Mammal, public WingedAnimal {
public:
    Bat() { cout << "Bat constructed\n"; }
};

int main() {
    Bat bat;

    // 🚨 PROBLEM 1: Which 'age'?
    // bat.age = 10;  // ❌ ERROR: ambiguous — is it Mammal::age or WingedAnimal::age?

    // 🚨 PROBLEM 2: Which 'speak()'?
    // bat.speak();   // ❌ ERROR: ambiguous — which Animal subobject to call?

    // ✅ Workaround (but messy): explicitly qualify
    bat.Mammal::age = 8;
    bat.WingedAnimal::age = 12;

    bat.Mammal::speak();        // Prints: I am an animal, age 8
    bat.WingedAnimal::speak();  // Prints: I am an animal, age 12

    // 🚨 PROBLEM 3: Two copies of Animal exist!
    cout << "Size of Bat: " << sizeof(bat) << " bytes\n";
    // Likely includes *two* 'int age' members → larger than expected!

    return 0;
}