#ifndef _Organism_H
#define _Organism_H

#include <iostream>

using namespace std;

class City;

class Organism
{
protected:
	int x;
	int y;
	int width;
	int height;
	City* city;

	enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
	Organism();
	Organism(City* city, int posx, int posy);
	virtual ~Organism();

	virtual void move() = 0;
	virtual void spawn() = 0;
	virtual int getSpecies() = 0; //this could also be coded concrete here
	virtual void getPosition() = 0;

	void setPosition(int x, int y);
};

#endif
