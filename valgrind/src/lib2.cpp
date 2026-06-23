#include <iostream>
#include <lib2.h>

void lib2fun() {
	int *b = new int(20);
	std::cout << "Value of variable b = "<<*b<<std::endl;
	delete(b);
}