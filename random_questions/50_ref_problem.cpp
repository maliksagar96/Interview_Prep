/*
  This is such a sexy problem. 
  The variable goals has to be initialised as soon as an object is created. 
  Since there is no constructor defined the compiler tries to create a constructor on its own. 
  But then it sees that the reference variable goals has to be defined which is left unitialised. 
  So it deletes the default constructor as this variable can be defined only through a constructor otherwise 
  keeping the reference variable undefined is illegal. 
  This can be fixed with a constrcutor which declares the refernce variable.
*/

#include <iostream> 
#include <string>

struct Player {
  int& goals;
  std::string name;

  // Player(int &PlayerGoals, std::string &playerName):goals(PlayerGoals), name(playerName){}
};

int main() {

  int mbappeGoals = 39;
  Player mbappe;
  // Player mbappe(mbappeGoals, "Mbappe");
}