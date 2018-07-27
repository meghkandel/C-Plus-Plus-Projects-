
// File: MyPokemon.cpp                                                                                                                                                                                          
//Project: CMSC 202 project 2, Fall 2016                                                                                                                                                                    
// Date: 10/18/2016                                                                                                                                                                                         
//Author: Megh Kadel                                                                                                                                                                                        
//Section: 16                                                                                                                                                                                               
//Email: ab46015@umbc.edu  

// Function denitions 

# include "MyPokemon.h"

using namespace std;

MyPokemon::MyPokemon(){


  m_Num =0;
  m_Name = " ";
  m_CP = 0;
  m_HP = 0;
  m_Rarity = 0;


}


MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity){

  m_Num = num;
  m_Name = name;
  m_CP = cp;
  m_HP = hp;
  m_Rarity = rarity;

}




int MyPokemon :: GetNum(){

  return m_Num;

}
void MyPokemon::SetRarity ( int newRarity){


  m_Rarity = newRarity;


}

int MyPokemon:: GetRarity(){


  return m_Rarity;

}

void MyPokemon:: SetName( string newName){

  m_Name = newName;
}

string MyPokemon:: GetName(){

  return m_Name;
}

void MyPokemon::SetCP( int newCP){

  m_CP = newCP;

} 

int MyPokemon:: GetCP(){

  return m_CP;
}

void MyPokemon::SetHP(int newHP){

  m_HP = newHP;
}

int MyPokemon:: GetHP(){

  return m_HP;

}

void MyPokemon:: Train(){

  //what this function needs to do?

  //int cp = 0;
  m_CP = m_CP + 10;
}
