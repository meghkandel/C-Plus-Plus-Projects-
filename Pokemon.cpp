
// File: Pokemon.cpp                                                                                                                                                                                          
//Project: CMSC 202 project 2, Fall 2016                                                                                                                                                                    
// Date: 10/18/2016                                                                                                                                                                                         
//Author: Megh Kadel                                                                                                                                                                                        
//Section: 16                                                                                                                                                                                               
//Email: ab46015@umbc.edu  

// Members functions definitions
 
# include "Pokemon.h"

using namespace std;


Pokemon:: Pokemon (){

  m_Num = 0;
  m_Name= " ";
  m_MinCP =0 ;
  m_MaxCP= 0;
  m_Rarity= 0;
}

Pokemon:: Pokemon (int num, string name, int cpMin, int cpMax, int rarity){

  m_Num = num;
  m_Name= name;
  m_MinCP = cpMin;
  m_MaxCP= cpMax;
  m_Rarity= rarity;

}



int Pokemon ::GetNum(){

  return m_Num;
}

void Pokemon:: SetRarity(int newRarity){

  m_Rarity = newRarity;

}

int Pokemon::GetRarity(){

  return m_Rarity;

} 

void Pokemon:: SetName( string newName){

  m_Name = newName;

}

string  Pokemon:: GetName(){

  return m_Name;

}

int Pokemon ::GetCPMin(){

  return m_MinCP;
}


int Pokemon:: GetCPMax(){

  return m_MaxCP; 
}

void Pokemon ::SetCP( int newCP){

 


}
