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
	sf::Image WEPSMITHIMG;
	sf::Image CASTLEIMG;
	sf::Image FHOUSEICON;
	sf::Image FORTICON;
	sf::Image WSICON;
	sf::Image WAREIMG;
	sf::Image WAREICON;
	sf::Image CONTROLPANELIMG;
	sf::Image INFOIMG;

	sf::Texture TREETEX;
	sf::Texture STONETEX;
	sf::Texture IRONTEX;
	sf::Texture FORTRESSTEX;
	sf::Texture SETTLERTEX;
	sf::Texture MENU_BACKGROUND_TEX;
	sf::Texture FHOUSETEX;
	sf::Texture WEPSMITHTEX;
	sf::Texture CASTLETEX;
	sf::Texture FHOUSEICONT;
	sf::Texture FORTICONT;
	sf::Texture WSICONT;
	sf::Texture WARETEX;
	sf::Texture WAREICONT;
	sf::Texture CONTROLPANELTEX;
	sf::Texture INFOTEX;

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

		MENU_BACKGROUND_IMG.loadFromFile("sprites/menutile.png");
		MENU_BACKGROUND_TEX.loadFromImage(MENU_BACKGROUND_IMG);

		FHOUSEIMG.loadFromFile("sprites/familyhouse.png");
		FHOUSETEX.loadFromImage(FHOUSEIMG);

		WEPSMITHIMG.loadFromFile("sprites/weaponsmith.png");
		WEPSMITHTEX.loadFromImage(WEPSMITHIMG);

		CASTLEIMG.loadFromFile("sprites/castle.png");
		CASTLETEX.loadFromImage(CASTLEIMG);

		FHOUSEICON.loadFromFile("sprites/familyhouseICON.png");
		FHOUSEICONT.loadFromImage(FHOUSEICON);

		FORTICON.loadFromFile("sprites/towerICON.png");
		FORTICONT.loadFromImage(FORTICON);

		WSICON.loadFromFile("sprites/weaponsmithICON.png");
		WSICONT.loadFromImage(WSICON);

		WAREICON.loadFromFile("sprites/warehouseICON.png");
		WAREICONT.loadFromImage(WAREICON);

		WAREIMG.loadFromFile("sprites/warehouse.png");
		WARETEX.loadFromImage(WAREIMG);

		CONTROLPANELIMG.loadFromFile("sprites/controlpanel.png");
		CONTROLPANELTEX.loadFromImage(CONTROLPANELIMG);

		INFOIMG.loadFromFile("sprites/blankpanel.png");
		INFOTEX.loadFromImage(INFOIMG);

	}

};

AssetHandler ASSETHANDLER;

#endif
