#include "mainwindow.h"
#include <QDebug>
#include "awardPrize.h"
#include "myKeyEvents.h"
#include "gameelement.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      file(QString("/home/" + qgetenv("USER") + "/.config/flappyBird/config.conf"), this)
{
    priceLife= file.readKey("priceLife").toInt();
    levelOccilation= file.readKey("levelOccilation").toInt();
    initialVelocity= file.readKey("initialVelocity").toDouble();
    increaseVelocity= file.readKey("increaseVelocity").toDouble();
    numberOfLevelPipes= file.readKey("numberOfLevelPipes").toInt();
    int intKeyUp= file.readKey("keyUpPin").toInt();
    int intKeyLeft= file.readKey("keyLeftPin").toInt();
    int intKeyRight= file.readKey("keyRightPin").toInt();
    int intKeyBack= file.readKey("keyBackPin").toInt();
    int intCoinAceptor= file.readKey("coinAceptorPin").toInt();
    int intProductsManager= file.readKey("productsManagerPin").toInt();
    double birdUpVelocity= file.readKey("birdUpVelocity").toDouble();
    double birdDownAceleration= file.readKey("birdDownAceleration").toDouble();
    int gameLives= file.readKey("gameLives").toInt();
    int gameLevel= file.readKey("gameLevel").toInt() - 1;
    //gameLevel= 9;
    int gameScore= file.readKey("gameScore").toInt();


    //setFocusPolicy(Qt::NoFocus);
    qsrand(QTime::currentTime().second());
    bufferPixmap = new QPixmap(288,512);
    // Set size.
    resize(540,760);


    /* Init 2 buttons. */
    windowPrize= new awardPrize(this);
    windowPrize->getManager()->setSensor(intProductsManager);
    startButton = new QPushButton(this);
    startButton->setGeometry(QRect((20.0/288)* width(),
                                   (341.0/512)* height(),
                                   (117.0/288)* width(),
                                   (71.0/512)* height()));

    startButton->setStyleSheet("QPushButton{border-image:url(" +  GameElement::url + "image/button_play.png);}" +
                               "QPushButton:pressed{margin: 2px 2px 2px 2px;}"
                               "QPushButton:focus{margin: 5px 5px 5px 5px}"
                               "QPushButton{margin: 10px 10px 10px 20px}");

    connect(startButton, &QPushButton::pressed, this,  [=](){
        if(level == 10) return;
        setNextLevel();
        startGame();
    } );

    prizeButton = new QPushButton(this);
    prizeButton->setGeometry(QRect((151.0/288)* width(),
                                   (341.0/512)* height(),
                                   (117.0/288)* width(),
                                   (71.0/512)* height()));


    prizeButton->setStyleSheet("QPushButton{border-image:url(" +  GameElement::url + "image/reclamar_premio.png);}" +
                               "QPushButton:pressed{margin: 2px 2px 2px 2px;}"
                               "QPushButton:focus{margin: 5px 5px 5px 5px}"
                               "QPushButton{margin: 10px 10px 10px 10px}");

    prizeButton->setEnabled(false);
    connect( prizeButton, SIGNAL(pressed()), this, SLOT(deliverPrize()));

    /* Init all the game elements. */
    background = new EleBackground();
    ground = new EleGround();
    bird = new EleBird();
    bird->setDownAceleration(birdDownAceleration);
    bird->setUpVelocity(birdUpVelocity);
    scoreboard = new EleScoreBoard(QRectF(20.5, 0.0, 10.0, 25.0));
    readyboard = new EleReadyBoard();
    overboard = new EleOverBoard();
    titleboard = new EleTitleBoard();
    pipe[0] = new ElePipe(false, 0);
    pipe[1] = new ElePipe(false, 1);
    pipe[2] = new ElePipe(false, 2);
    pipe[0]->setOccilation(false);
    pipe[1]->setOccilation(false);
    pipe[2]->setOccilation(false);

    livesboard= new EleScoreBoard(QRectF(131.5, 0.0, 25.0, 45.0));
    levelboard= new EleScoreBoard(QRectF(242.5, 0.0, 25.0, 45.0));


    impactBirdRect.setRect(0,0,0.4* bird->getBindRect().width(),
                           0.4* bird->getBindRect().height());

    /* Sound */
    soundDie = new QSound( GameElement::url + "sounds/sfx_die.wav");
    soundHit = new QSound( GameElement::url + "sounds/sfx_hit.wav");
    soundPoint = new QSound( GameElement::url + "sounds/sfx_point.wav");
    soundSwooshing = new QSound( GameElement::url + "sounds/sfx_swooshing.wav");
    soundWing = new QSound( GameElement::url + "sounds/sfx_wing.wav");

    /* The refresh rate : 50Hz */
    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
    timer.start(20);

    /* Connect signals and slots */
    connect( pipe[0],SIGNAL(pipePass()),this,SLOT(getScore()));
    connect( pipe[1],SIGNAL(pipePass()),this,SLOT(getScore()));
    connect( pipe[2],SIGNAL(pipePass()),this,SLOT(getScore()));

    connect( overboard,SIGNAL(buttonVisible(bool,bool,bool)),this,SLOT(setButtonVisible(bool,bool,bool)));
    connect(windowPrize, &awardPrize::selectedPrize, this, [=](){
        //displayInfo();
        prizeButton->setEnabled(false);
        level= 0;
        gameTitle();
    });


    // Game Start.
    level= gameLevel;
    lives= gameLives;
    score= gameScore;

    scoreboard->setScore(score);
    livesboard->setScore(lives);
    levelboard->setScore(level);

    gameTitle();

    keyUp= new Key(intKeyUp, 100, this);
    keyRight= new Key(intKeyRight, 100, this);
    keyLeft= new Key(intKeyLeft, 100, this);
    keyBack= new Key(intKeyBack, 100, this);
    coinAceptor= new Key(intCoinAceptor, 100, this);

    connect(coinAceptor, &Key::pressed, this, [=](){
        coinIn(500);
    });

    connect(this, SIGNAL(scoreChanged(int)), this, SLOT(nextLevel(int)));

    connect(keyUp, SIGNAL(pressed()), this, SLOT(enterPressed()));

    connect(keyLeft, &Key::pressed, this, [=](){
        left_pressed();
    });

    connect(keyRight, &Key::pressed, this, [=](){
        right_pressed();
    });

    billetero= new ID003_Lib_V3();
    connect(billetero, SIGNAL(entroDinero(int)), this, SLOT(coinIn(int)));
    billetero->abrirPuerto(file.readKey("urlBilletero").toString().toUtf8().data());
    billetero->start();
}

MainWindow::~MainWindow()
{
    delete  startButton;
    delete  prizeButton;
    delete  background;
    delete  ground;
    delete  bird;
    delete  scoreboard;
    delete  livesboard;
    delete  readyboard;
    delete  overboard;
    delete  titleboard;
    delete  pipe[0];
    delete  pipe[1];
    delete  pipe[2];
    delete  billetero;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

    /* When the game playing, bird up */
    if(status == GAMEPLAY && event->key() == Qt::Key_Enter ) {
        bird->birdUp();
        soundWing->stop();
        soundWing->play();
    }

    else if( ( status == GAMEREADY) && lives > 0 && event->key() == Qt::Key_Enter ) {
        gamePlay();
    }

    else if(status == GAMEOVER){
        qDebug() << "LOSER!!!!" << endl;
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter( bufferPixmap);
    /* Draw all the elements. */
    background->logic();
    background->draw(&painter);

    pipe[0]->logic();
    pipe[0]->draw(&painter);

    pipe[1]->logic();
    pipe[1]->draw(&painter);

    pipe[2]->logic();
    pipe[2]->draw(&painter);

    bird->logic();
    bird->draw(&painter);

    scoreboard->logic();
    scoreboard->draw(&painter);

    livesboard->logic();
    livesboard->draw(&painter);

    levelboard->logic();
    levelboard->draw(&painter);

    readyboard->logic();
    readyboard->draw(&painter);

    titleboard->logic();
    titleboard->draw(&painter);

    ground->logic();
    ground->draw(&painter);

    overboard->logic();
    overboard->draw(&painter);

    QPainter mainWindowPainter(this);
    mainWindowPainter.drawPixmap(QRect(0,0, width(), height()),* bufferPixmap);

    if( status == GAMEPLAY)
    {
        /* update the impact rectangle of bird. */
        impactBirdRect.moveCenter( bird->getBindRect().center());

        /* To test if the impact happened. */
        if(impactBirdRect.intersects( ground->getBindRect()))
        {
            soundHit->play();
            lostLife();
        }
        if( impactBirdRect.intersects( pipe[0]->getRect(above))
                || impactBirdRect.intersects( pipe[0]->getRect(following))
                || impactBirdRect.intersects( pipe[1]->getRect(above))
                || impactBirdRect.intersects( pipe[1]->getRect(following))
                || impactBirdRect.intersects( pipe[2]->getRect(above))
                || impactBirdRect.intersects( pipe[2]->getRect(following)))
        {
            //soundHit->play();
            soundDie->play();
            lostLife();
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    startButton->setGeometry(QRect((20.0/288)* width(),
                                   (341.0/512)* height(),
                                   (117.0/288)* width(),
                                   (71.0/512)* height()));
    prizeButton->setGeometry(QRect((151.0/288)* width(),
                                   (341.0/512)* height(),
                                   (117.0/288)* width(),
                                   (71.0/512)* height()));
}

void MainWindow::gameTitle()
{
    background->enabledLogic = true;
    background->enabledDraw = true;

    titleboard->enabledLogic = true;
    titleboard->enabledDraw = true;

    bird->enabledLogic = false;
    bird->enabledDraw = false;

    ground->enabledLogic = true;
    ground->enabledDraw = true;

    overboard->enabledLogic = false;
    overboard->enabledDraw = false;

    pipe[0]->enabledLogic = false;
    pipe[0]->enabledDraw = false;
    pipe[1]->enabledLogic = false;
    pipe[1]->enabledDraw = false;
    pipe[2]->enabledLogic = false;
    pipe[2]->enabledDraw = false;
    readyboard->enabledLogic = false;
    readyboard->enabledDraw = false;

    scoreboard->enabledLogic = false;
    scoreboard->enabledDraw = false;

    livesboard->enabledLogic = false;
    livesboard->enabledDraw = false;

    levelboard->enabledLogic= false;
    levelboard->enabledDraw= false;

    setButtonVisible(true,true,true);
    status = GAMETITLE;
}

void MainWindow::gameReady()
{

    background->enabledLogic = true;
    background->enabledDraw = true;

    titleboard->enabledLogic = false;
    titleboard->enabledDraw = false;

    bird->enabledLogic = false;
    bird->enabledDraw = true;

    ground->enabledLogic = true;
    ground->enabledDraw = true;

    overboard->enabledLogic = false;
    overboard->enabledDraw = false;

    pipe[0]->enabledLogic = false;
    pipe[0]->enabledDraw = false;
    pipe[1]->enabledLogic = false;
    pipe[1]->enabledDraw = false;
    pipe[2]->enabledLogic = false;
    pipe[2]->enabledDraw = false;

    readyboard->enabledLogic = true;
    readyboard->enabledDraw = true;

    scoreboard->enabledLogic = true;
    scoreboard->enabledDraw = true;

    livesboard->enabledLogic = true;
    livesboard->enabledDraw = true;


    levelboard->enabledLogic= true;
    levelboard->enabledDraw= true;


    setButtonVisible(false,false,false);
    status = GAMEREADY;
}

void MainWindow::gamePlay()
{
    background->enabledLogic = true;
    background->enabledDraw = true;

    titleboard->enabledLogic = false;
    titleboard->enabledDraw = false;

    bird->enabledLogic = true;
    bird->enabledDraw = true;

    ground->enabledLogic = true;
    ground->enabledDraw = true;

    overboard->enabledLogic = false;
    overboard->enabledDraw = false;

    pipe[0]->enabledLogic = true;
    pipe[0]->enabledDraw = true;
    pipe[1]->enabledLogic = true;
    pipe[1]->enabledDraw = true;
    pipe[2]->enabledLogic = true;
    pipe[2]->enabledDraw = true;

    readyboard->enabledLogic = false;
    readyboard->enabledDraw = false;

    scoreboard->enabledLogic = true;
    scoreboard->enabledDraw = true;

    livesboard->enabledLogic = true;
    livesboard->enabledDraw = true;

    levelboard->enabledLogic= true;
    levelboard->enabledDraw= true;
    coinInEnable= false;

    status = GAMEPLAY;
}

void MainWindow::lostLife()
{
    --lives;
    qDebug() << "LEVEL: " << level << endl;
    if(lives == 0 ){
        gameOver();
        coinInEnable= true;
        return;
    }else{

        background->enabledLogic = true;
        background->enabledDraw = true;

        titleboard->enabledLogic = false;
        titleboard->enabledDraw = false;

        bird->enabledLogic = true;
        bird->enabledDraw = true;

        ground->enabledLogic = false;
        ground->enabledDraw = true;

        pipe[0]->enabledLogic = false;
        pipe[0]->enabledDraw = true;
        pipe[1]->enabledLogic = false;
        pipe[1]->enabledDraw = true;
        pipe[2]->enabledLogic = false;
        pipe[2]->enabledDraw = true;

        readyboard->enabledLogic = false;
        readyboard->enabledDraw = false;

        scoreboard->enabledLogic = false;
        scoreboard->enabledDraw = false;

        livesboard->enabledLogic = false;
        livesboard->enabledDraw = false;

        levelboard->enabledLogic= false;
        levelboard->enabledDraw= false;

        overboard->setScore(score);
        overboard->enabledLogic = true;
        overboard->enabledDraw = true;

        level= 0;
        score= 0;
        levelboard->setScore(level);
        scoreboard->setScore(score);
        livesboard->setScore(lives);
        status = LOSTLIFE;
    }
}

void MainWindow::gameOver()
{
    background->enabledLogic = true;
    background->enabledDraw = true;

    titleboard->enabledLogic = false;
    titleboard->enabledDraw = false;

    bird->enabledLogic = true;
    bird->enabledDraw = true;

    ground->enabledLogic = false;
    ground->enabledDraw = true;

    pipe[0]->enabledLogic = false;
    pipe[0]->enabledDraw = true;
    pipe[1]->enabledLogic = false;
    pipe[1]->enabledDraw = true;
    pipe[2]->enabledLogic = false;
    pipe[2]->enabledDraw = true;

    readyboard->enabledLogic = false;
    readyboard->enabledDraw = false;

    scoreboard->enabledLogic = false;
    scoreboard->enabledDraw = false;

    livesboard->enabledLogic = false;
    livesboard->enabledDraw = false;

    levelboard->enabledLogic= false;
    levelboard->enabledDraw= false;

    overboard->setScore(score);
    overboard->enabledLogic = true;
    overboard->enabledDraw = true;
    overboard->setGameOver(true);
    levelboard->setScore(level);
    scoreboard->setScore(0);
    livesboard->setScore(lives);

    status = GAMEOVER;
}

void MainWindow::startGame()
{
    /* Init all the game elements. */
    background->init();
    bird->init();
    scoreboard->init();
    livesboard->init();
    levelboard->init();
    readyboard->init();
    overboard->init();
    pipe[0]->init();
    pipe[1]->init();
    pipe[2]->init();

    // Game Start.
    gameReady();
    soundSwooshing->play();
}

void MainWindow::closeGame()
{
    if(lives == 0){
        close();
    }
}

void MainWindow::getScore()
{
    score += 1;
    scoreboard->setScore(score);
    soundPoint->play();
    emit scoreChanged(score);
}



void MainWindow::setButtonVisible(bool _startBtn, bool _closeBtn, bool _rateBtn)
{
    prizeButton->setVisible(_closeBtn);
    startButton->setVisible(_startBtn);
}



void MainWindow::coinIn(int dinero){
    if(coinInEnable){
        lives+= dinero / priceLife;
        qDebug() << lives << endl;
        livesboard->setScore(lives);
    }
}


void MainWindow::nextLevel(int score){
    if(score % numberOfLevelPipes == 0){

        if(level == 10){
            gameOver();
        }

        keyUp->disconnect(0,0,0);
        QTimer::singleShot(3000, this, [=](){
            connect(keyUp, SIGNAL(pressed()), this, SLOT(enterPressed()));
        });

        background->enabledLogic = true;
        background->enabledDraw = true;

        titleboard->enabledLogic = false;
        titleboard->enabledDraw = false;

        bird->enabledLogic = false;
        bird->enabledDraw = true;

        ground->enabledLogic = false;
        ground->enabledDraw = true;

        overboard->setScore(score);
        levelboard->setScore(level);
        overboard->enabledLogic = true;
        overboard->enabledDraw = true;

        pipe[0]->enabledLogic = false;
        pipe[0]->enabledDraw = true;
        pipe[1]->enabledLogic = false;
        pipe[1]->enabledDraw = true;
        pipe[2]->enabledLogic = false;
        pipe[2]->enabledDraw = true;

        readyboard->enabledLogic = false;
        readyboard->enabledDraw = false;

        scoreboard->enabledLogic = false;
        scoreboard->enabledDraw = false;

        livesboard->enabledLogic = false;
        livesboard->enabledDraw = false;

        levelboard->enabledLogic= false;
        levelboard->enabledDraw= false;

        if(level == 3 || level == 6 || level == 9 || level == 1){
            prizeButton->setEnabled(true);
        }else{
            prizeButton->setEnabled(false);
        }

        status = NEXTLEVEL;
    }
}

void MainWindow::setNextLevel(){
    ++level;
    levelboard->setScore(level);
    qDebug() << "Set next level: " << level << endl;
    if(status == LOSTLIFE || status == GAMETITLE){
        pipe[0]->setSpeedX(initialVelocity);
        pipe[1]->setSpeedX(initialVelocity);
        pipe[2]->setSpeedX(initialVelocity);

    }else if(level < 8){
        pipe[0]->setSpeedX(pipe[0]->getSpeedX() + increaseVelocity);
        pipe[1]->setSpeedX(pipe[1]->getSpeedX() + increaseVelocity);
        pipe[2]->setSpeedX(pipe[2]->getSpeedX() + increaseVelocity);
    }

    if(level >= levelOccilation){
        pipe[0]->setSpeedX(1.5);
        pipe[1]->setSpeedX(1.5);
        pipe[2]->setSpeedX(1.5);
        pipe[0]->setOccilation(true);
        pipe[1]->setOccilation(true);
        pipe[2]->setOccilation(true);
        pipe[0]->setRandomColor(true);
        pipe[1]->setRandomColor(true);
        pipe[2]->setRandomColor(true);
    }
}

void MainWindow::deliverPrize(){
    qDebug() << level << "deliver prize" << endl;
    if(level == 3 || level == 6 || level == 9 || level == 1 ){
        status= DELIVERPRIZE;
        windowPrize->enablePrizes(level);

#ifdef DEBUG
        windowPrize->show();
#else
        windowPrize->showMaximized();
#endif

    }else{
        return;
    }
}

void MainWindow::enterPressed(){
    qDebug() << status << endl;
    if(status == DELIVERPRIZE){
        space_pressed();
    }else if(status == GAMEREADY || status == GAMEPLAY){
        enter_pressed();
    }else{
        space_pressed();
    }
}