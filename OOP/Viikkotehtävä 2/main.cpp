#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
    int maxnum = 20; // Korkein luku

    cout << "Ohjelma käynnistetty." << endl;
    cout << "_____________________________" << endl;
    cout << "Arvauspeli" << endl;

    Game peli(maxnum);

    cout << "____________________________" << endl;

    peli.play();

    cout << "____________________________" << endl;

    peli.printGameResult();

    cout << "____________________________" << endl;
    cout << "Ohjelma päättyy." << endl;

    return 0;
}