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
			// So I started to do y,x instead of x,y..
			// it must be the order i do my for loops in
			// oh well
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


ostream& operator<<(ostream& os, City& city)
{
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (city.getOrganism(y, x) == nullptr)
			{
				os << SPACE_CH;
			}
			else
			{
				//os << city.getOrganism(y, x).getSpecies();
			}
		}
		os << endl;
	}

	return os << endl;
}