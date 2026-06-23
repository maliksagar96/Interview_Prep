#include <iostream>
#include <lib1.h>

int* lib1fun() {
	int *a = new int(10);
	std::cout << "Value of variable a = "<<*a<<std::endl;
	return a;
}

