#include "Zombie.h"
#include "City.h"

Zombie::Zombie() : Organism()
{
}

Zombie::Zombie(City* cit, int posx, int posy)
{
	x = posx;
	y = posy;
	breedCounter = 0;
	starveCounter = 0;
	hasGone = false;
	width = GRIDSIZE;
	height = GRIDSIZE;
	city = cit;
	cit->setOrganism(this, y, x);

}

Zombie::~Zombie()
{
}

void Zombie::move()
{
}

void Zombie::spawn()
{
}

void Zombie::turn()
{
}

char Zombie::getSpecies()
{
	return ZOMBIE_CH;
}
