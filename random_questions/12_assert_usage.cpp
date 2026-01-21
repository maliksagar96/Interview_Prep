#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int main( ){
 int a = 5;
 int b = 5;

 assert(a == b);

 float c = 0.003;
 float d = 0.003;

 const float eps = 1e-6;

 assert(std::fabs(c - d) < eps);

 float e = /* CPU */;
 float f = /* GPU */;

  const float abs_eps = 1e-6f;
  const float rel_eps = 1e-5f;

  /*This is better.*/
  assert(std::fabs(a - b) <= std::max(abs_eps, rel_eps * std::max(std::fabs(a), std::fabs(b))));

  return 0;
}