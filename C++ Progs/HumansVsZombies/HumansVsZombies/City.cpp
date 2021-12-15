#include "City.h"

using namespace std;

//Constructor
City::City()
{
	for (int y = 0; y < GRID_HEIGHT; y++) 
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			grid[y][x] = NULL; 
			// When I work with 2d arrays they always end up backwards
			// So I started to do y,x instead of x,y and it works out haha 
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
			if (this->grid[y][x] != NULL)
			{
				delete(grid[y][x]);
			};
		}
	}
}


Organism* City::getOrganism(int x, int y)
{
	if (x > 0 && x <= GRID_WIDTH && y > 0 && y <= GRID_HEIGHT)
	{
		return this->grid[y][x];
	}
	else
	{
		return NULL;
	}

}

void City::setOrganism(Organism* organism, int x, int y)
{
	if (x > 0 && x <= GRID_WIDTH && y > 0 && y <= GRID_HEIGHT)
	{
		this->grid[y][x] = organism;
	}
}

void City::move(Organism* organism, int x, int y)
{
	
}


ostream& operator<<(ostream& os, City& city)
{
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (city.getOrganism(y, x) == nullptr)
			{
				os << ".";
			}
			else
			{
				os << city.getOrganism(y, x).getSpecies();
			}
		}
		os << endl;
	}

	return os << endl;
}