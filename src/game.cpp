#include "game.h"

Game::Game() : mWindow(sf::VideoMode(740, 470), "Crally SFML"), mTimePerFrame(sf::seconds(1.f / 60.f)), mWorld(mWindow)
{

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
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
   /*if (key == sf::Keyboard::W) 
       mIsMovingUp = isPressed;
   else if (key == sf::Keyboard::S)
       mIsMovingDown = isPressed;
   else if (key == sf::Keyboard::D)
       mIsMovingRight = isPressed;
   else if (key == sf::Keyboard::A)
       mIsMovingLeft = isPressed;*/
}

void Game::update(sf::Time elapsedTime)
{
    mWorld.update(elapsedTime);
}

void Game::render()
{
    mWindow.clear(sf::Color(100, 100, 100, 255));
    mWorld.draw();
    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}
