/*
Tehtävä 1/2
Laadi ohjelma, joka pyytää pelaajaa arvaamaan tietokoneen arpoman satunnaisen luvun väliltä 1-20. Pelaajaa autetaan kertomalla onko hänen arvauksensa pienempi tai suurempi tai yhtäsuuri kuin etsittävä luku.Kun arvaus on yhtäsuuri kuin luku, peli päättyy.
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
#include <stdlib.h>

using namespace std;

int main() {
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int guess = 0;

    cout << "Arvaa luku väliltä 1-100: ";

    do {
        cout << "Anna arvaus: ";
        cin >> guess;

        if(guess > number) {
            cout << "Luku on pienempi." << endl;
        } else if(guess < number) { cout << "Luku on suurempi." << endl;
        } else {
            cout << "Oikea vastaus!" << endl;
            exit(0);
        }
        } while(number != guess);

    return 0;
}