#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"

class Zombie : public Organism
{
public:
	Zombie();
	Zombie(City* city, int posx, int posy);
	virtual ~Zombie();

	void move();
};

#endif
