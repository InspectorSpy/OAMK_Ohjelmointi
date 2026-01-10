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
#include <cstidlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // satunnaisluvun alustaminen

    int salaNumero, arvaus, arvausMaara, arvauksienMaara, voitot = 0, tappiot = 0;
    char pelaaUudelleen;

    cout << "Welcome" << endl;
    cout << "arvaaluku" << endl;

    do {
        salaNumero = rand() % 100 + 1;
        arvausMaara = 7;
        arvauksienMaara = 0;

        cout << "Numero generoitu väliltä 1-100. Sinulla on " << arvausMaara << " yritystä arvata se." << endl;
    }
    return 0;
}