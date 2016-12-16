#ifndef MENU_H
#define MENU_H


#include <iostream>
#include <SFML/Graphics.hpp>

#include "../assets.h"

#include "../constants.h"
#include "Game.h"

#include "logic/HumanPlayer.h"

#include "Fortress.h"
#include "Warehouse.h"
#include "Weaponsmith.h"
#include "Castle.h"
#include "FamilyHouse.h"


class Menu
{
public:
	bool clickflag = false;

	Menu(AssetHandler* ASSETHANDLER, SpatialHash* SHASH);

	int button1_clicked(sf::Event event, int x, int y);
	int button2_clicked(sf::Event event, int x, int y);
    int button3_clicked(sf::Event event, int x, int y);
    int button4_clicked(sf::Event event, int x, int y);


	int increase_wood(sf::Event event, int x, int y);
	int decrease_wood(sf::Event event, int x, int y);
	int increase_stone(sf::Event event, int x, int y);
	int decrease_stone(sf::Event event, int x, int y);
	int increase_iron(sf::Event event, int x, int y);
	int decrease_iron(sf::Event event, int x, int y);
	int increase_build(sf::Event event, int x, int y);


	void update(sf::Event event, int mouseX, int mouseY, int camX, int camY, Map* m, HumanPlayer* p, std::vector<Entity*>* v);

	bool startClick(sf::Event event, int mouseX, int mouseY, int camX, int camY, Map* m, HumanPlayer* p, std::vector<Entity*>* v);
	void draw_info(sf::RenderWindow &window, bool b1, bool b2, bool b3, bool b4, HumanPlayer* p);

	void drawmenu(sf::RenderWindow &window, HumanPlayer* p);

private:
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	bool b4 = false;
	int checker = 0;
	
	AssetHandler* ASSETHANDLER;
	SpatialHash* SHASH;
	sf::Font font;
	sf::Text wood_amount;
	sf::Text iron_amount;
	sf::Text stone_amount;
	sf::Text idle_amount;
	sf::Text info_text;
	sf::Text req_wood;
	sf::Text req_stone;
	sf::Text req_iron;
	sf::RectangleShape background;
	sf::RectangleShape infobox;
	sf::RectangleShape controlpanel;
	sf::RectangleShape button1;
	sf::RectangleShape button2;
	sf::RectangleShape button3;
	sf::RectangleShape button4;
	sf::RectangleShape build;
};

#endif


