#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>

using namespace std;

int main() {

  // vector<float> a = {1.4, 2.7, 4};
  // vector<float> b = {1.4, 2.7, 3.5};

  // // assert(a.size() == b.size() && "Size mismatch between a and b");

  // for(int i = 0;i<a.size();i++) {
  //   assert((fabs(b[i] - a[i]) < 1e-6) && "Results Mismatch");
  // }

  cout<<sizeof(int)<<endl;
  cout<<sizeof(long)<<endl;

  assert(sizeof(int) != sizeof(long) && "Different Sizes"); //Is this statement always true

// No — this statement is **not always true**.  
// On many systems (e.g., Windows x64, Linux x64 with LP64 model), `sizeof(int) == 4` and `sizeof(long) == 8`, so the assert passes.  
// But on Windows (LLP64 model) and some 32-bit systems, `sizeof(int) == sizeof(long) == 4`, so the assert **fails**.  
// Thus, the assertion is platform-dependent and **not portable**.

  return 0;
}