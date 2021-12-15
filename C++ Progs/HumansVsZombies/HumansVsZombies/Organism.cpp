#include "Organism.h"
#include "GameSpecs.h"
using namespace std;

Organism::Organism()
{
	x = 0;
	y = 0;
	width = GRID_WIDTH;
	height = GRID_HEIGHT;
	city = NULL;
}

Organism::Organism(City* city, int posx, int posy)
{
	x = posx;
	y = posy;
	width = GRID_WIDTH;
	height = GRID_HEIGHT;
	city = city;
}

Organism::~Organism()
{
}

void Organism::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}