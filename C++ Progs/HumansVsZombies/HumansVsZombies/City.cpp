#include "City.h"
#include "Organism.h"
#include <windows.h>
#include <conio.h>
using namespace std;

//Constructor
City::City()
{
	for (int y = 0; y < GRID_HEIGHT; y++) 
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			grid[x][y] = NULL; 
		}
	}
}
//Deconstructor
City::~City()
{
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (this->grid[x][y] != NULL)
			{
				delete(grid[x][y]);
			};
		}
	}
}

Organism* City::getOrganism(int x, int y)
{
	if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
	{
		return this->grid[x][y];
	}
	else
	{
		return NULL;
	}

}

void City::setOrganism(Organism* organism, int x, int y)
{
	if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
	{
		this->grid[x][y] = organism;
	}
}

bool City::keepRunning()
{
	if (countHumans() == 0 && countZombies() == 0)
	{
		return false;
	}
	
	return true;
}

int City::countHumans()
{
	this->humans = 0;
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (this->getOrganism(x, y) != nullptr)
			{
				if (this->getOrganism(x, y)->getSpecies() == HUMAN_CH)
				{
					this->humans += 1;
				}
			}
		}
	}

	return this->humans;
}

int City::countZombies()
{
	this->zombies = 0;
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (this->getOrganism(x, y) != nullptr)
			{
				if (this->getOrganism(x, y)->getSpecies() == ZOMBIE_CH)
				{
					this->zombies += 1;
				}
			}
		}
	}

	return this->zombies;
}

void City::turn()
{
	bool allGone = false;

	while (!allGone)
	{
		allGone = true;
		for (int y = 0; y < GRID_HEIGHT; y++)
		{
			for (int x = 0; x < GRID_WIDTH; x++)
			{
				if (this->getOrganism(x, y) != nullptr)
				{
					if (!this->getOrganism(x, y)->getHasGone())
					{
						this->getOrganism(x, y)->turn();
						allGone = false;
					}
				}
			}
		}
	}
	
}

void City::reset()
{
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (this->getOrganism(x, y) != nullptr)
			{
				this->getOrganism(x, y)->flipHasGone();
			}
		}
	}
}


void City::color(int color)
{
	HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);
	return;
}

ostream& operator<<(ostream& os, City& city)
{
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (city.getOrganism(x, y) == nullptr)
			{
				city.color(BASIC_COLOR);
				os << SPACE_CH;
			}
			else
			{
				char c = city.getOrganism(x, y)->getSpecies();
				if (c == HUMAN_CH)
				{
					city.color(HUMAN_COLOR);
				}
				else
				{
					city.color(ZOMBIE_COLOR);
				}
				os << c;
			}
			city.color(BASIC_COLOR);
		}
		os << endl;
	}
	city.color(HUMAN_COLOR);
	os << "HUMANS REMAINING: " << city.countHumans();

	city.color(ZOMBIE_COLOR);
	os << "   ZOMBIES REMAINING: "<< city.countZombies();

	city.color(BASIC_COLOR);


	return os << endl;
}