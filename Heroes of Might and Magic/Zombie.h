//
// Created by Roi on 03/01/2019.
//

#ifndef ASSIGNMENT_5_ZOMBIE_H
#define ASSIGNMENT_5_ZOMBIE_H

#include "Creature.h"


class Zombie:public Creature{
public:
	Zombie();
	~Zombie(){};
	void attack(Creature *creature);

};


#endif //ASSIGNMENT_5_ZOMBIE_H
