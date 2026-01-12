/*
1. Toteuta viikkotehtävän 1 mukainen arvauspeli nyt oliopohjaisesti. 
Toteuta alla olevan luokkakaavion mukainen luokka Game
Konstruktorissa parametrinä annetaan maksimiarvo, mille välille 1-maxNumber peli arpoo arvattavan luvun.
Play()-jäsenfunktioon toteutetaan peli
printGameResult()-jäsenfunktiosta kutsutaan kun peli on päättynyt. Se tulostaa oikean vastauksen ja kuinka monta arvausta siihen tarvittiin.
Luokan toteutuksessa täytyy olla molemmat otsikkotiedosto Game.h ja luokan toteutus Game.cpp

2. Lisää peliin debug-tietoa, tulostamalla kontruktorista ja jäsenfunktioista mitä niissä tapahtuu. Esimerkki alla kuvassa. 

3. Lopuksi vielä toteuta ohjelmaan main.cpp-kooditiedosto, missä main()-funktiossa luodaan Game-olio ja ajetaan peli. 

*/

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum); // Proto

int main()
{
    int maxnum = 20; // Korkein luku
    int yritykset; // Arvaukset

    srand(time(NULL)); // Alustus

    cout << "Arvauspeli\n";

    yritykset = game(maxnum); // Olio

    cout << "\nOnneksi olkoon! Arvasit luvun " << yritykset << " yrityksessä\n";

    return 0;
}

int game(int maxnum) { // Olio funktio
    int numero;
    int arvaus;
    int yritykset = 0;

    numero = (rand() % maxnum) + 1; // Arvotaan numero

    do {
        cout << "Arvaa numero 1-" << maxnum << " välillä: ";
        cin >> arvaus;
        yritykset++;

        if (arvaus > numero) {
            cout << "Liian iso numero.\n";
        }
        else if (arvaus < numero) {
            cout << "Liian pieni numero.\n";
        }
        else {
            cout << "Oikein!\n";
        }
    }
    while (arvaus != numero); // Toista kunnes arvaus on oikein

    return yritykset; // Palauta arvausten määrä
}