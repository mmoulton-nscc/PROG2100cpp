#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include "GameSpecs.h"
using namespace std;

class Organism;

const int GRID_WIDTH = GRIDSIZE;
const int GRID_HEIGHT = GRIDSIZE;

class City
{
protected:
	Organism* grid[GRID_HEIGHT][GRID_WIDTH];

public:
	City();
	virtual ~City();

	Organism* getOrganism(int x, int y);
	void setOrganism(Organism* organism, int x, int y);

	friend ostream& operator<<(ostream& output, City& city);

};

#endif

