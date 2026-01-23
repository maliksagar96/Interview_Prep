#include <iostream>
#include <memory>

using namespace std;

int main() {
    std::unique_ptr<int> a = std::make_unique<int>(10);
    cout << *a << endl;        // 10
    cout << &a << endl;        // address of the unique_ptr object (on stack)

    auto b = &a;               // b is std::unique_ptr<int>*
    cout << b << endl;         // same as &a
    cout << b->get() << endl;  // address of the managed int (on heap)
    // OR
    cout << (*b).get() << endl;

    return 0;
}