//
// Created by Roi on 05/01/2019.
//

#include "Necromancer.h"
Necromancer::Necromancer(){
	this->heroType = "Necromancer";
};

Necromancer::~Necromancer(){};

void Necromancer::specialSkill(Hero** heroes, int length){
	this->usedAbillity = true;
	this->creatureArr[0]->setAmount(this->creatureArr[0]->getAmount()+1);
	this->numOfCreatures++;
	cout<<"Zombie added successfully\n";
};
