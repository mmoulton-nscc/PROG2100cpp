#include "Zombie.h"
#include "City.h"
#include "Human.h"
#include <chrono>
#include <algorithm>
#include <random>

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
	cit->setOrganism(this, x, y);

}

Zombie::~Zombie()
{
}

void Zombie::move()
{
	//check adjacent spots for human or open cells
	vector<int> openspots;
	vector<int> foodspots;

	//food
	if (y + 1 < height && city->getOrganism(x, y + 1) != NULL && city->getOrganism(x, y + 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(NORTH);
	}
	if (y - 1 >= 0 && city->getOrganism(x, y - 1) != NULL && city->getOrganism(x, y - 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(SOUTH);
	}
	if (x + 1 < width && city->getOrganism(x + 1, y) != NULL && city->getOrganism(x + 1, y)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(EAST);
	}
	if (x - 1 >= 0 && city->getOrganism(x - 1, y) != NULL && city->getOrganism(x - 1, y)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(WEST);
	}
	if (y + 1 < height && x + 1 < width && city->getOrganism(x + 1, y + 1) != NULL && city->getOrganism(x + 1, y + 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(NORTHEAST);
	}
	if (y + 1 < height && x - 1 <= 0 && city->getOrganism(x - 1, y + 1) != NULL && city->getOrganism(x - 1, y + 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(NORTHWEST);
	}
	if (y - 1 >= 0 && x + 1 < width && city->getOrganism(x + 1, y - 1) != NULL && city->getOrganism(x + 1 , y - 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(SOUTHEAST);
	}
	if (y - 1 >= 0 && x - 1 >= 0 && city->getOrganism(x - 1, y - 1) != NULL && city->getOrganism(x - 1, y - 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(SOUTHWEST);
	}

	//movement
	if (y + 1 < height && city->getOrganism(x, y + 1) == NULL)
	{
		openspots.push_back(NORTH);
	}
	if (y - 1 >= 0 && city->getOrganism(x, y - 1) == NULL)
	{
		openspots.push_back(SOUTH);
	}
	if (x + 1 < width && city->getOrganism(x + 1, y) == NULL)
	{
		openspots.push_back(EAST);
	}
	if (x - 1 >= 0 && city->getOrganism(x - 1, y) == NULL)
	{
		openspots.push_back(WEST);
	}
	if (y + 1 < height && x + 1 < width && city->getOrganism(x + 1, y + 1) == NULL)
	{
		openspots.push_back(NORTHEAST);
	}
	if (y + 1 < height && x - 1 <= 0 && city->getOrganism(x - 1, y + 1) == NULL)
	{
		openspots.push_back(NORTHWEST);
	}
	if (y - 1 >= 0 && x + 1 < width && city->getOrganism(x + 1, y - 1) == NULL)
	{
		openspots.push_back(SOUTHEAST);
	}
	if (y - 1 >= 0 && x - 1 >= 0 && city->getOrganism(x - 1, y - 1) == NULL)
	{
		openspots.push_back(SOUTHWEST);
	}

	//if there are humans around
	if (!foodspots.empty())
	{
		//shuffle
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(foodspots.begin(), foodspots.end(), default_random_engine(seed));

		//set new position to organism
		switch (foodspots[0])
		{
		case NORTH:
			city->setOrganism(NULL, x, y + 1);
			break;
		case SOUTH:
			city->setOrganism(NULL, x, y - 1);
			break;
		case EAST:
			city->setOrganism(NULL, x + 1, y);
			break;
		case WEST:
			city->setOrganism(NULL, x - 1, y);
			break;
		case NORTHEAST:
			city->setOrganism(NULL, x + 1, y + 1);
			break;
		case NORTHWEST:
			city->setOrganism(NULL, x - 1, y + 1);
			break;
		case SOUTHEAST:
			city->setOrganism(NULL, x + 1, y - 1);
			break;
		case SOUTHWEST:
			city->setOrganism(NULL, x - 1, y - 1);
			break;
		}

		//hunger sated
		starveCounter = 0;
	}

	//no food? try to move instead
	else if (!openspots.empty())
	{
		//shuffle
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(openspots.begin(), openspots.end(), default_random_engine(seed));

		//set old cell to empty
		city->setOrganism(NULL, x, y);

		//set new position to organism
		switch (openspots[0])
		{
		case NORTH:
			this->setPosition(x, y + 1);
			break;
		case SOUTH:
			this->setPosition(x, y - 1);
			break;
		case EAST:
			this->setPosition(x + 1, y);
			break;
		case WEST:
			this->setPosition(x - 1, y);
			break;
		case NORTHEAST:
			this->setPosition(x + 1, y + 1);
			break;
		case NORTHWEST:
			this->setPosition(x - 1, y + 1);
			break;
		case SOUTHEAST:
			this->setPosition(x + 1, y - 1);
			break;
		case SOUTHWEST:
			this->setPosition(x - 1, y - 1);
			break;
		}

		//reflect organism's new position in city grid
		city->setOrganism(this, x, y);
	}

}

void Zombie::spawn()
{
	vector<int> foodspots;

	//search for humans to convert
	if (y + 1 < height && city->getOrganism(x, y + 1) != NULL && city->getOrganism(x, y + 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(NORTH);
	}
	if (y - 1 >= 0 && city->getOrganism(x, y - 1) != NULL && city->getOrganism(x, y - 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(SOUTH);
	}
	if (x + 1 < width && city->getOrganism(x + 1, y) != NULL && city->getOrganism(x + 1, y)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(EAST);
	}
	if (x - 1 >= 0 && city->getOrganism(x - 1, y) != NULL && city->getOrganism(x - 1, y)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(WEST);
	}
	if (y + 1 < height && x + 1 < width && city->getOrganism(x + 1, y + 1) != NULL && city->getOrganism(x + 1, y + 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(NORTHEAST);
	}
	if (y + 1 < height && x - 1 <= 0 && city->getOrganism(x - 1, y + 1) != NULL && city->getOrganism(x - 1, y + 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(NORTHWEST);
	}
	if (y - 1 >= 0 && x + 1 < width && city->getOrganism(x + 1, y - 1) != NULL && city->getOrganism(x + 1, y - 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(SOUTHEAST);
	}
	if (y - 1 >= 0 && x - 1 >= 0 && city->getOrganism(x - 1, y - 1) != NULL && city->getOrganism(x - 1, y - 1)->getSpecies() == HUMAN_CH)
	{
		foodspots.push_back(SOUTHWEST);
	}

	//if there are humans around
	if (!foodspots.empty())
	{
		//shuffle
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(foodspots.begin(), foodspots.end(), default_random_engine(seed));

		Zombie* zomb;

		//nullify human and spawn zombie in its place
		switch (foodspots[0])
		{
		case NORTH:
			city->setOrganism(NULL, x, y + 1);
			new Zombie(city, x, y + 1);
			break;
		case SOUTH:
			city->setOrganism(NULL, x, y - 1);
			new Zombie(city, x, y - 1);
			break;
		case EAST:
			city->setOrganism(NULL, x + 1, y);
			new Zombie(city, x + 1, y);
			break;
		case WEST:
			city->setOrganism(NULL, x - 1, y);
			new Zombie(city, x - 1, y);
			break;
		case NORTHEAST:
			city->setOrganism(NULL, x + 1, y + 1);
			new Zombie(city, x + 1, y + 1);
			break;
		case NORTHWEST:
			city->setOrganism(NULL, x - 1, y + 1);
			new Zombie(city, x - 1, y + 1);
			break;
		case SOUTHEAST:
			city->setOrganism(NULL, x + 1, y - 1);
			new Zombie(city, x + 1, y - 1);
			break;
		case SOUTHWEST:
			city->setOrganism(NULL, x - 1, y - 1);
			new Zombie(city, x - 1, y - 1);
			break;
		}

		//bred
		breedCounter = 0;
	}
}

void Zombie::turn()
{
	move();
	if (breedCounter >= ZOMBIE_BREED)
	{
		spawn();
	}
	if (starveCounter >= ZOMBIE_STARVE)
	{
		starve();
	}
	hasGone = true;
	breedCounter += 1;
	starveCounter += 1;
}

char Zombie::getSpecies()
{
	return ZOMBIE_CH;
}

void Zombie::starve()
{
	//nullify zombie and replace with humans
	city->setOrganism(NULL, x, y);
	new Human(city, x, y);

}
