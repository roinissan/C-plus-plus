//
// Created by Roi on 03/01/2019.
//

#ifndef ASSIGNMENT_5_ARCHER_H
#define ASSIGNMENT_5_ARCHER_H

#include "Creature.h"

class Archer : public Creature{

public:
	Archer();
	~Archer(){};
	void attack(Creature *creature);
};

#endif //ASSIGNMENT_5_ARCHER_H
