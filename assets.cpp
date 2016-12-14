#include "assets.h"

AssetHandler::AssetHandler(){
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

	SETTLERWIMG.loadFromFile("sprites/settler0W.png");
	SETTLERWTEX.loadFromImage(SETTLERWIMG);

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

	BUILD.loadFromFile("sprites/constructionsite.png");
	BUILDTEX.loadFromImage(BUILD);

	BUILDICON.loadFromFile("sprites/buildbutton.png");
	BUILDICONT.loadFromImage(BUILDICON);

}
