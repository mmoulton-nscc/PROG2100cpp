#include "Human.h"

Human::Human() : Organism()
{
}

Human::Human(City* cit, int posx, int posy) : Organism(cit, x, y)
{
}

Human::~Human()
{
}

void Human::move()
{

}

void Human::spawn()
{

}

void Human::turn()
{

}

char Human::getSpecies()
{
	return HUMAN_CH;
}


