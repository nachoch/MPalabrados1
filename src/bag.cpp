/**
 * @file bag.cpp
 * @author DECSAI
 * @note To be implemented by students except function shuffle()
 */
#include <cassert>
#include <random>
#include <algorithm>
#include "bag.h"
#include "language.h"

///@warning Fill missing #include

using namespace std;

/**
 * @brief Randomly reorders a vector of char
 * @param s Vector of char
 * @param n Number of char in the vector
 * @author DECSAI
 */
void shuffleVector(char *s, int n, int id);

/**
 * @brief Removes a position from a vector and compacts the remaining positions, 
 * thus reducing its size
 * @param s Vector of char
 * @param n Number of chars
 * @param p Position to remove
 * @warning TO BE FULLY IMPLEMENTED. 
 * @warning Check parameters const/&/* and their types
 */
void removeVector(char *s, int &n, int p);


// Main methods

Bag::Bag() {
    nletters = 0;
    id = time(NULL);
}

char Bag::get(int p)const{
    if (p < nletters)
        return letters[p];
}

void Bag::set(int p, char c){
    if (p < nletters){
        letters[p] = c;
    }
}

///@warning Implement all the methods

void Bag::setRandom(int rand){
    id = rand;
}

void Bag::define(const Language& l){
    string setLetras = l.getLetterSet();
    int contador;
    
    // Aniadimos letra a bag tantas veces (contador) como aparezca en el lenguage seleccionado
    for (int i = 0; setLetras[i] != '\0'; i++){
        contador = 0;
        while (contador < l.getFrequency(setLetras[i])){
            letters[nletters] = setLetras[i];
            contador++;
            nletters++;
        }
    }
    
    shuffleVector(letters, nletters, id);
}


int Bag::size() const{
    return nletters;
}


string Bag::to_string() const{
    string s = "";
    
    for (int i = 0; i < nletters; i++)
        s += letters[i];
    
    return s;
}


void Bag::set(std::string s){
    // la funcion c_str() devuelve un puntero constante a la cadena de caracteres
    //strcpy(letters, s.c_str());
    for (int i = 0; i < s.length(); i++)
        letters[i] = s[i];
    
    nletters = s.length();
}

string Bag::extract(int n){
    string s = "";
    int num = n;
    
    if (nletters < num)
        num = nletters;
    
    for (int i = 0; i < num; i++){
            s += letters[i];
            removeVector(letters, nletters, 0);
    }
    
    
    return s;
}

// Auxiliary functions 

void shuffleVector(char *s, int n, int id) {
    vector <char> aux(s, s+n);
    unsigned seed = id;
    std::shuffle(aux.begin(), aux.end(), std::default_random_engine(seed));
    for (int i=0; i<n; i++)
        s[i] = aux[i];    
}


void removeVector (char *s, int &n, int p){
    for (int i = p; i < n-1; i++){
        s[i] = s[i+1];
    }
    n --;
}

