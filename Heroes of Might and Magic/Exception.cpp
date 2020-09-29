//
// Created by Roi on 05/01/2019.
//

#include "Exception.h"

Exception::Exception(){
}

Exception::~Exception(){
}

void Exception::nameNotLegal(){
	std::cout<<"Name is not legal. Exception Nr. 1\n";
}

void Exception::notEnoughGold(){
	std::cout<<"Not enought gold. Exception Nr. 2\n";
}

void Exception::heroNotExist(){
	std::cout<<"Hero not exist. Exception Nr. 4\n";
}

void Exception::creatureNotExist(){
	std::cout<<"Creature not exist. Exception Nr. 3\n";
}
