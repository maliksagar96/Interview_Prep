/*

5. There is a Value data type that works in a single-threaded environment. Make changes so that it works as efficiently as possible in a multi-threaded environment.

class Value 
{ 
private:
     int m_value{};

public:
      Value (){}
      int getValue() const
      { 
          return m_value;
      }
      void updateValue(int value)
      { 
          m_value = value; 
      } 
}


*/

#include <iostream>
#include <atomic>

class Value 
{ 
private:
     atomic<int> m_value{0};

public:
      Value (){}
      int getValue() const
      { 
          return m_value.load();
      }
      void updateValue(int value)
      { 
          m_value.store(value); 
      } 
}


int main() {

  return 0;
}