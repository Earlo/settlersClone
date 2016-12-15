#ifndef CONSTS
#define CONSTS
//const for screen
const int MOVSPEED = 4;
const int DRAWSIZE = 4;

const int VIEWX = 600;
const int VIEWY = 600;
const int MENUX = 200;
const int MENUY = 600;

const int SCREENX = VIEWX + MENUX;
const int SCREENY = 600;

const double VIEWPORTW = (double)VIEWX/(double)SCREENX;
const double MENUPOWRTW = 1.0 - VIEWPORTW;

const int CAMCENTERX = VIEWX/2;
const int CAMCENTERY = VIEWY/2;
//const int WORLDX = 1000;
//const int WORLDY = 1000;
const int WORLDX = 300;
const int WORLDY = 300;

const int SCROLLX = WORLDX * DRAWSIZE - SCREENX;
const int SCROLLY = WORLDY * DRAWSIZE - SCREENY;
const unsigned int TILESTODRAWX = (VIEWX/DRAWSIZE)+3;
const unsigned int TILESTODRAWY = (VIEWY/DRAWSIZE)+3;
//consts for spatial hash
const int HASHRES = 10;
const int ENTHASH = HASHRES*DRAWSIZE;
const int HASHX = WORLDX/HASHRES;
const int HASHY = WORLDY/HASHRES;
//consts for pathfinding
const double MAXCOST = 10.0;
const double BASECOST = 1.0;
//Building requirements
const int FORT_W = 4; //fortress
const int FORT_S = 20;
const int FORT_I = 10;

const int WEP_W = 2; //weaponsmith
const int WEP_S = 10;
const int WEP_I = 15;

const int FAMILY_W = 12; //familyhouse
const int FAMILY_S = 5;
const int FAMILY_I = 2;

const int WARE_W = 15; //warehouse
const int WARE_S = 6;
const int WARE_I = 0;


//consts for game
const double STLSPEED = 2.0;


#endif
