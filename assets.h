#ifndef ASSETS
#define ASSETS

#include <SFML/Graphics.hpp>
class AssetHandler{
	public:
	sf::Image TREEIMG;
	sf::Image STONEIMG;
	sf::Image IRONIMG;
	sf::Image FORTRESSIMG;
	sf::Image MENU_BACKGROUND_IMG;
	
	sf::Texture TREETEX;
	sf::Texture STONETEX;
	sf::Texture IRONTEX;
	sf::Texture FORTRESSTEX;
	sf::Texture MENU_BACKGROUND_TEX;

	AssetHandler(){
		TREEIMG.loadFromFile("sprites/Tree1.png");
		TREETEX.loadFromImage(TREEIMG);

		STONEIMG.loadFromFile("sprites/Stone.png");
		STONETEX.loadFromImage(STONEIMG);

		IRONIMG.loadFromFile("sprites/Iron.png");
		IRONTEX.loadFromImage(IRONIMG);
		
		FORTRESSIMG.loadFromFile("sprites/tower.png");
		FORTRESSTEX.loadFromImage(FORTRESSIMG);

		MENU_BACKGROUND_IMG.loadFromFile("sprites/menutile.png");
		MENU_BACKGROUND_TEX.loadFromImage(MENU_BACKGROUND_IMG);
		MENU_BACKGROUND_TEX.setRepeated(true);
	}

};

AssetHandler ASSETHANDLER;

#endif
