//
// Created by Roi on 05/01/2019.
//

#ifndef ASSIGNMENT_5_NECROMANCER_H
#define ASSIGNMENT_5_NECROMANCER_H

#include "Hero.h"

class Necromancer: public Hero{
public:
	Necromancer();
	~Necromancer();
	void specialSkill(Hero** heroes, int length);
};


#endif //ASSIGNMENT_5_NECROMANCER_H
