#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class MyPokemon{
 public:
  //Constructors
  MyPokemon();
  MyPokemon(int num, string name, int cp, int hp, int rarity);

  //Accessors
  int GetCP();
  int GetHP();
  int GetRarity();
  string GetName();
  int GetNum();

  //Mutators
  void SetRarity(int newRarity);
  void SetName(string newName);
  void SetCP(int newCP);
  void SetHP(int newHP);

  //Member Functions
  void Train();
  
 private:
  int m_Num;
  string m_Name;
  int m_CP;
  int m_HP;
  int m_Rarity;
};
