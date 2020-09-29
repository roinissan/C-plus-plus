//
// Created by Roi on 03/01/2019.
//

#ifndef ASSIGNMENT_5_WIZARD_H
#define ASSIGNMENT_5_WIZARD_H

#include "Creature.h"

class Wizard:public Creature{
public:
	Wizard();
	~Wizard(){};
	void attack(Creature *creature);
	int defence(Creature *creature);
};

#endif //ASSIGNMENT_5_WIZARD_H
