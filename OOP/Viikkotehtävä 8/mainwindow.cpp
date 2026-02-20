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
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameTimer(new QTimer(this))
    , gameTime(0)
    , player1Time(0)
    , player2Time(0)
    , currentPlayer(1)
    , gameRunning(false)
{
    ui->setupUi(this);

    connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateTime);

    setGameInfoText("Select game time", 12);
    ui->startGameButton->setEnabled(false);
    ui->switchPlayer1Button->setEnabled(false);
    ui->switchPlayer2Button->setEnabled(false);
    ui->progressBar1->setValue(0);
    ui->progressBar2->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_time5Button_clicked()
{
    gameTime = 5 * 60;
    player1Time = gameTime;
    player2Time = gameTime;

    setGameInfoText("5 minutes selected. Press START GAME to begin.", 12);
    updateProgressBar();

    ui->startGameButton->setEnabled(true);
    gameRunning = false;
    gameTimer->stop();
}

void MainWindow::on_time10Button_clicked()
{
    gameTime = 10 * 60;
    player1Time = gameTime;
    player2Time = gameTime;

    setGameInfoText("10 minutes selected. Press START GAME to begin.", 12);
    updateProgressBar();

    ui->startGameButton->setEnabled(true);
    gameRunning = false;
    gameTimer->stop();
}

void MainWindow::on_startGameButton_clicked()
{
    startGame();
}

void MainWindow::startGame()
{
    if (gameTime == 0) {
        setGameInfoText("Please select a game time first.", 12);
        return;
    }

    gameRunning = true;
    currentPlayer = 1;

    setGameInfoText("Game started! Player 1's turn.", 12);

    ui->time5Button->setEnabled(false);
    ui->time10Button->setEnabled(false);
    ui->startGameButton->setEnabled(false);
    ui->switchPlayer1Button->setEnabled(true);
    ui->switchPlayer2Button->setEnabled(false);

    gameTimer->start(1000);

    QDebug() << "Game start. Player 1's turn";
}

void MainWindow::on_switchPlayer1Button_clicked()
{

}

void MainWindow::on_switchPlayer2Button_clicked()
{

}

void MainWindow::updateTime()
{

}

void MainWindow::updateProgressBar()
{

}

void MainWindow::setGameInfoText()
{

}

void MainWindow::endGame()
{

}

void MainWindow::on_resetGameButton_clicked()
{
    
}