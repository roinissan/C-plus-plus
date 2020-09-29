//
// Created by Roi on 03/01/2019.
//

#include "Zombie.h"


Zombie::Zombie(){
	this->attackPower = 2;
	this->defencePower = 5;
	this->price = 50;
	this->name = "Zombie";
	amount = 0;
};



void Zombie::attack(Creature *creature){
	int attack;
	if((creature->getName())== "Archer")
		attack =  2*attackPower;
	else
		attack = attackPower;
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
