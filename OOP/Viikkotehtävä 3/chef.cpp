/*
1. Laadi ensin alla esitetyn luokkakaavion mukanen luokka Chef. Kiinnitä huomiota jäsenmuuttujan chefName suojaukseen.
2. Konstruktorissa annetaan parametrinä kokin nimi. 
3. Jäsenfunktioissa makeSalad() ja makeSoup() annetaan parametrinä ainesten määrä. Funktiot palauttavat annosten määrän. 
Salaatti: yhteen annokseen tarvitaan 5 ainesta
Keitto: yhteen annokseen tarvitaan 3 ainesta
4. Toteuta luokka Chef niin, että jäsenfunktiot, konstruktori ja destruktori tulostavat debug-tietoa. 
5. Toteuta luokka ItalianChef, joka perii Chef-luokan. 
6. Lisää luokkaan luokkakaavion mukaiset jäsenmuuttujat. Salasanalle annetaan alustusarvoksi pizza. 
7. Jäsenfunktio askSecret() tarkistaa onko parametrinä annettu salasana ok, ja jos on, kutsuu makePizza()-jäsenfunktiota. Muut parametrit ovat ainesten eli jauhojen (flour) ja veden (water) määrä. Funktio palauttaa true/false sen mukaan oliko salasana oikea. 
8. makePizza tekee pizzoja niin paljon kuin aineksi riittää, yhteen pizzaan tarvitaan:
5 ainesta jauhoja
5 ainesta vettä
9. makePizza() on privaatti siksi, että se on salainen ja sitä ei voi muuten kutsua kun tietämällä salasanan (muitakin tapoja tehdä tarkistus kyllä on..). 
*/

#include "chef.h"
#include <iostream>

using namespace std;

Chef::Chef(string chefName) : name(chefName) {
    cout << "Chef " << name << " konstruktori" << endl;
}

Chef::~Chef() {
    cout << "Chef " << name << " destruktori" << endl;
}

int Chef::makeSalad(int ingredients) {
    int portions = ingredients / 5;
    cout << "Chef " << name << " with " << ingredients << " items can make salad " << portions << " portions" << endl; 
    return portions;
}

int Chef::makeSoup(int ingredients) {
    int portions = ingredients / 3;
    cout << "Chef " << name << " with " << ingredients << " items can make soup " << portions << " portions" << endl; 
    return portions;
}