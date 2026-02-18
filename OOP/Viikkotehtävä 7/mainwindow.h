/*
1. Toteuta yksikertainen Qt Widged applikaatio, jossa on alla olevan kuvan mukainen käyttöliittymä. Count nappia painettaessa LineEdit olion numero kasvaa ja Reset nappia painettaessa se nollaantuu.
2. Käyttöliittymässä Number1, Number2 ja Result ovat Qlabel olioita, joita käytetään pelkkinä teksti kenttinä. Eli ne eivät vaadi mitään koodia.
3. Laatikot, joissa on numerot 1,2 ja 3 ovat QlineEdit olioita ja ne kannattaisi nimetä num1, num2 ja result olioiksi.
4. Kaikki loput käyttöliittymän laatikot ovat QPushButton olioita. Numero oliot kannatta nimetä N0,N1, N2, N9 ja operaatio oliot add, sub, mul, div nimisiksi ja lopulta clear ja enter oliot.

Vihjeitä:
1. Aloita tekemällä käyttöliittymän kaikki elementit, nimeä ne ehdotetulla tavalla.
2. Tee kaikille QPushButton olioille click handler samaan tyyliin kuin tehtävässä 1.
3. Tee mainwindow.h tiedostoon yllä esitetyt private muuttujat ja metodit.
4. Laita jokaiseen numeronäppäimen click handleriin kutsu numberClickHandler() funktioon. Eli kaikki numeronäppäimet käsitellään samalla tavalla. Yritä saada ensin toimimaan numeroiden vastaanottaminen näppäimien avulla alla olevan esimerkin mukaan (esimerkissä on ensin painettu numeroa 1 ja sitten numeroa 2. Ohjelma kirjoittaa qDebug() funktion avulla Qstring muuttujien number1 ja number2 muuttujen arvot jokaisen numeronäppäin painalluksen jälkeen). Tähän löytyy esimerkkikoodeja. 
5. +,-,* tai / näppäin tallentaa operand muuttujaan numeron 0,1,2,3 sen mukaan mitä operaatiota oli painettu ja vaihtaa state = 1 => state = 2, jolloin numeronäppäimet ”keräävät” merkkejä number2 muuttujaan.
6. Clear näppäin asettaa state = 1, number1 =””, number2=”” ja nollaa QLineEdit ikkunat.
7. Enter näppäin muuttaa number1 ja number2 Qstring arvot float arvoiksi ja tekee operand muuttujan mukaisen laskutoimituksen ja tallentaa tuloksen result muuttujaan, jonka tulos kirjoitetaan tietysti QLineEdit ikkunaan.
*/

ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE

namespace UI { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow (QWidget *parent = nullptr);
        ~MainWindow();
    
    private:
        UI::MainWindow *ui;
        QString number1;
        QString number2;
        int operand;
        int state;
        void numberCLickHandler();
}

#endif