/*
1. Toteutus on helpoin aloittaa Seuraaja-luokasta, jossa ei ole muuta ihmeellistä kuin osoitin next, joka on tyyppiä Seuraaja. 
2. Luokassa itseasiassa toteutetaan tunnettu tietorakenne linkitetty lista (yhdensuuntainen). Listan ideana on, että jokaisessa solmussa (=oliossa) on osoitin seuraavaan (next). Näin listaa voidaan käydä läpi alkaen ensimmäisestä solmusta ja lista päättyy, kun solmusta seuraava on tyhjä (nullptr).
3. Listan käyttäjä (tässä Notifikaattori) on sitten vastuussa solmujen lisäämisestä (ja poistamisesta) listalle. Seuraaja-luokan tarvitsee vain mahdollistaa tämä linkitys osoitin-jäsenellään. 
4. Jäsenfunktion paivitys() ideana on tulostaa konsolille saatu viesti. 
5. Notifikaattorissa tarvitsee siis toteuttaa seuraajien lisäys, poisto, tulostus ja niille viestin postitus. Luokassa on jäsenenä osoitin seuraajat, joka on listan alkupiste (=head/alku). Linkitettyä listaa lähdetään aina siis kelaamaan alusta loppuun asti siirtymällä nextin avulla seuraavaan olioon. Kun next on nullptr, tiedämme että lista päättyi siihen olioon. 
6. Nyt listan läpikäynti menisi seuraavasti while-silmukassa: osoitin *o = alku while (o != nullptr) o->jasenfunktio() // tehdään silmukassa jotain oliolle o = o->next
7. Listalta poisto tehdään ”ohittamalla” olio, eli sen edeltäjä next muokataan osoittamaan sitä seuraavaan olioon. Esimerkki: ohitetaan olio B muokkaamalla A->next osoittamaan C:hen.
8. Lisäys tehdään ”kiilaamalla” listan alkuun niin, että alku/head osoittaa lisättävään olioon ja lisättävän olion next kiilattuun vanhaan alkuun. Esimekki: Alku osoittaa B:hen, lisätään A niin, että A->next osoittaa B:hen ja alku taas A:han. 
9. Palataan takaisin luokkakaavioon. Nyt tiedämme mitä jäsenfunktiot lisaa() ja poista() tekevät.
10. Funktion tulosta() ideana on tulostaa seuraajien nimi, eli kutsua silmukassa jokaiselle seuraajalle getNimi()-jäsenfunktiota ja tulostaa se konsolille.
11. Lopuksi, funktio postita() toimii siten, että silmukassa kutsutaan jokaisen seuraajan paivitys()-funktiota, jonka parametrinä on sama viesti kuin notifikaattorin postita()-funktiossa. Funktio paivitys() sitten tulostaa viestin ruudulle. Esimerkki tulostuksesta seuraavalla sivulla. 
*/

#include <iostream>
#include <string>
#include "seuraaja.h"

seuraaja::seuraaja(const std::string& n) : nimi(n), next(nullptr) {} // Konstruktori

std::string seuraaja::getNimi() const { // Palauta nimi
    return nimi;
}

void seuraaja::paivitys(const std::string& viesti) { // Päivitys
    std::cout << nimi << " sai viestin: " << viesti << std::endl; // Tulosta viesti
}