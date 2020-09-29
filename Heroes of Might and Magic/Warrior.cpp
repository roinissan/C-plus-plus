//
// Created by Roi on 05/01/2019.
//

#include "Warrior.h"

Warrior::Warrior(){
	this->heroType = "Warrior";
}

Warrior::~Warrior(){}

void Warrior::specialSkill(Hero** heroes, int length){
	this->usedAbillity = true;
	if (this->goldAmount <= 2450){
		this->goldAmount = this->goldAmount + 50;
		cout<<"Gold added successfully\n";
	}
}