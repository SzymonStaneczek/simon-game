/// <summary>
/// author Szymon Staneczek January 2022
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

const::sf::Color RED{ 180,0,0,225 };
const::sf::Color GREEN{ 0,180,0,225 };
const::sf::Color BLUE{ 0,0,180,225 };
const::sf::Color YELLOW{ 180,180,0,225 };


class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void setupButtons();
	
	void setupFontAndText();


	sf::RectangleShape m_buttonRed;
	sf::RectangleShape m_buttonGreen;
	sf::RectangleShape m_buttonBlue;
	sf::RectangleShape m_buttonYellow;



	sf::Text m_simonText;
	sf::Text m_easyText;
	sf::Text m_mediumText;
	sf::Text m_hardText;
	sf::Text m_exitText;
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

