
// File: proj2.cpp                                                                                                                                                                                          
//Project: CMSC 202 project 2, Fall 2016                                                                                                                                                                    
// Date: 10/18/2016                                                                                                                                                                                         
//Author: Megh Kadel                                                                                                                                                                                        
//Section: 16                                                                                                                                                                                               
//Email: ab46015@umbc.edu  


#include "proj2.h"
#include <iostream>
#include <fstream>


using namespace std;

int main () {

 
  
  srand(10);
  vector<Pokemon> pokeDex;
  vector<MyPokemon> myCollection;
  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu (pokeDex, myCollection);
  return 0;
}

void getPokeDex(vector<Pokemon> & pokeDex){
  int num;
  string name;
  int cpMin;
  int cpMax;
  int rarity;
  ifstream data("pokeDex.txt");
  unsigned  int POKECOUNT = 151; //total numbers of pokemons
  
  for (unsigned int i = 0; i < POKECOUNT; i++){ 
     data >> num >> name >> cpMin >> cpMax >> rarity;
     
     Pokemon pokeObject = Pokemon(num, name, cpMin, cpMax, rarity);
     pokeDex.push_back(pokeObject);
  }
   
   
  data.close();
}

void getMyCollection(vector<MyPokemon> & myCollection){
  int num;
  string name;
  int cp;
  int hp;
  int rarity;
 ifstream data1;
 data1.open("myCollection.txt"); 
unsigned  int size = myCollection.size();
 for (unsigned int i = 0; i < size; i++){
 data1>> num >> name >> cp >> hp >> rarity; 
 MyPokemon myPokeObject = MyPokemon( num, name, cp, hp, rarity);
  myCollection.push_back(myPokeObject);
  
}
data1.close();
}

void printPokeDex(vector <Pokemon> & pokeDex){
  unsigned int size = pokeDex.size();
  
 for(unsigned int i = 0; i < size ; i++){
   cout  << pokeDex[i].GetNum() <<"   " <<pokeDex[i].GetName()<<endl; 
   }

}

void printMyCollection(vector <MyPokemon> & myCollection){
 

  unsigned int size = myCollection.size();
  for (unsigned int i = 0; i < size ; i++){

    int num= myCollection[i].GetNum();
    string name = myCollection[i].GetName();
    int cp = myCollection[i].GetCP();
    int hp = myCollection[i].GetHP();
    int rarity = myCollection[i].GetRarity();

    cout << num<<"  "<< name << " " << cp << "  " << hp << "  " << rarity <<endl;
  }


}

void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0;
 const int UPPER_NO = 100;// upper limit of (1-100) numbers
 const int LOWER_NO = 1;// a constant
 const int CUTOFF_NO0 = 0;//a constant value
 const int CUTOFF_NO1 = 66;// upper limit for 65% probalility 
 const int CUTOFF_NO2 = 46;// upper limit for 45% probability
 const int CUTOFF_NO3 = 26;// upper lilit for 25% probability
 const int CUTOFF_NO4 = 11; // upper limit for 10% probability
  do {
  cout <<"What type of Pokemon would you like to try and catch?: "<<endl;
  cout <<"1. Very Common (Very High Probability)"<<endl;
  cout <<"2. Common (High Probability)"<<endl;
  cout <<"3. Uncommon (Normal Probability)"<<endl;
  cout <<"4. Rare ( Low Probability)"<<endl; 
  cout<<"5.Ultra Rare (Extremely Low Probability)<<endl;"<<endl;
  cin >> option;
  }while (option<1|| option>5);

  

  int cpNumber = rand()% UPPER_NO + LOWER_NO;
  
  switch (option){
  case 1:
    if (cpNumber< CUTOFF_NO1 && cpNumber > CUTOFF_NO0)
       foundPokemon(1,pokeDex,myCollection);

    break;
  case 2:
    if (cpNumber< CUTOFF_NO2 && cpNumber > CUTOFF_NO0)
       foundPokemon(2,pokeDex,myCollection);
    break;
  case 3:
    if (cpNumber< CUTOFF_NO3 && cpNumber > CUTOFF_NO0)
      foundPokemon(3,pokeDex,myCollection);
    break;
  case 4:
    if (cpNumber< CUTOFF_NO4 && cpNumber > CUTOFF_NO0)
      foundPokemon(4,pokeDex,myCollection);
    break;
  case 5:
    if (cpNumber == UPPER_NO)
       foundPokemon(5,pokeDex,myCollection);
    break;    
    }
   

}

void foundPokemon(int rarity, vector <Pokemon> & pokeDex, 
		 vector<MyPokemon> & myCollection ){

  cout<<"You start to search"<<endl;
  int fkNumber;
  const int MIN = 1;
  int POKECOUNT = 151;

  fkNumber = rand()% POKECOUNT + MIN;
  if (pokeDex[fkNumber].GetRarity() == rarity)

    {
      cout<<"Congrats! You found a "<<pokeDex[fkNumber].GetName()<<endl;
      //............
      int num = pokeDex[fkNumber].GetNum();
      string name = pokeDex[fkNumber].GetName();
      int cp = pokeDex[fkNumber].GetCPMax();
      //..............      
      int hp = rand()% 500 + 1;
      int rarity = pokeDex[fkNumber].GetRarity();
      MyPokemon myPokeObj = MyPokemon(num,name, cp,hp,rarity); 
      myCollection.push_back(myPokeObj);
      
    }
  else 
    {  cout<<" Sorry,you found nothing. Try again Please"<<endl;} 
}

void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. See the PokeDex" << endl;
      cout << "2. See your collection" << endl;
      cout << "3. Search for a new Pokemon" << endl;
      cout << "4. Battle Your Pokemon" << endl;
      cout << "5. Train your Pokemon" << endl;
      cout << "6. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 6);
  
    switch(option){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex,  myCollection);
      break;
    case 4:
      battlePokemon(pokeDex, myCollection);    
      break;
    case 5:
      trainPokemon(pokeDex, myCollection);
      break;
    case 6:
      exitPokemon(myCollection);
      isExit = 1;
    }
  }while(isExit == 0);
}


 void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
   int bkNumber;
   int MAX = 151; //total number of the pokemon
   int MIN = 1; 
     int unsigned batInput;
   
   bkNumber = rand()% MAX + MIN;
   cout<<"You are going to fight a"<<pokeDex[bkNumber].GetName()<<endl;
   cout<<"The enemy has a CP of "<<pokeDex[bkNumber].GetCPMax()<<endl;
   cout<<"Which of your Pokemon would like to use?:"<<endl;

    printMyCollection(myCollection);
    
   cin>> batInput;

   if (batInput <= myCollection.size()){
        if (myCollection[batInput].GetCP() > pokeDex[bkNumber].GetCPMax())
        
       cout<<"You won!! " <<endl;
       
     
       else 
     
       cout<<"Sorry you lost the battle."<<endl;
   }


 else 
   
   cout<<"Choose a pokemon within the size of your myCollection"<<endl;
   

 }




 void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){

   
   int unsigned choice;
   int cp;
   cout<<"Which of your Pokemmon would like to use?: "<<endl;


   printMyCollection(myCollection);

   cin>> choice;
   if (choice <= myCollection.size()){
   cout<<"Your" << myCollection[choice].GetName()<< "trained"<<endl;
   cp= myCollection[choice].GetCP();
   myCollection[choice].Train ();
   cout<<"Your CP is now " << myCollection[choice].GetCP()<<endl;
     }
     
     else{
     cout<<" Choose a Pokemon within a size of the collection of your Pokemon"<<endl;
     }
     
     
 }

 void exitPokemon(vector<MyPokemon> & myCollection){
   saveMyCollection(myCollection);
   cout<<"File Saved"<<endl;
   cout<<"Thank you for playing Pokemon UMBC"<<endl;
 }

void saveMyCollection(vector<MyPokemon> & myCollection){

  ofstream myFile;
  
  myFile.open("myCollection.txt");
  unsigned int size = myCollection.size();
  

  for (unsigned int i = 0; i< size; i++){

    int num = myCollection[i].GetNum();
    string name = myCollection[i].GetName();
    int cp = myCollection[i].GetCP();
    int hp = myCollection[i].GetHP();
    int rarity = myCollection[i].GetRarity();
     
    myFile << num <<"    "<<name<<"  " <<cp<<"  " <<hp<< "  " <<rarity<<endl;
  }

}

 
