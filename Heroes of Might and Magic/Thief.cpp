//
// Created by Roi on 05/01/2019.
//

#include "Thief.h"

Thief::Thief(){
	this->heroType = "Thief";
}

Thief::~Thief(){}

void Thief::specialSkill(Hero** heroes, int length){
	string name;
	Hero* warrior;
	bool check = false;
	cout<<"Please insert hero name:\n";
	cin>>name;
	for(int i = 0; i<length;i++){
		string ch = heroes[i]->getName();
		if(heroes[i]!=NULL){
			if(heroes[i]->getName()==name && heroes[i]->getIsDead()==false){
				warrior = heroes[i];
				check=true;
				break;
			}
		}
	}
	if(check==false)
		throw Exception();
	this->usedAbillity = true;
	if(warrior->getGold() >= 70){
		if(goldAmount <=2430){
			goldAmount = goldAmount +70;
			warrior->setGold(warrior->getGold() -70);
		}
		else{
			warrior->setGold(warrior->getGold() - (2500-goldAmount));
			goldAmount = 2500;
		}
	}
	else{
		if(goldAmount + warrior->getGold() <=2500 ){
			goldAmount = goldAmount + warrior->getGold();
			warrior->setGold(0);
		}
		else{
			warrior->setGold(0);
			goldAmount = 2500;
		}
	}
}
