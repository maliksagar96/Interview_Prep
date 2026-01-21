#include <iostream>

using namespace std;

int main() {

  int n = 3;
  int *p = &n; //so far so good.
  void *pv = p; //void * can be casted to any type of pointer.

  cout<<*p<<endl;
  cout<<*(int*)pv<<endl; //cout<<*pv<<endl; gives out an error. The variable pv stores the address of n but without the type information.
  //(int*)pv is the casting of pv to int* and * is then used to deference it. 

  p = static_cast<int*>(pv);   
  //So there won't be a problem with this. You can cast pv to int *. But if you mess up you are on your own.




  return 0;
}