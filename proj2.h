


// File: proj2.h                                                                                                                                                                                          
//Project: CMSC 202 project 2, Fall 2016                                                                                                                                                                    
// Date: 10/18/2016                                                                                                                                                                                         
//Author: Megh Kadel                                                                                                                                                                                        
//Section: 16                                                                                                                                                                                               
//Email: ab46015@umbc.edu  

#include "Pokemon.h"
#include "MyPokemon.h"
#include <iostream>     /* cout, cin */
#include <vector>       /* vector */
#include <string>       /* string */
#include <fstream>      /* fstream, ifstream, ofstream */
#include <iomanip>      /* setw, setfill, etc */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//Constants for files + Max Pokemon
const int POKECOUNT = 151;
const char POKEDEX[12] = "pokeDex.txt";
const char MYCOLLECTION[18] = "myCollection.txt";
//Add more constants as needed

// Name: getPokeDex(vector)
// Pre-condition: When the application loads, loads the complete pokemon list from file
// Post-condition: Returns a populated pokeDex vector
void getPokeDex(vector <Pokemon> & pokeDex);
// Name: getMyCollection
// Pre-condition: When the application loads, loads the user's pokemon collection from file
// Post-condition: Returns a populated myCollection vector
void getMyCollection(vector<MyPokemon> & myCollection);
// Name: catchPokemon
// Pre-condition: Takes in the current user's collection and the pokeDex vector
// Post-condition: Prompts user for rarity (1-5) user would like to capture
//                 Based on rarity (1=65%, 2=45%, 3=25%, 4=10%, 5=1%) tries to find a random
//                 Pokemon based on that rarity.
//                 If a Pokemon is found, calls foundPokemon
void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection);
// Name: printPokeDex (vector)
// Pre-condition: Takes in populated pokeDex vector
// Post-condition: Prints num and name of each Pokemon in vector
void printPokeDex(vector <Pokemon> & pokeDex);
// Name: printMyCollection (vector)
// Pre-condition: Takes in populated myCollection vector
// Post-condition: Prints num, name, CP, HP, rarity of each pokemon in vector
void printMyCollection(vector <MyPokemon> & myCollection);
// Name: foundPokemon (rarity, vector pokeDex, vector myCollection)
// Pre-condition: After a Pokemon is found, rarity is passed to this function
// Post-condition: Using rarity, the pokeDex is randomly searched for a matching rarity
//                 After an appropriate Pokemon is found
//                 Adds new Pokemon to user's collection
void foundPokemon(int rarity,vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection );
// Name: mainMenu
// Pre-condition: Takes in vector pokeDex and vector myCollection
// Post-condition: Calls a variety of functions based on user 
void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> &myCollection);
// Name: battlePokemon(vector pokeDex, vector myCollection)
// Pre-condition: Takes in both pokeDex and myCollection. Randomly chooses an enemy
//                Sets enemy CP as random number between minCP and maxCP
// Post-condition: Says if battle is won or lost - returns to mainMenu
void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection);
// Name: trainPokemon(vector pokeDex, vector myCollection)
// Pre-condition: Takes in both pokeDex and myCollection
// Post-condition: Calls Train member function that increases CP by 10. Updates myCollection
void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection);
// Name: exitPokemon
// Pre-condition: From main menu, user selects 6
// Post-condition: Calls saveMyCollection and exits application
void exitPokemon(vector<MyPokemon> & myCollection);
// Name: saveMyCollection(vector)
// Pre-condition: Takes in vector of user collection of Pokemon
// Post-condition: Saves a file with each Pokemon with number, name, CP, HP, rarity
void saveMyCollection(vector<MyPokemon> & myCollection);
