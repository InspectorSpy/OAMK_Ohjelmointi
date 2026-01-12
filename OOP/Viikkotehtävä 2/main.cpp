#include "Game.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001); // Konsoli utf-8
    SetConsoleCP(65001);

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