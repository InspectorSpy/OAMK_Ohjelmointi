/*
1. Valitse projektiksi Qt Widgets Application.
2. Toteuta  sivun 3 kuvan mukainen käyttöliittymä shakkikello sovellukselle.
3. Shakkikello sovelluksen tulee toimia sivun 4 mukaisesti eli:
    1. Sovelluksen käynnistyessä käyttäjää pyydetään valitsemaan peliaika kahdella painikkeella. 
    2. Käyttäjän valitessa ajan, progressbar oliot näyttävät kummallekin pelaajalle 100% jäljellä olevaa peliaikaa.
    3. Käyttäjän aloittaessa pelin START GAME painikkeella pelaajan 1 aika alkaa vähenemään, kunnes pelaaja 1 painaa omaa switch player painikettaan siirtonsa tehtyään. Tällöin pelaajan 1 progressbar pysähtyy ja aika alkaa kulumaan pelaajan 2 progressbarissa.
    4. Jos jommankumman pelaajan player1Time tai player2Time muuttuja = 0, niin päädytään tähän neljänteen vaiheeseen.
    5. Pelin voi päättää missä vaiheessa tahansa, jolloin pelaajaa kehotetaan aloittamaan uusi peli valitsemalla peliaika ja käynnistämällä peli START GAME painikkeella.

HUOM: Luokkakaaviosta puuttuvat signaalit ja slotit. Mutta tietysti jokaiselle QPushButton oliolle täytyy oma click handlerinsä olla ja Qtimer luokan timeout() signaalia voidaan hyödyntää ajan kulumisen mittaamiseen. MainWindow luokassa oleva julkinen (public) timeout() funktio on public slots tyyppinen, eli siihen voidaan kytkeä Qtimer luokan timeout() signaali.

UpdateProgressBar() metodi päivittää kummankin progressbar olion tilanteen player1Time, player2Time ja gameTime muuttujien perusteella.

setGameInfoText(Qstring,short) metodin Qstring parametrin avulla voidaan tulostaa ohjetekstejä käyttöliittymän Label olioon ja metodin short parametrilla voidaan valita tuon ohjetekstin fontin koko.
*/

#include "mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}