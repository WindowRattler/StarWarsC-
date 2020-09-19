//BenjaminKramer
//converted Java Code to CPP
#include <iostream>
#include <string>
using namespace std;

class ForceBeing {
  private:
   int power_level;
   string name;
   bool evil;

  protected :
  ForceBeing(int level) {
      power_level = level;
  }

  void setPowerLevel(int level) {
    power_level = level;
  }

  void setName(string characterName) {
    name = characterName;
  }

  public :
  virtual int getPowerLevel() {
    return power_level;
  }

  virtual string getName() {
    return name;
  }

  void setEvil() {
    evil = true;
  }

  void setGood() {
    evil = false;
  }

};
//Jedi class (good guy)
class Jedi : public ForceBeing {
  
  public :
  Jedi(string jediName, int powerLevel) : ForceBeing(powerLevel){
    setName(jediName);
    setGood();
  }

  int getPowerLevel(){
    return ForceBeing::getPowerLevel() + 1;
   }

};
//Sith class (bad guy)
class Sith : public ForceBeing {
  public :
  Sith(string sithName, int powerLevel) : ForceBeing(powerLevel) {
    setName(sithName);
    setEvil();
  }

  int getPowerLevel() {
    return ForceBeing::getPowerLevel() - 1;
  }

  string getName() {
    return "Sith Lord: " + ForceBeing::getName();
  }
};
//method that sets up players and determines winner
//passes by reference
class StarWars {

    public:
     static string getWinner(ForceBeing &player1, ForceBeing &player2) {
        return player1.getPowerLevel() > player2.getPowerLevel() ? player1.getName() : player2.getName();
       
    }

    static void printWinner(string winner) {
        cout << "The winner is: " + winner << endl;
    }
};
//main method
    int main() {
        Sith darthVader("Darth Vader",100);
        Jedi lukeSkywalker("Luke Skywalker",99);
        StarWars::printWinner(StarWars::getWinner(darthVader,lukeSkywalker));
        return 0;
}
