//
// Created by Roi on 03/01/2019.
//

#include "Wizard.h"

Wizard::Wizard(){
	this->attackPower = 8;
	this->defencePower = 2;
	this->price = 150;
	this->name = "Wizard";
	amount = 0;
};


void Wizard::attack(Creature *creature){
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

int Wizard::defence(Creature *creature){
	if ((creature->getName())=="Black_Dragon")
		return defencePower*2;
	return defencePower;
};
