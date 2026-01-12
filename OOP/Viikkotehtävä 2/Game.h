/*
1. Toteuta viikkotehtävän 1 mukainen arvauspeli nyt oliopohjaisesti. 
Toteuta alla olevan luokkakaavion mukainen luokka Game
Konstruktorissa parametrinä annetaan maksimiarvo, mille välille 1-maxNumber peli arpoo arvattavan luvun.
Play()-jäsenfunktioon toteutetaan peli
printGameResult()-jäsenfunktiosta kutsutaan kun peli on päättynyt. Se tulostaa oikean vastauksen ja kuinka monta arvausta siihen tarvittiin.
Luokan toteutuksessa täytyy olla molemmat otsikkotiedosto Game.h ja luokan toteutus Game.cpp

2. Lisää peliin debug-tietoa, tulostamalla kontruktorista ja jäsenfunktioista mitä niissä tapahtuu. Esimerkki alla kuvassa. 

3. Lopuksi vielä toteuta ohjelmaan main.cpp-kooditiedosto, missä main()-funktiossa luodaan Game-olio ja ajetaan peli. 

*/

#ifndef GAME_H
#define GAME_H

class Game {
private:
    int maxNumber;
    int randomNumber;
    int guessCount;

public:
    ~Game();
    Game(int maxNum);
    void play();
    void printGameResult();
};

#endif