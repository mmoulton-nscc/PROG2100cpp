#include "Organism.h"
#include "GameSpecs.h"
using namespace std;

Organism::Organism()
{
	x = 0;
	y = 0;
	breedCounter = 0;
	starveCounter = 0;
	hasGone = false;
	width = GRIDSIZE;
	height = GRIDSIZE;
	city = NULL;
}

Organism::Organism(City* cit, int posx, int posy)
{
	x = posx;
	y = posy;
	breedCounter = 0;
	starveCounter = 0;
	hasGone = false;
	width = GRIDSIZE;
	height = GRIDSIZE;
	city = cit;
	cit->setOrganism(y, x, this);
}

Organism::~Organism()
{
}

void Organism::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Organism::getHasGone()
{
	return this->hasGone;
}
