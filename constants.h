#ifndef CONSTS
#define CONSTS
//const for screen
const int MOVSPEED = 4;
const int DRAWSIZE = 4;
const int SCREENX = 800;
const int SCREENY = 600;
const int VIEWX = 600;
const int VIEWY = 600;
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
const int HASHX = WORLDX/HASHRES;
const int HASHY = WORLDY/HASHRES;
//consts for pathfinding
const double MAXCOST = 10.0;
const double BASECOST = 1.0;


#endif
