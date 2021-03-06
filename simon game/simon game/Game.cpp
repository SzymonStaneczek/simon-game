/// <summary>
/// @author  Szymon Staneczek 
/// @date January 2022
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font
	setupButtons(); 

}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_buttonBlue);
	m_window.draw(m_buttonGreen);
	m_window.draw(m_buttonRed);
	m_window.draw(m_buttonYellow);
	m_window.draw(m_simonText);
	m_window.draw(m_easyText);
	m_window.draw(m_mediumText);
	m_window.draw(m_hardText);
	m_window.draw(m_exitText);
	m_window.display();
	
}

void Game::setupButtons()
{
	m_buttonBlue.setSize(sf::Vector2f(200.0f, 200.0f));
	m_buttonBlue.setFillColor(BLUE);
	m_buttonBlue.setPosition(sf::Vector2f(570.0f, 30.0f));

	m_buttonGreen.setSize(sf::Vector2f(200.0f, 200.0f));
	m_buttonGreen.setFillColor(GREEN);
	m_buttonGreen.setPosition(sf::Vector2f(350.0f, 250.0f));

	m_buttonRed.setSize(sf::Vector2f(200.0f, 200.0f));
	m_buttonRed.setFillColor(RED);
	m_buttonRed.setPosition(sf::Vector2f(350.0f, 30.0f));

	m_buttonYellow.setSize(sf::Vector2f(200.0f, 200.f));
	m_buttonYellow.setFillColor(YELLOW);
	m_buttonYellow.setPosition(sf::Vector2f(570.0f, 250.0f));
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	m_simonText.setFont(m_ArialBlackfont);
	m_simonText.setFillColor(RED);
	m_simonText.setCharacterSize(50);
	m_simonText.setPosition(50, 30);
	m_simonText.setString("SIMON");

	m_easyText.setFont(m_ArialBlackfont);
	m_easyText.setFillColor(GREEN);
	m_easyText.setCharacterSize(20);
	m_easyText.setPosition(50, 100);
	m_easyText.setString("PRESS GREEN FOR \n EASY MODE");

	m_mediumText.setFont(m_ArialBlackfont);
	m_mediumText.setFillColor(YELLOW);
	m_mediumText.setCharacterSize(20);
	m_mediumText.setPosition(50, 200);
	m_mediumText.setString("PRESS YELLOW FOR \n MEDIUM MODE");

	m_hardText.setFont(m_ArialBlackfont);
	m_hardText.setFillColor(RED);
	m_hardText.setCharacterSize(20);
	m_hardText.setPosition(50, 300);
	m_hardText.setString("PRESS RED FOR \n HARD MODE");

	m_exitText.setFont(m_ArialBlackfont);
	m_exitText.setFillColor(BLUE);
	m_exitText.setCharacterSize(20);
	m_exitText.setPosition(50, 400);
	m_exitText.setString("PRESS BLUE TO \n EXIT GAME");

}


