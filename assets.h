#ifndef ASSETS
#define ASSETS

#include <SFML/Graphics.hpp>
class AssetHandler{
	public:
	sf::Image TREEIMG;
	sf::Image STONEIMG;
	sf::Image IRONIMG;
	sf::Image FORTRESSIMG;
	sf::Image SETTLERIMG;	
	sf::Image MENU_BACKGROUND_IMG;
	sf::Image FHOUSEIMG;

	sf::Texture TREETEX;
	sf::Texture STONETEX;
	sf::Texture IRONTEX;
	sf::Texture FORTRESSTEX;
	sf::Texture SETTLERTEX;
	sf::Texture MENU_BACKGROUND_TEX;
	sf::Texture FHOUSETEX;

	AssetHandler(){
		TREEIMG.loadFromFile("sprites/Tree1.png");
		TREETEX.loadFromImage(TREEIMG);

		STONEIMG.loadFromFile("sprites/Stone0.png");
		STONETEX.loadFromImage(STONEIMG);

		IRONIMG.loadFromFile("sprites/Iron0.png");
		IRONTEX.loadFromImage(IRONIMG);
		
		FORTRESSIMG.loadFromFile("sprites/tower.png");
		FORTRESSTEX.loadFromImage(FORTRESSIMG);

		SETTLERIMG.loadFromFile("sprites/settler0.png");
		SETTLERTEX.loadFromImage(SETTLERIMG);

		MENU_BACKGROUND_IMG.loadFromFile("sprites/menutile.jpg");
		MENU_BACKGROUND_TEX.loadFromImage(MENU_BACKGROUND_IMG);

		FHOUSEIMG.loadFromFile("sprites/familyhouse.png");
		FHOUSETEX.loadFromImage(FHOUSEIMG);
	}

};

AssetHandler ASSETHANDLER;

#endif
