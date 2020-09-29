//
// Created by Roi on 03/01/2019.
//

#include "BlackDragon.h"

BlackDragon::BlackDragon(){
	this->attackPower = 9;
	this->defencePower = 10;
	this->price = 200;
	this->name = "Black_Dragon";
	amount = 0;
};


void BlackDragon::attack(Creature *creature){
	int attack = attackPower;
	attack = attack * amount;
	int defence = creature->defence(this);

	int killed_amount = 0;
	for(;defence <= attack; attack = attack-defence)
		killed_amount++;

	if (creature->getAmount()- killed_amount < 0)
		creature->setAmount(0);
	else
		creature->setAmount(creature->getAmount()- killed_amount);
};
