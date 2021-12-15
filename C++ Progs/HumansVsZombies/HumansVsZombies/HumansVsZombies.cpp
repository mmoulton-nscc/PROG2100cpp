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

        if (city->getOrganism(y, x) == NULL)
        {
            Human* hume = new Human(city, x, y);
        }
    }

    //instantiate zombies into city
    while (city->countZombies() < ZOMBIE_STARTCOUNT)
    {
        int y = rand() % GRID_HEIGHT;
        int x = rand() % GRID_WIDTH;

        if (city->getOrganism(y, x) == NULL)
        {
            Zombie* zomb = new Zombie(city, x, y);
        }
    }

    while (city->keepRunning())
    {
        ClearScreen();
        cout << *city;
        cout << "               GENERATION " << loopcount;

        loopcount += 1;
        this_thread::sleep_for(interval);
    }

    //while (city->keepRunning()) { //while both humans and zombies exist
    //    this_thread::sleep_for(interval);
    //    ClearScreen();
    //    city->humansMove();
    //    city->zombiesMoveEat();
    //    city->humansRecruit();
    //    city->zombiesRecruit();
    //    city->zombiesStarve();
    //    city->countOrganisms(Z or H goes here);

    //    city->reset(); //resets moved flags
}//end main

