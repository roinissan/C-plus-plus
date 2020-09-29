//
// Created by Roi on 05/01/2019.
//

#ifndef ASSIGNMENT_5_HERO_H
#define ASSIGNMENT_5_HERO_H

#include <iostream>
#include <string.h>
using namespace std;
#include "Exception.h"
#include "BlackDragon.h"
#include "Archer.h"
#include "Vampire.h"
#include "Zombie.h"
#include "Wizard.h"



//[0]->Zombies , [1]->Archers , [2]->Vampires  , [3]->Wizards , [4]->Black Dragons
class Hero{
// Fields
protected:
	string heroName;
	string heroType;
	double goldAmount;
	bool tookGold;
	bool usedAbillity;
	bool isDead;
	int numOfCreatures;
	Creature** creatureArr;


public:
	// Constructor and Destructor
	Hero();
	virtual ~Hero();

	// Class Methods
	virtual void specialSkill(Hero** heroes, int length){};
	virtual void purchaseCreatures();
	virtual void addGold();
	bool checkName(string name);
	void printAttackInfo();
	void showDetails();
	void print();
	void attack(Hero *oppHero, int attacker, int defender);
	virtual int endTurn(Hero** heroes, int currHero, int heroesAmount);

	// Getters
	virtual double getGold();
	virtual string getName();
	Creature** getCreaturesArr(){return creatureArr;};
	bool getTookGold();
	bool getUsedAbillity();
	string getType();
	bool getIsDead();
	int getNumOfCreatures();

	// Setters
	bool setName(string name);
	void setNumberOfCreature(int number_of_creatures);
	void setGold(double new_gold_amount);
	void setIsDead(bool state);
	void setTookGold(bool took_gold);
	void setUsedAbillity(bool use_ability);







};




#endif //ASSIGNMENT_5_HERO_H
