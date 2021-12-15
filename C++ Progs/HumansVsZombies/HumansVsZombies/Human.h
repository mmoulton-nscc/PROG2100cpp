#ifndef _Human_H
#define _Human_H

#include "Organism.h"

class Human : public Organism
{
public:
	Human();
	Human(City* city, int posx, int posy);
	virtual ~Human();

	void move();
};

#endif
