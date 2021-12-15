//
// Humans vs Zombies - Mark Moulton - W0440932

#include <iostream>
#include <chrono>
#include <thread>

#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
#include "City.h"
#include "GameSpecs.h"

using namespace std;

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}



int main()
{
    City* city = new City();
    chrono::milliseconds interval(PAUSE_MILLISECONDS);
    int loopcount = 0;


    //instantiate humans into city
    while (city->countHumans() < HUMAN_STARTCOUNT)
    {
        int y = rand() % GRID_HEIGHT;
        int x = rand() % GRID_WIDTH;

        if (city->getOrganism(x, y) == NULL)
        {
            Human* hume = new Human(city, x, y);
        }
    }

    //instantiate zombies into city
    while (city->countZombies() < ZOMBIE_STARTCOUNT)
    {
        int y = rand() % GRID_HEIGHT;
        int x = rand() % GRID_WIDTH;

        if (city->getOrganism(x, y) == NULL)
        {
            Zombie* zomb = new Zombie(city, x, y);
        }
    }

    //run until extinction event
    while (city->keepRunning())
    {
        city->reset();
        ClearScreen();
        city->turn();

        cout << *city;
        cout << "               GENERATION " << loopcount;

        loopcount += 1;
        this_thread::sleep_for(interval);
    }

}

