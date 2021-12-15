#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"

class Zombie : public Organism
{
public:
	Zombie();
	Zombie(City* city, int posx, int posy);
	virtual ~Zombie();

	//parent's virtual methods
	void move();
	void spawn();
	void turn();
	char getSpecies();

};

#endif
