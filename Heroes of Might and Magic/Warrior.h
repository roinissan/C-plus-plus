//
// Created by Roi on 05/01/2019.
//

#ifndef ASSIGNMENT_5_WARRIOR_H
#define ASSIGNMENT_5_WARRIOR_H

#include "Hero.h"

class Warrior:public Hero{
public:
	Warrior();
	~Warrior();
	void specialSkill(Hero** heroes, int length);
};



#endif //ASSIGNMENT_5_WARRIOR_H
