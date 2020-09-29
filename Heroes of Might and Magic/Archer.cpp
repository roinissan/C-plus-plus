//
// Created by Roi on 03/01/2019.
//

#include "Archer.h"
Archer::Archer(){
	attackPower = 5;
	defencePower = 4;
	price = 90;
	name = "Archer";
	amount = 0;
};


void Archer::attack(Creature *creature){
	int attack;
	if((creature->getName())=="Black_Dragon")
		attack =  attackPower + (attackPower*0.2);
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

