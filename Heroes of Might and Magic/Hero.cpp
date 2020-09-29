//
// Created by Roi on 05/01/2019.
//

#include "Hero.h"
#include <string.h>
#include <string>
Hero::Hero(){
	//need to set all creatures amount to 0 in the data structure
	heroName = "roei";
	heroType = "Warrior";
	goldAmount = 750;
	creatureArr = new Creature*[5];
	Creature* newZ = new Zombie();
	creatureArr[0] = newZ;
	Creature* newA = new Archer();
	creatureArr[1] = newA;
	Creature* newV = new Vampire();
	creatureArr[2] = newV;
	Creature* newW = new Wizard();
	creatureArr[3] = newW;
	Creature* newBD = new BlackDragon();
	creatureArr[4] = newBD;
	tookGold = false;
	usedAbillity = false;
	isDead = false;
	numOfCreatures = 0;
}

Hero::~Hero() {
	for(int creature = 0; creature < 5; creature++)
		if(creatureArr[creature] != NULL)
			delete creatureArr[creature];
	delete [] creatureArr;
}

double Hero::getGold(){
	return goldAmount;
}

string Hero::getName(){
	return heroName;
}

string Hero::getType() {
	return heroType;
}

bool Hero::getIsDead() {
	return isDead;
}

bool Hero::getTookGold(){
	return tookGold;
}

bool Hero::getUsedAbillity(){
	return usedAbillity;
}

int Hero::getNumOfCreatures(){
	return numOfCreatures;
}


void Hero::setGold(double new_gold_amount) {
	goldAmount = new_gold_amount;
}

void Hero::setTookGold(bool took_gold) {
	tookGold = took_gold;
}

void Hero::setUsedAbillity(bool use_ability){
	usedAbillity = use_ability;
}

void Hero::setNumberOfCreature(int number_of_creatures){
	numOfCreatures = number_of_creatures;
}

bool Hero::setName(string name){
	if(name.empty()){
		throw Exception();
	}
	if(checkName(name)==true){
		heroName = name;
		return true;
	}
	throw Exception();
}

void Hero::setIsDead(bool state) {
	isDead = state;
}

// Hero Attribute - get gold every turn
void Hero::addGold(){
	if(goldAmount<2400){
		goldAmount = goldAmount +100;
	}
	else{
		goldAmount = 2500;
	}
	tookGold = true;
}

// Checks that the name of the Hero is in the right format
bool Hero::checkName(string name){
	if(name.length()>31)
		return false;

	for(unsigned int i = 0; i <(name.length());i++){
		if(!isupper(name.at(i)) && !islower(name.at(i)) && !isdigit(name.at(i)))
			return false;
	}
	return true;
}

//print methods - each for different use
void Hero::print(){
	cout << heroName << " " << heroType;
}

void Hero::printAttackInfo(){

	cout << heroName << " " << heroType << ":\n";
	for (int creature = 4; creature > -1; creature--){
		if(creatureArr[creature]->getAmount()>0)
			cout << creatureArr[creature]->getAmount() << " " << creatureArr[creature]->getName() << " ";
	}
	cout << endl;
}

void Hero::showDetails(){
	int count = 0;
	int check = 0;
	cout<<heroName<<" "<<heroType<<"\n";
	cout<<goldAmount<<" gold\n";
	for(int i = 0; i<5;i++){
		if(creatureArr[i]->getAmount()>0)
			count++;
	}
	if(count==1){
		if(creatureArr[4]->getAmount()>0)
			cout<<creatureArr[4]->getAmount()<<" Black_Dragon.\n";
		if(creatureArr[3]->getAmount()>0)
			cout<<creatureArr[3]->getAmount()<<" Wizard.\n";
		if(creatureArr[2]->getAmount()>0)
			cout<<creatureArr[2]->getAmount()<<" Vampire.\n";
		if(creatureArr[1]->getAmount()>0)
			cout<<creatureArr[1]->getAmount()<<" Archer.\n";
		if(creatureArr[0]->getAmount()>0)
			cout<<creatureArr[0]->getAmount()<<" Zombie.\n";
	}
	if(count==2){
		if(creatureArr[4]->getAmount()>0){
			cout<<creatureArr[4]->getAmount()<<" Black_Dragon ";
			check++;
		}
		if(creatureArr[3]->getAmount()>0){
			if(check==1){
				cout<<creatureArr[3]->getAmount()<<" Wizard.\n";
			}
			else{
				cout<<creatureArr[3]->getAmount()<<" Wizard ";
				check++;
			}
		}
		if(creatureArr[2]->getAmount()>0){
			if(check==1){
				cout<<creatureArr[2]->getAmount()<<" Vampire.\n";
			}
			else{
				cout<<creatureArr[2]->getAmount()<<" Vampire ";
				check++;
			}
		}
		if(creatureArr[1]->getAmount()>0){
			if(check==1){
				cout<<creatureArr[1]->getAmount()<<" Archer.\n";
			}
			else{
				cout<<creatureArr[1]->getAmount()<<" Archer ";
				check++;
			}
		}
		if(creatureArr[0]->getAmount()>0)
			cout<<creatureArr[0]->getAmount()<<" Zombie.\n";
	}
	if(count==3){
		if(creatureArr[4]->getAmount()>0){
			cout<<creatureArr[4]->getAmount()<<" Black_Dragon ";
			check++;
		}
		if(creatureArr[3]->getAmount()>0){
			cout<<creatureArr[3]->getAmount()<<" Wizard ";
			check++;
		}
		if(creatureArr[2]->getAmount()>0){
			if(check==2){
				cout<<creatureArr[2]->getAmount()<<" Vampire.\n";
			}
			else{
				cout<<creatureArr[2]->getAmount()<<" Vampire ";
				check++;
			}
		}
		if(creatureArr[1]->getAmount()>0){
			if(check==2)
				cout<<creatureArr[1]->getAmount()<<" Archer.\n";
			else{
				cout<<creatureArr[1]->getAmount()<<" Archer ";
				check++;
			}
		}
		if(creatureArr[0]->getAmount()>0)
			cout<<creatureArr[0]->getAmount()<<" Zombie.\n";
	}
	if(count==4){
		if(creatureArr[4]->getAmount()>0){
			cout<<creatureArr[4]->getAmount()<<" Black_Dragon ";
			check++;
		}
		if(creatureArr[3]->getAmount()>0){
			cout<<creatureArr[3]->getAmount()<<" Wizard ";
			check++;
		}
		if(creatureArr[2]->getAmount()>0){
			cout<<creatureArr[2]->getAmount()<<" Vampire ";
			check++;
		}
		if(creatureArr[1]->getAmount()>0){
			if(check==3){
				cout<<creatureArr[1]->getAmount()<<" Archer.\n";
			}
			else{
				cout<<creatureArr[1]->getAmount()<<" Archer ";
			}
		}
		if(creatureArr[0]->getAmount()>0)
			cout<<creatureArr[0]->getAmount()<<" Zombie.\n";
	}
	if(count==5){
		if(creatureArr[4]->getAmount()>0)
			cout<<creatureArr[4]->getAmount()<<" Black_Dragon ";
		if(creatureArr[3]->getAmount()>0)
			cout<<creatureArr[3]->getAmount()<<" Wizard ";
		if(creatureArr[2]->getAmount()>0)
			cout<<creatureArr[2]->getAmount()<<" Vampire ";
		if(creatureArr[1]->getAmount()>0)
			cout<<creatureArr[1]->getAmount()<<" Archer ";
		if(creatureArr[0]->getAmount()>0)
			cout<<creatureArr[0]->getAmount()<<" Zombie.\n";
	}

}



// Hero buy creature attribute
void Hero::purchaseCreatures(){
	int input=0,amount=0,amount_copy;

	cout << "1. Buy Zombies.\n"<<"2. Buy Archers.\n"<<"3. Buy Vampire.\n"<<"4. Buy Wizard.\n"<<"5. Buy Black Dragon\n";
	cin >> input;
	switch(input){
		case 1:
			cout << "Attack level:2, Defense level:5\n";
			cin >> amount;
			amount_copy = amount;
			if(goldAmount < amount*50){
				throw Exception();
			}
			while(amount>0){
				creatureArr[0]->setAmount(creatureArr[0]->getAmount() +1);
				numOfCreatures++;
				amount--;
			}
			goldAmount = goldAmount - (amount_copy*50);
			break;

		case 2:
			cout << "Attack level:5, Defense level:4\n";
			cin >> amount;
			amount_copy = amount;
			if(goldAmount < amount*90){
				throw Exception();
			}
			while(amount>0){
				creatureArr[1]->setAmount(creatureArr[1]->getAmount() +1);
				numOfCreatures++;
				amount--;
			}
			goldAmount = goldAmount - (amount_copy*90);
			break;
		case 3:
			cout<<"Attack level:4, Defense level:4\n";
			cin>>amount;
			amount_copy = amount;
			if(goldAmount < amount*80){
				throw Exception();
			}
			while(amount>0){
				creatureArr[2]->setAmount(creatureArr[2]->getAmount() +1);
				numOfCreatures++;
				amount--;
			}
			goldAmount = goldAmount - (amount_copy*80);
			break;
		case 4:
			cout<<"Attack level:8, Defense level:2\n";
			cin>>amount;
			amount_copy = amount;
			if(goldAmount < amount*150){
				throw Exception();
			}
			while(amount>0){
				creatureArr[3]->setAmount(creatureArr[3]->getAmount() +1);
				numOfCreatures++;
				amount--;
			}
			goldAmount = goldAmount - (amount_copy*150);
			break;
		case 5:
			cout<<"Attack level:9, Defense level:10\n";
			cin>>amount;
			amount_copy = amount;
			if(goldAmount < amount*200){
				throw Exception();
			}
			while(amount>0){
				creatureArr[4]->setAmount(creatureArr[4]->getAmount() +1);
				numOfCreatures++;
				amount--;
			}
			goldAmount = goldAmount - (amount_copy*200);
			break;

	}
}

// Hero attacks another Hero attribute
void Hero::attack(Hero *oppHero, int attacker, int defender){
	int amount_before = oppHero->creatureArr[defender]->getAmount();
	creatureArr[attacker]->attack(oppHero->getCreaturesArr()[defender]);
	int amount_after = amount_before - oppHero->creatureArr[defender]->getAmount();
	oppHero->setNumberOfCreature(oppHero->numOfCreatures - amount_after);

	if(oppHero->numOfCreatures==0){
		if((goldAmount + oppHero->goldAmount )>2500){
			goldAmount = 2500;
			oppHero->goldAmount = 0;
		}
		else{
			goldAmount = goldAmount + oppHero->goldAmount;
			oppHero->goldAmount = 0;
		}
	}else if (numOfCreatures==0){
		if((goldAmount + oppHero->goldAmount )>2500){
			oppHero->goldAmount = 2500;
			goldAmount = 0;
				}
		else{
			oppHero->goldAmount = goldAmount + oppHero->goldAmount;
			goldAmount = 0;
		}
	}

}

// update the next hero turn
int Hero::endTurn(Hero** heroes, int currHero, int heroesAmount){
	tookGold = false;
	usedAbillity = false;
	if(heroes!= NULL){
		if(currHero==heroesAmount-1){
			for(int i = 0;i<heroesAmount;i++){
				if(heroes[i]!=NULL && heroes[i]->getIsDead()==false)
					return i;
			}
		}
		else{
			for(int i = currHero+1;i<heroesAmount;i++){
				if(heroes[i]!=NULL && heroes[i]->getIsDead()==false)
					return i;
			}
		}
	}
	return -1;
}

