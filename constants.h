#ifndef CONSTS
#define CONSTS

const int MOVSPEED = 4;
const int DRAWSIZE = 4;
const int SCREENX = 800;
const int SCREENY = 600;
const int VIEWX = 600;
const int VIEWY = 600;
const int CAMCENTERX = VIEWX/2;
const int CAMCENTERY = VIEWY/2;
const int WORLDX = 1000;
const int WORLDY = 1000;
const int SCROLLX = WORLDX * DRAWSIZE - SCREENX;
const int SCROLLY = WORLDY * DRAWSIZE - SCREENY;

const unsigned int TILESTODRAWX = (VIEWX/DRAWSIZE)+3;
const unsigned int TILESTODRAWY = (VIEWY/DRAWSIZE)+3;

#endif
