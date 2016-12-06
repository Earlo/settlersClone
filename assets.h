#ifndef ASSETS
#define ASSETS

#include <SFML/Graphics.hpp>
class AssetHandler{
	public:
	sf::Image TREEIMG;
	sf::Image STONEIMG;
	sf::Image IRONIMG;

	sf::Texture TREETEX;
	sf::Texture STONETEX;
	sf::Texture IRONTEX;

	AssetHandler(){
		TREEIMG.loadFromFile("sprites/Tree1.png");
		TREETEX.loadFromImage(TREEIMG);

		STONEIMG.loadFromFile("sprites/Stone.png");
		STONETEX.loadFromImage(STONEIMG);

		IRONIMG.loadFromFile("sprites/Iron.png");
		IRONTEX.loadFromImage(IRONIMG);

	}

};

AssetHandler ASSETHANDLER;

#endif