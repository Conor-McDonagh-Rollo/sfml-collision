#include <./include/Game.h>
#include <SFML/Graphics.hpp>

using namespace sf;

sf::RenderWindow* window = new RenderWindow(sf::VideoMode(1000, 1000), "Launching...");;

sf::CircleShape player_shape;
sf::CircleShape npc_shape;
sf::CircleShape npc_shape2;
sf::CircleShape npc_shape3;

Game::Game(){}

void Game::initialize()
{
	window->setSize(sf::Vector2u(640, 480));
	window->setTitle("Game");

	player = new Player();
	player_shape.setRadius(50.0f);
	player_shape.setFillColor(sf::Color(0, 255, 0));
	player_shape.setOutlineThickness(10);
	player_shape.setOutlineColor(sf::Color(0, 0, 255));

	npc = new NPC();
	npc_shape.setRadius(100.0f);
	npc_shape.setFillColor(sf::Color(0, 0, 255));
	npc_shape.setOutlineThickness(10);
	npc_shape.setOutlineColor(sf::Color(0, 255, 0));

	npc_shape.setPosition(sf::Vector2f(150.0f, 150.0f));

	npc->setX(npc_shape.getPosition().x);
	npc->setY(npc_shape.getPosition().y);
	npc->setR(npc_shape.getRadius());


	npc2 = new NPC();
	npc_shape2.setRadius(100.0f);
	npc_shape2.setFillColor(sf::Color(0, 0, 255));
	npc_shape2.setOutlineThickness(10);
	npc_shape2.setOutlineColor(sf::Color(0, 255, 0));

	npc_shape2.setPosition(sf::Vector2f(350.0f, 150.0f));

	npc2->setX(npc_shape2.getPosition().x);
	npc2->setY(npc_shape2.getPosition().y);
	npc2->setR(npc_shape2.getRadius());


	npc3 = new NPC();
	npc_shape3.setRadius(100.0f);
	npc_shape3.setFillColor(sf::Color(0, 0, 255));
	npc_shape3.setOutlineThickness(10);
	npc_shape3.setOutlineColor(sf::Color(0, 255, 0));

	npc_shape3.setPosition(sf::Vector2f(650.0f, 150.0f));

	npc3->setX(npc_shape3.getPosition().x);
	npc3->setY(npc_shape3.getPosition().y);
	npc3->setR(npc_shape3.getRadius());
}

void Game::run()
{
	initialize();

	while (window->isOpen())
	{
		update();
		draw();
	}
}

void Game::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		// Update Based on Mouse Position
		player_shape.setPosition(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));

		player->setX(player_shape.getPosition().x);
		player->setY(player_shape.getPosition().y);
		player->setR(player_shape.getRadius());

		if(player->collision(npc)){
			npc_shape.setOutlineColor(sf::Color(255, 0, 0));
		}
		else{
			npc_shape.setOutlineColor(sf::Color(0, 255, 0));
		}

		if(player->collision(npc2)){
			npc_shape2.setOutlineColor(sf::Color(255, 0, 0));
		}
		else{
			npc_shape2.setOutlineColor(sf::Color(0, 255, 0));
		}

		if(player->collision(npc3)){
			npc_shape3.setOutlineColor(sf::Color(255, 0, 0));
		}
		else{
			npc_shape3.setOutlineColor(sf::Color(0, 255, 0));
		}

		player->update();
		npc->update();
		npc2->update();
		npc3->update();

	}

}

void Game::draw()
{
	window->clear();
	window->draw(npc_shape);
	window->draw(npc_shape2);
	window->draw(npc_shape3);
	window->draw(player_shape);
	window->display();
}


