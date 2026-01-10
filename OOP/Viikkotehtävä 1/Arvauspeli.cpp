/*
Tehtävä 1/2
Laadi ohjelma, joka pyytää pelaajaa arvaamaan tietokoneen arpoman satunnaisen luvun väliltä 1-20.
Pelaajaa autetaan kertomalla onko hänen arvauksensa pienempi tai suurempi tai yhtäsuuri kuin etsittävä luku.Kun arvaus on yhtäsuuri kuin luku, peli päättyy.
1) Ensin kirjoita ohjelma main-funktion sisälle pääohjelmaksi. Ohjelman runko voisi olla jotain seuraavan kaltaista:
Arvotaan satunnainen luku
Kysytään pelaajalta arvaus
Tarkistetaan onko arvaus pienempi, suurempi tai yhtäsuuri kuin luku
Kerrotaan tarkistuksen tulos tyyliin ”luku on pienempi/suurempi” tai ”oikea vastaus”
Jos pelaajan vastaus ei ollut oikein, niin palataan kohtaan 2.
Testaa tässä vaiheessa ohjelman toimivuus, ennen tehtävän jatkamista seuraavalla sivulla.

Tehtävä 2/2
2) Siirrä tehtävän ohjelma oman funktionsa sisälle niin, että sitä kutsutaan main-funktiosta. Lisää funktioon arvausten lukumäärän laskenta.
Käytä funktion nimenä ja prototyyppinä int game();, joka palauttaa arvausten määrän pääohjelmaan.
3) Muuta toteuttamaasi funktiota siten, että funktiolle annetaan parametriksi korkein etsittävä luku (maxnum), josta funktio arpoo satunnaisluvun.
Esimerkiksi, jos tämä luku on 40, niin funktio arpoo luvun väliltä 1-40.
Pelin loputtua tulosta arvausten määrä ruudulle main funktiosta paluuarvoa hyödyntäen. Käytä funktion nimenä ja prototyyppinä: int game(int maxnum);
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum); // proto

int main()
{
    int maxnum = 20;
    int yritykset;

    srand(time(NULL));

    cout << "Arvauspeli\n";
    cout << "Arvaa numero 1-" << maxnum << " välillä\n";

    yritykset = game(maxnum);

    cout << "\nOnneksi olkoon! Arvasit luvun " << yritykset << " yrityksessä\n";

    return 0;
}

int game(int maxnum) {
    int numero;
    int arvaus;
    int yritykset = 0;

    numero = (rand() % maxnum) + 1;

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
    while (arvaus != numero);

    return yritykset;
}
