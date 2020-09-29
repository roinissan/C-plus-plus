//
// Created by Roi on 03/01/2019.
//

#include "Vampire.h"

Vampire::Vampire(){
	this->attackPower = 4;
	this->defencePower = 4;
	this->price = 80;
	this->name = "Vampire";
	amount = 0;
};



void Vampire::attack(Creature *creature){
	int attack = attackPower;
	attack = attack * amount;
	int defence = creature->defence(creature);

	int killed_amount = 0;
	for(;defence <= attack; attack = attack-defence)
		killed_amount++;

	if (creature->getAmount()- killed_amount < 0)
		creature->setAmount(0);
	else
		creature->setAmount(creature->getAmount()- killed_amount);
};
