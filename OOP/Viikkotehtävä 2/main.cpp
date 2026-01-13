// Kääntäminen ja ajaminen, itse käytän g++
/* Windowsissa:
    Kääntäminen: g++ -o arvauspeli main.cpp Game.cpp
    Ajaminen: ./arvauspeli.exe 
*//*
Linuxissa:
    Kääntäminen: g++ -std=c++11 "main.cpp" "Game.cpp" -o arvauspeli
    Ajaminen: ./arvauspeli
*/

#include "Game.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001); // Konsoli utf-8
    SetConsoleCP(65001);
#endif

    srand(time(NULL)); // Alustus

    int maxnum = 20; // Korkein luku

    cout << "Ohjelma käynnistetty." << endl;
    cout << "_____________________________" << endl;
    cout << "Arvauspeli" << endl;

    Game peli(maxnum); // Olion luonti

    cout << "____________________________" << endl;

    peli.play(); // Pelaa peli

    cout << "____________________________" << endl;

    peli.printGameResult(); // Tulosta tulos

    cout << "____________________________" << endl;
    cout << "Ohjelma päättyy." << endl;

    return 0;
}