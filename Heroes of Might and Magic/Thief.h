//
// Created by Roi on 05/01/2019.
//

#ifndef ASSIGNMENT_5_THIEF_H
#define ASSIGNMENT_5_THIEF_H
#include "Hero.h"

class Thief :public Hero{
public:
	Thief();
	~Thief();
	void specialSkill(Hero** heroes, int length);
};



#endif //ASSIGNMENT_5_THIEF_H
