/*
	Command to test with valgrind
	valgrind --leak-check=full --show-leak-kinds=all ./valgrid_test

*/

#include <iostream>
#include <lib1.h>
#include <lib2.h>

using namespace std;

int main() {

	int *a = lib1fun();
	int b = 20;
	delete(a);
	b = 30;
	lib2fun();
	b = 40;

	for(int i = 0;i<5;i++) {
		b++;
	}


	return 0;
}