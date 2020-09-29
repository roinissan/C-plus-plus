//
// Created by Roi on 03/01/2019.
//

#ifndef ASSIGNMENT_5_BLACKDRAGON_H
#define ASSIGNMENT_5_BLACKDRAGON_H

#include "Creature.h"
class BlackDragon:public Creature{
public:
	BlackDragon();
	~BlackDragon(){};
	void attack(Creature *creature);
};



#endif //ASSIGNMENT_5_BLACKDRAGON_H
