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

    qDebug() << "Game start. Player 1's turn";
}

void MainWindow::on_switchPlayer1Button_clicked()
{
    if (!gameRunning || currentPlayer != 1) return;

    currentPlayer = 2;
    setGameInfoText("Player 2's turn", 14);

    ui->switchPlayer1Button->setEnabled(false);
    ui->switchPlayer2Button->setEnabled(true);

    qDebug() << "Switched to player 2";
}

void MainWindow::on_switchPlayer2Button_clicked()
{
    if (!gameRunning || currentPlayer != 2) return;

    currentPlayer = 1;
    setGameInfoText("Player 1's turn", 14);

    ui->switchPlayer1Button->setEnabled(true);
    ui->switchPlayer2Button->setEnabled(false);

    qDebug() << "Switched to player 1";
}

void MainWindow::updateTime()
{
    if (!gameRunning) return;

    if (currentPlayer == 1) {
        player1Time--;
        if (player1Time <= 0) {
            player1Time = 0;
            endGame(2);
            return;
        }
    } else {
        player2Time--;
        if (player2Time <= 0) {
            player2Time = 0;
            endGame(1);
            return;
        }
    }

    updateProgressBar();

    qDebug() << "Player 1:" << player1Time << "s, Player 2:" << player2Time << "s";
}

void MainWindow::updateProgressBar()
{
    if (gameTime > 0) {
        int progress1 = (player1Time * 100) / gameTime;
        int progress2 = (player2Time * 100) / gameTime;

        ui->progressBar1->setValue(progress1);
        ui->progressBar2->setValue(progress2);

        int min1 = player1Time / 60;
        int sec1 = player1Time % 60;
        int min2 = player2Time / 60;
        int sec2 = player2Time % 60;

        ui->timeLabel1->setText(QString("Player 1: %1:%2").arg(min1).arg(sec1, 2, 10, QChar('0')));
        ui->timeLabel2->setText(QString("Player 2: %1:%2").arg(min2).arg(sec2, 2, 10, QChar('0')));
    }
}

void MainWindow::setGameInfoText(QString text, short fontSize)
{
    ui->gameInfoLabel->setText(text);
    QFont font = ui->gameInfoLabel->font();
    font.setPointSize(fontSize);
    ui->gameInfoLabel->setFont(font);
}

void MainWindow::endGame(int winner)
{
    gameRunning = false;
    gameTimer->stop();

    QString winnerText = QString("TIME's UP! Player %1 wins!").arg(winner);
    setGameInfoText(winnerText, 16);

    ui->switchPlayer1Button->setEnabled(false);
    ui->switchPlayer2Button->setEnabled(false);
    ui->resetGameButton->setEnabled(true);

    qDebug() << "Game over. Winner: Player" << winner;
}

void MainWindow::on_resetGameButton_clicked()
{
    gameTime = 0;
    player1Time = 0;
    player2Time = 0;
    currentPlayer = 1;
    gameRunning = false;

    gameTimer->stop();

    ui->progressBar1->setValue(0);
    ui->progressBar2->setValue(0);
    ui->timeLabel1->setText("Player 1: 0:00");
    ui->timeLabel2->setText("Player 2: 0:00");

    setGameInfoText("Select game time", 12);

    ui->time5Button->setEnabled(true);
    ui->time10Button->setEnabled(true);
    ui->startGameButton->setEnabled(false);
    ui->switchPlayer1Button->setEnabled(false);
    ui->switchPlayer2Button->setEnabled(false);
    ui->resetGameButton->setEnabled(false);

    qDebug() << "Game reset";
}