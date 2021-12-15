#include "Human.h"
#include "City.h"
#include <chrono>
#include <algorithm>
#include <random>

Human::Human() : Organism()
{
}

Human::Human(City* cit, int posx, int posy)
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

Human::~Human()
{
}

void Human::move()
{
	//check adjacent spots for open cells
	vector<int> openspots;
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

	//if there are open spots
	if (!openspots.empty())
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
		}

		//reflect organism's new position in city grid
		city->setOrganism(this, x, y);
	}

}

void Human::spawn()
{
	//check adjust spots for open cells
	vector<int> openspots;
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

	//if there are open spots
	if (!openspots.empty())
	{
		//shuffle
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(openspots.begin(), openspots.end(), default_random_engine(seed));

		Human* hume;

		//create new organism in open cell
		switch (openspots[0])
		{
		case NORTH:
			new Human(city, x, y + 1);
			break;
		case SOUTH:
			new Human(city, x, y - 1);
			break;
		case EAST:
			new Human(city, x + 1, y);
			break;
		case WEST:
			new Human(city, x - 1, y);
			break;
		}

		//reset breed counter
		breedCounter = 0;
	}
}

void Human::turn()
{
	move();
	if (breedCounter >= HUMAN_BREED)
	{
		spawn();
	}
	hasGone = true;
	breedCounter += 1;

}

char Human::getSpecies()
{
	return HUMAN_CH;
}


