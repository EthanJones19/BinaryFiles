#include <iostream>
#include <fstream>
#include "Game.h"

void Game::run()
{
	start();

	while (m_player->getIsAlive() && m_chicken->getIsAlive())
	{
		draw();

		update();
	}

	end();
}

void Game::start()
{
	int i = 0;
	std::fstream file;
	m_player = new Character();
	m_chicken = new Character();

	//Asks player if they would like to load the game or start a new game.
	std::cout << "Would you like to load save data?" << std::endl;
	std::cout << "Press 1 to load a save." << std::endl;
	std::cout << "Press 2 to start new game." << std::endl;

	std::cin >> i;

	//Will load player and chicken stats from a saved game.
	if (i == 1)
	{
		file.open("save.txt", std::ios::in, std::ios::binary);

		if (!file.is_open())
		{
			std::cout << "File not found" << std::endl;
			std::cout << "New game will start" << std::endl;
			system("pause");
			return;
		}
		else
		{
			file.read((char*)m_player, sizeof(Character));
		}
		file.close();
	}
}

void Game::update()
{
	std::fstream file;
	int action = ' ';

	//Gives player the options
	std::cout << "What would you like to do Player?" << std::endl;
	std::cout << "Press 1 to attack." << std::endl;
	std::cout << "Press 2 to save progress." << std::endl;

	std::cin >> action;

	//Player does damage to chicken
	if (action == 1)
	{
		m_player->attack(m_chicken);
		std::cout << "Player does " << m_player->getDamage() << " damage to Chicken." << std::endl;
		system("pause");
	}

	//Saves the player and chicken current stats to file.
	else if (action == 2)
	{
		file.open("save.txt", std::ios::app, std::ios::binary);

		if (!file.is_open())
		{
			std::cout << "Save file not found" << std::endl;
			return;
		}
		else
		{
			file.write((char*)m_player, sizeof(Character));
		}
		file.close();
	}

	//Shows the chicken attacking the player
	if (action == 1)
	{
		std::cout << "Chicken attacks and does " << m_chicken->getDamage() << " damage to Player." << std::endl;
		m_chicken->attack(m_player);
		system("pause");
	}
	//Displays that the game has saved.
	if (action == 2)
	{
		std::cout << "Save complete!" << std::endl;
		system("pause");
	}
}

//Draws the stats for player and chicken.
void Game::draw()
{
	system("cls");

	std::cout << "Chicken health: " << m_chicken->getHealth() << std::endl;

	std::cout << "Player health: " << m_player->getHealth() << std::endl;
}

void Game::end()
{
	//Displays text if player health is above 0.
	if (m_player->getIsAlive() == true)
	{
		system("cls");
		std::cout << "Player wins!" << std::endl;
		system("pause");
	}
	//Displays if player health is below 0.
	else
	{
		system("cls");
		std::cout << "The chicken has won..... XD" << std::endl;
		system("pause");
	}

	delete m_player;
	delete m_chicken;
}