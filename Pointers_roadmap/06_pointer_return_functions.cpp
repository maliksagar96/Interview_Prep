/*

	The variable heapPointer is a var

*/

#include <iostream>

using namespace std;

int* func(){
	int *heapPointer = new int(10);
	return heapPointer;
}

int main() {

	int *ptr = func();

	cout <<"Before Modification = "<<*ptr<<endl;
	*ptr = 20;
	cout <<"After Modification = "<<*ptr<<endl;

	delete ptr;

	return 0;
}

