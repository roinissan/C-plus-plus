//
// Created by Roi on 03/01/2019.
//

#ifndef ASSIGNMENT_5_CREATURE_H
#define ASSIGNMENT_5_CREATURE_H

using namespace std;
#include <string>
#include <iostream>

class Creature{
public:
	// Constructors and Destructors
	Creature();
	Creature (const Creature &creature);
	virtual ~Creature();

	// Class methods
	virtual void attack(Creature *creature);
	virtual int defence(Creature *creature);

	// Setters and Getters
	void setAmount(int new_amount);
	void printCreature();
	int getPrice();
	std::string getName();
	int getAmount();

protected:
	// Fields
	std::string name;
	int attackPower;
	int defencePower;
	int price;
	int amount;

};

#endif //ASSIGNMENT_5_CREATURE_H
