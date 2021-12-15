#ifndef _Organism_H
#define _Organism_H

#include <iostream>
#include "GameSpecs.h"

using namespace std;

class City;

class Organism
{
protected:
	int x;
	int y;
	int width;
	int height;
	int breedCounter;
	int starveCounter;
	bool hasGone;
	City* city;

	enum { NORTH, EAST, SOUTH, WEST, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST };

public:
	Organism();
	Organism(City* city, int posx, int posy);
	virtual ~Organism();

	virtual void move() = 0;
	virtual void spawn() = 0;
	virtual void turn() = 0;
	virtual char getSpecies() = 0;

	void setPosition(int x, int y);
	bool getHasGone();

};

#endif
