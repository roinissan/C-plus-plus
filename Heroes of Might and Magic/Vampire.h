//
// Created by Roi on 03/01/2019.
//

#ifndef ASSIGNMENT_5_VAMPIRE_H
#define ASSIGNMENT_5_VAMPIRE_H

#include "Creature.h"

class Vampire:public Creature {
public:
	Vampire();
	~Vampire() {};
	void attack(Creature *creature);
};
#endif //ASSIGNMENT_5_VAMPIRE_H
