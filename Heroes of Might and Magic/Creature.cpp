//
// Created by Roi on 03/01/2019.
//

#include "Creature.h"

Creature::Creature(){
	attackPower = 0;
	defencePower = 0;
	price = 0;
	name = "None";
	amount = 0;
};

Creature::Creature(const Creature &creature) {
	attackPower = creature.attackPower;
	defencePower = creature.defencePower;
	price = creature.price;
	amount = creature.amount;
	name = creature.name;
}

Creature::~Creature(){};

void Creature::attack(Creature *creature){};

int Creature::defence(Creature *creature){return defencePower;};

std::string Creature::getName(){return name;};

int Creature::getPrice(){return price;};

int Creature::getAmount(){return amount;};

void Creature::printCreature(){
	cout << "Attack level: "<< attackPower << ", Defense level: "<< defencePower<< endl;
};
void Creature::setAmount(int new_amount){
	amount = new_amount;
};

