#include "game.h"

Game::Game() : mWindow(sf::VideoMode(740, 470), "Crally SFML"), mTimePerFrame(sf::seconds(1.f / 60.f)),
    mSprite(), mTexture()
{
    if (!mTexture.loadFromFile("/home/crally/CRealm/wizard.png"))
    {
        printf("Debug: Failed to load texture from file, exeiting...\n");
        exit(1);
    }
    mSprite.setTexture(mTexture);
    mSprite.setPosition(100.f, 100.f);
    mSprite.setScale(.3f, .3f);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > mTimePerFrame)
        {
            timeSinceLastUpdate -= mTimePerFrame;
            processEvents();
            update(mTimePerFrame);
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();
        switch (event.type)
        {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
   if (key == sf::Keyboard::W) 
       mIsMovingUp = isPressed;
   else if (key == sf::Keyboard::S)
       mIsMovingDown = isPressed;
   else if (key == sf::Keyboard::D)
       mIsMovingRight = isPressed;
   else if (key == sf::Keyboard::A)
       mIsMovingLeft = isPressed;
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= 600.f;
    if (mIsMovingDown)
        movement.y += 600.f;
    if (mIsMovingLeft)
        movement.x -= 600.f;
    if (mIsMovingRight)
        movement.x += 600.f;

    mSprite.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    mWindow.clear(sf::Color(100, 100, 100, 255));
    mWindow.draw(mSprite);
    mWindow.display();
}
