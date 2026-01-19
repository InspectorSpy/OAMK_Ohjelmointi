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

#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main() {

    Chef chef("Jyrki Sukula");
    chef.makeSalad(25);
    chef.makeSoup(15);

    italianChef italianChef("Giorgio Locatelli");
    italianChef.makeSalad(5);
    italianChef.makeSoup(3);
    // italianChef.makePizza();
    // italianChef.askSecret();

    cout << "name of the italian chef is " << italianChef.getName() << endl;

    // test askSecret
    cout << "Test password function:" << endl;
    bool result1 = italianChef.askSecret("pizza", 50, 50);
    cout << "Password correct: " << (result1 ? "true" : "false") << endl;

    bool result2 = italianChef.askSecret("wrong", 50, 50);
    cout << "Password correct: " << (result2 ? "true" : "false") << endl;

    return 0;
}