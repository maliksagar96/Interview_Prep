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

	delete(a);
	lib2fun();

	return 0;
}