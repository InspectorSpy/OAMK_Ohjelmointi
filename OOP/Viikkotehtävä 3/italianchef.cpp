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

#include "italianchef.h"
#include <iostream>
#include <algorithm>

using namespace std;

italianChef::italianChef(string chefName) : Chef(chefName), password("pizza") {
    cout << "Italian chef " << name << " konstruktori" << endl;
}

italianChef::~italianChef() {
    cout << "Italian chef " << name << " destruktori" << endl;
}

string italianChef::getName() const {
    return name;
}

bool italianChef::askSecret(string secret, int flour, int water) {
    if (secret == password) {
        makePizza(flour, water);
        return true;
    }
    return false;
}

int italianChef::makePizza(int flour, int water) {
    int pizzasFromFlour = flour / 5;
    int pizzasFromWater = water / 5;
    int pizzas = min(pizzasFromFlour, pizzasFromWater);
    cout << "Italian chef " << name << " makes pizza with " << flour << " flour and " << water << " water" << endl;
    return pizzas;
}