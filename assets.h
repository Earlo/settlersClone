#ifndef ASSETS
#define ASSETS

#include <SFML/Graphics.hpp>
class AssetHandler{
	public:
	sf::Image TREEIMG;
	sf::Image STONEIMG;
	sf::Image IRONIMG;
	sf::Image FORTRESSIMG;
	
	sf::Texture TREETEX;
	sf::Texture STONETEX;
	sf::Texture IRONTEX;
	sf::Texture FORTRESSTEX;

	AssetHandler(){
		TREEIMG.loadFromFile("sprites/Tree1.png");
		TREETEX.loadFromImage(TREEIMG);

		STONEIMG.loadFromFile("sprites/Stone0.png");
		STONETEX.loadFromImage(STONEIMG);

		IRONIMG.loadFromFile("sprites/Iron0.png");
		IRONTEX.loadFromImage(IRONIMG);
		
		FORTRESSIMG.loadFromFile("sprites/tower.png");
		FORTRESSTEX.loadFromImage(FORTRESSIMG);
	}

};

AssetHandler ASSETHANDLER;

#endif
