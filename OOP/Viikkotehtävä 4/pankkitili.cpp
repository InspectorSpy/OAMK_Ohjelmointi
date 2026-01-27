/*
Tehtävä osa 1.
1. Toteutusta on helpoin lähteä tekemään Pankkitili-luokasta. Jäsenfunktioissa deposit() tekee talletuksen tilille ja withdraw() noston tililtä. Hox! Nämä funktiot ovat virtuaalisia!
2. Negatiivisia nostoja / talletuksia ei voi tehdä. Esim noston parametriksi ei voi antaa summaa -123.45.
3. Pankkitilin saldo ei saa mennä negatiiviseksi, eli enempää ei voi nostaa kun mitä saldo on.
4. Nämä jäsenfunktiot palauttavat true/false sen mukaan onnistuiko talletus/nosto.
5. Luokassa on myös getteri saldolle (getBalance()).
6. Huomataan, että Luottotili-luokka perii Pankkitilin. Tarvitsee siis tehdä omat toteutukset luottotililtä nostolle/luottovelan maksulle, perittyihin virtuaalifunktioihin. Hox! Muistakaa avainsana override.
7. Konstruktorissa on nyt parametrit tilinomistajan nimi ja henkilökohtainen luottoraja.
8. Negatiivisia nostoja / velanmaksuja ei voi tehdä. Esim velanmaksun parametriksi ei voi antaa summaa -123.
9. Luottotilin saldo saa mennä negatiiviseksi, mutta ei alle luottorajan. 
10. Funktiot palauttavat jälleen true/false sen mukaan onnistuiko operaatio. 
11. Luottotilin saldo ei saa olla yli 0. Eli kaikki nostettu on velkaa.
12. Seuraavaksi laaditaan Asiakas-luokka. Huomataan yksityiset jäsenet luokista Pankkitili ja Luottotili. Konstruktorissa double-parametri on asiakkaan henkilökohtainen luottoraja.
13. Jäsenfunktio showSaldo() tulostaa molempin tilien saldot ruudulle.
14. Jäsenfunktiot talletus() ja nosto() tekevät nämä operaatiot pankkitilille (ts. kutsutaan jäsenolion vastaavaa funktiota).
15. Jäsenfunktiot luotonMaksu() ja luotonNosto() tekevät operaatiot luottotilille (ts. kutsutaan jäsenolion vastaavaa funktiota).

Tehtävä osa 2.
Tehtävän toisessa osassa harjoitellaan viittauksien käyttöä. 
1. Huomataan alla luokkakaaviosta uusi jäsenfunktio tiliSiirto, jossa on parametrinä ensin siirrettävä summa ja sitten viittaus Asiakas-luokan olioon, kenelle summa siirretään.
2. Siirron voi tehdä pankkitililtä toiselle, ei luottotililtä luottotilille. 
3. Nyt operaatiossa täytyy ensin nostaa rahat tililtä ja sen jälkeen tallettaa nostetut rahat parametrinä annetun asiakkaan tilille. 
4. Tietysti tässä pätee samat säännöt kuin aiemmin: tilillä pitää olla tarpeeksi rahaa, negatiivista siirtoa ei voi tehdä, jne. 
*/

#include "pankkitili.h"

Pankkitili::Pankkitili(string nimi) : owner(nimi), saldo(0) {

}

bool Pankkitili::deposit(double amount) {
    if(amount < 0) return false;
    if (saldo - amount < 0) return false;
    saldo -= amount;
    return true;
}

bool Pankkitili::withdraw(double amount) {
    if (amount < 0) return false;
    if (saldo - amount < 0) return false;
    saldo -= amount;
    return true;
}

double Pankkitili::getBalance() {
    return saldo;
}

Pankkitili::~Pankkitili() {

}