#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define DEBUG


#include <QMainWindow>

#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QSound>

#include <QString>
#include <QCoreApplication>
#include <QApplication>

#include "elebackground.h"
#include "eleground.h"
#include "elebird.h"
#include "elepipe.h"
#include "elescoreboard.h"
#include "elereadyboard.h"
#include "eleoverboard.h"
#include "eletitleboard.h"
#include "awardPrize.h"
#include "configurationFile.h"

#include "key.h"
#include <id003_lib_v3.h>



/* 6 status */
enum GameStatus{GAMETITLE,
                GAMEREADY,
                GAMEPLAY,
                GAMEOVER,
                NEXTLEVEL,
                LOSTLIFE,
                DELIVERPRIZE};

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;

    /* Buttons on the start panel. */
    QPushButton *startButton;
    QPushButton *prizeButton;


    /* Elements need to draw */
    EleBackground *background;
    EleGround *ground;
    EleBird *bird;
    ElePipe *pipe[3];
    EleScoreBoard *scoreboard;
    EleScoreBoard *livesboard;
    EleScoreBoard *levelboard;
    EleReadyBoard *readyboard;
    EleOverBoard *overboard;
    EleTitleBoard *titleboard;
    awardPrize *windowPrize;

    /* Sound */
    QSound *soundDie;
    QSound *soundHit;
    QSound *soundPoint;
    QSound *soundSwooshing;
    QSound *soundWing;

    int score; // Game score
    int level;
    int lives;
    int priceLife;
    int levelOccilation;
    int numberOfLevelPipes;
    double initialVelocity;
    double increaseVelocity;
    double nextLevelFactor;
    bool coinInEnable;

    QRectF impactBirdRect; // the rectangle used to test the impact of bird.
    GameStatus status;
    QTimer timer; // Main timer, refresh the interface.
    Key *keyUp;
    Key *keyRight;
    Key *keyLeft;
    Key *keyBack;
    Key *coinAceptor;

    ID003_Lib_V3 *billetero;
    configurationFile file;

    /*Corresponding  to 4 game status. */
    void gameTitle();
    void gameReady();
    void gamePlay();
    void gameOver();
    void lostLife();
    void setNextLevel();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void resizeEvent(QResizeEvent *);

public slots:
    void getScore(); // socre increase.
    void startGame(); // The button clicked , game began.
    void closeGame();// The button clicked , game exit.

    void setButtonVisible(bool,bool,bool); // set 3 button visible .
    void coinIn(int);
    void nextLevel(int score);
    void deliverPrize();
    void enterPressed();

signals:
    void scoreChanged(int score);
};

#endif // MAINWINDOW_H
