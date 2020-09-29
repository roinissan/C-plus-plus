#include <iostream>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <fstream>
#include <cerrno>
#include <errno.h>

#include "DirectoryMainpulation.h"
#include "Warrior.h"
#include "Necromancer.h"
#include "Thief.h"

#include "Hero.h"
#include "Exception.h"


// function which checks if the given hero has more creatures
bool stillHaveCreatures(Hero** heroes,int index){

	if(heroes[index]->getIsDead()==true)
		return false;
	if(heroes[index]->getNumOfCreatures() > 0)
		return true;
	return false;
}
// function to find a hero given a name
int searchHero(Hero **heroes, int heroesAmount, string name){
	for(int i = 0;i<heroesAmount;i++){
		if(heroes[i]->getIsDead() == false && name==heroes[i]->getName()){
			return i;
		}
	}
	return -1;
}

// function to find a creature given a name
int findFightCreature(Hero* hero,string creature_name){
	for(int creature_index = 0 ; creature_index < 5 ; creature_index++)
		if(hero->getCreaturesArr()[creature_index]->getName() == creature_name)
			return creature_index;
	return -1;

}
// function which checks if the given attack parameters are ok
void attackValidation(Hero *attacker, Hero *defender,int &attackIn,int &defenceIn){
	bool valid_attack_name = false,valid_defence_name = false;
	int attack_creature_index = 0, defence_creature_index = 0;
	string attack_creature_name, defence_creature_name;

	cin >> attack_creature_name;
	cin >> defence_creature_name;


	attack_creature_index = findFightCreature(attacker,attack_creature_name);
	defence_creature_index = findFightCreature(defender,defence_creature_name);

	if(attack_creature_index != -1){
		valid_attack_name = true;
		attackIn = attack_creature_index;
	}
	if(defence_creature_index != -1){
		valid_defence_name = true;
		defenceIn = defence_creature_index;
	}
	try{
		if(valid_attack_name == false || attacker->getCreaturesArr()[attack_creature_index]->getAmount() == 0)
			throw Exception();
		if(valid_defence_name == false || defender->getCreaturesArr()[defence_creature_index]->getAmount() ==0)
			throw Exception();
	}
	catch(Exception &e){
		e.creatureNotExist();
		attackValidation(attacker, defender,attackIn,defenceIn);
	}

}

// function which checks the who is the winner of a fight given 2 heros
void fightWinnerCheck(Hero *attacker, Hero *defender){

	if(attacker->getNumOfCreatures() == 0){
		cout << "You have been perished\n";
		attacker->setIsDead(true);

	}
	else if(defender->getNumOfCreatures() == 0){
		cout << "You have been victorious\n";
		defender->setIsDead(true);
	}
}

// function which creates the heroes folders
bool createFolders(Hero** heroes, int number_of_players){
	int is_success;
	string sub_directory_name = "Heroes";

	is_success = mkdir(sub_directory_name.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (is_success == -1){
		cout << strerror(errno) << endl;
		return false;
	}
	sub_directory_name = "Game";
	is_success = mkdir(sub_directory_name.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (is_success == -1){
		cout << "Could not create the game folder" << endl;
		return false;
	}

	for(int player_name = 0; player_name < number_of_players; player_name++){
		sub_directory_name =  "Heroes/" + heroes[player_name]->getName();
		is_success = mkdir(sub_directory_name.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		if (is_success == -1){
			cout << "Could not create the warrior folder" << endl;
			return false;
		}

	}
	return true;
}
// function which creates the heroes files
bool createHeroesFiles(Hero** heroes,int total_amount){
	string file_name;
	string sub_directory_name = "Heroes/";
	for (int hero_index = 0; hero_index < total_amount; hero_index++ ){
		file_name = sub_directory_name + heroes[hero_index]->getName() + "/" + heroes[hero_index]->getName() + ".txt";
		std::fstream outfile (file_name.c_str(),ios::out);
		outfile << heroes[hero_index]->getType() << endl;
		outfile << heroes[hero_index]->getName() << endl;
		outfile << heroes[hero_index]->getGold() << endl;
		outfile << heroes[hero_index]->getTookGold() << endl;
		outfile << heroes[hero_index]->getUsedAbillity() << endl;
		outfile << heroes[hero_index]->getIsDead() << endl;
		outfile << heroes[hero_index]->getNumOfCreatures() << endl;
		outfile << heroes[hero_index]->getCreaturesArr()[0]->getAmount() << endl;
		outfile << heroes[hero_index]->getCreaturesArr()[1]->getAmount() << endl;
		outfile << heroes[hero_index]->getCreaturesArr()[2]->getAmount() << endl;
		outfile << heroes[hero_index]->getCreaturesArr()[3]->getAmount() << endl;
		outfile << heroes[hero_index]->getCreaturesArr()[4]->getAmount() << endl;
		outfile.close();
	}
	return true;
}

// function which saves parameters of the given fight
void saveGeneralData(Hero** heroes, int last_hero_turn_index, int total_amount,int turn_counter,int alive_heros){
	string war_sub_directory_name = "Game/general.txt";
	std::fstream outfile (war_sub_directory_name.c_str(),ios::out);
	outfile << total_amount << endl;
	outfile << turn_counter << endl;
	outfile << last_hero_turn_index << endl;
	outfile << alive_heros << endl;
	for (int hero_index = 0; hero_index < total_amount; hero_index++ ){
		outfile << heroes[hero_index]->getName() <<endl;
	}
	outfile.close();
}

// general function for saving the game data
bool saveData(Hero** heroes, int last_hero_turn_index, int total_amount,int turn_counter,int alive_heros){
	char main_directory_name[] = "Heroes";
	char game_directory_name[] = "Game";
	bool create_folders;

	//deletes the Hero folder
	DirectoryManipulation de;
	de.deletePlayersDirectory(main_directory_name);
	de.deleteGameDirectory(game_directory_name);


	// creates the Hero folder
	create_folders = createFolders(heroes,total_amount);
	if(!create_folders)
		return false;
	if(!createHeroesFiles(heroes, total_amount))
		return false;
	saveGeneralData(heroes, last_hero_turn_index, total_amount,turn_counter,alive_heros);
	return true;
}
// function to reset the heroes array
void resetHeroArr(Hero **heroes, int number_of_heroes){
	for(int hero = 0; hero < number_of_heroes; hero++)
		heroes[hero] = NULL;
}

// function which starts a new game
Hero** startNewGame(int heros_quantity[], int total){

	Hero** heroes_array = new Hero*[total];
	string heroes_type[3] = {"warrior","thief","necromancer"};
	string input_name;
	Hero *new_hero;
	int hero_random_turn;

	char main_directory_name[] = "Heroes";
	char game_directory_name[] = "Game";


	//deletes the Hero folder
	DirectoryManipulation de;
	de.deletePlayersDirectory(main_directory_name);
	de.deleteGameDirectory(game_directory_name);

	resetHeroArr(heroes_array,total);
	for (int hero_type = 0; hero_type < 3; hero_type++){
		for(int hero_type_quantity = 0; hero_type_quantity < heros_quantity[hero_type];hero_type_quantity++ ) {
			//check if starts from 1 or 0
			cout << "Please insert " << heroes_type[hero_type] << " number " << hero_type_quantity + 1 << " name:\n";
			cin >> input_name;

			if (hero_type == 0)
				new_hero = new Warrior();
			else if (hero_type == 1)
				new_hero = new Thief();
			else
				new_hero = new Necromancer();
			while (new_hero->getName() == "roei") {
				try {
					new_hero->setName(input_name);
				}
				catch (Exception &e) {
					e.nameNotLegal();
					cout << "Please insert " << heroes_type[hero_type] << " number " << hero_type_quantity + 1
						 << " name:\n";
					cin >> input_name;
				}
			}
			hero_random_turn = rand() % total;
			while(heroes_array[hero_random_turn] != NULL){
				hero_random_turn = rand() % total;
			}
			heroes_array[hero_random_turn] = new_hero;
		}
	}
	return heroes_array;

}

// function to load the previous game data
Hero** createDataFromFile(string *names, int number_of_players){
	string file_name, line, player_name;
	Hero **heroes_array = new Hero*[number_of_players];
	Hero *new_hero;
	int row_counter = 0;

	for(int player_index = 0; player_index < number_of_players; player_index++) {
		file_name = "Heroes/" + names[player_index] + "/" + names[player_index] + ".txt";
		std::fstream infile(file_name.c_str(),ios::in);
		if(!infile)
			return NULL;
		while (!infile.eof()) {
			infile >> line;
			if (row_counter == 0) {
				if (line == "Warrior")
					new_hero = new Warrior();
				else if (line == "Thief")
					new_hero = new Thief();
				else
					new_hero = new Necromancer();
			} else if (row_counter == 1) {
				new_hero->setName(line);
			} else if (row_counter == 2)
				new_hero->setGold(atof(line.c_str()));
			else if (row_counter == 3)
				new_hero->setTookGold(atoi(line.c_str()));
			else if (row_counter == 4)
				new_hero->setUsedAbillity(atoi(line.c_str()));
			else if (row_counter == 5)
				new_hero->setIsDead(atoi(line.c_str()));
			else if (row_counter == 6)
				new_hero->setNumberOfCreature(atoi(line.c_str()));
			else if (row_counter == 7)
				new_hero->getCreaturesArr()[0]->setAmount(atoi(line.c_str()));
			else if (row_counter == 8)
				new_hero->getCreaturesArr()[1]->setAmount(atoi(line.c_str()));
			else if (row_counter == 9)
				new_hero->getCreaturesArr()[2]->setAmount(atoi(line.c_str()));
			else if (row_counter == 10)
				new_hero->getCreaturesArr()[3]->setAmount(atoi(line.c_str()));
			else if (row_counter == 11)
				new_hero->getCreaturesArr()[4]->setAmount(atoi(line.c_str()));
			row_counter++;

		}
		row_counter = 0;
		heroes_array[player_index] = new_hero;
	}
	delete [] names;
	return heroes_array;
}

// function which load the previous data
Hero** continueLastGame(int &heroesAmount,int &turn_counter,int &last_hero_turn_index,int &alive_players){
	string line_string,*players_name;
	string war_sub_directory_name = "Game/general.txt";
	int row_counter = 0, player_counter = 0;

	std::fstream infile(war_sub_directory_name.c_str(),ios::in);
	if(!infile){
		cerr << "Could not open the file" << endl;
		return NULL;
	}
	while(!infile.eof()) {
		std::getline(infile,line_string);
		if(row_counter == 0){
			heroesAmount = atoi(line_string.c_str());
			players_name = new string[heroesAmount];
		}else if(row_counter == 1){
			turn_counter = atoi(line_string.c_str());
		}else if(row_counter == 2){
			last_hero_turn_index = atoi(line_string.c_str());
		}else if(row_counter == 3){
			alive_players = atoi(line_string.c_str());
		}else{
			if(player_counter < heroesAmount) {
				players_name[player_counter] = line_string;
				player_counter++;
			}
		}
		row_counter++;
	}

	infile.close();
	return(createDataFromFile(players_name,heroesAmount));
}

// function to check the indexes for printing - warriors,thieves,necs
int* get_print_order(Hero** heroes_array,int total){
	int *print_order = new int[total];
	int print_order_index = 0;
	for (int hero_type = 0; hero_type < 3; hero_type++){
		for (int hero_index = 0; hero_index < total; hero_index++){
			if (hero_type == 0) {
				if (heroes_array[hero_index]->getType() == "Warrior"){
					print_order[print_order_index] = hero_index;
					print_order_index++;
				}
			}else if (hero_type == 1) {
				if (heroes_array[hero_index]->getType() == "Thief"){
					print_order[print_order_index] = hero_index;
					print_order_index++;
				}
			}else{
				if (heroes_array[hero_index]->getType() == "Necromancer"){
					print_order[print_order_index] = hero_index;
					print_order_index++;
				}
			}
		}
	}
	return print_order;
}
// running the game
int main (int argc, char* args[]){
	int heroesAmount,warriors,thieves,necros,currHero,count,copy_heroes;
	Hero** heroes;
	if (argc > 2){
		warriors = atoi(args[2]);
		thieves = atoi(args[3]);
		necros = atoi(args[4]);
		if((warriors<0 || warriors>3) || (thieves<0 || thieves>3) || (necros<0 || necros>3)){
			cout<<"Wrong arguments inserted.\n";
			return 0;
		}
		currHero = 0,count = 0;
		int heros_quantity[] = {warriors,thieves,necros};
		heroesAmount = warriors + thieves + necros;
		heroes = startNewGame(heros_quantity,heroesAmount);
		copy_heroes = heroesAmount;
	}
	else{
		warriors = 0;
		thieves = 0;
		necros = 0;
		heroesAmount = warriors + thieves + necros;
		heroes = continueLastGame(copy_heroes,count,currHero,heroesAmount);
	}

	int user_input = 0 ,oppName = 0,attackerIn = 0, defenderIn = 0 , attackInput = 0;
	string fightHero = "",attacker,defender;
	int *print_order = get_print_order(heroes,copy_heroes);

	while(user_input!=7) {
		if (heroesAmount == 1) {
			for (int i = 0; i < copy_heroes; i++) {
				if (heroes[i]->getIsDead() == false) {
					cout << heroes[i]->getName() << " is the winner!\n";
					user_input = 7;
				}
			}

		} else {
			cout << "Welcome " << heroes[currHero]->getName() << "\n";
			cout << "What is your next step in the path to victory?\n";
			cout << "1. Attack\n";
			cout << "2. Get daily gold\n";
			cout << "3. Buy creatures\n";
			cout << "4. Show details\n";
			cout << "5. Special skill\n";
			cout << "6. End of my turn\n";
			cout << "7. Exit\n";
			cin >> user_input;
		}
		switch(user_input){
			case 1:
				cout<<"Attack:\n";
				cout<<"1. Show me my opponents\n";
				cout<<"2. Attack hero\n";
				cin>>attackInput;
				switch(attackInput){
					case 1:
						for(int i=0 ; i<copy_heroes;i++){
							if(!heroes[print_order[i]]->getIsDead() && heroes[print_order[i]]->getName() != heroes[currHero]->getName()){
								heroes[print_order[i]]->print();
								if(i != copy_heroes-1)
									cout<<"\n";
							}
						}
						fgetc(stdin);
						cin.ignore();
						break;
					case 2:
						if(count < 3)
							break;
						cout << "Please insert your opponent name:\n";
						cin >> fightHero;
						while(searchHero(heroes,copy_heroes,fightHero)==-1){
							try{
								throw Exception();
							}
							catch(Exception &e){
								e.heroNotExist();
								cout << "please insert your opponent name:\n";
								cin >> fightHero;
							}
						}
						oppName = searchHero(heroes,copy_heroes,fightHero);
						if(stillHaveCreatures(heroes,currHero)==true && stillHaveCreatures(heroes,oppName)==true)
							heroes[currHero]->printAttackInfo();
						if(stillHaveCreatures(heroes,currHero)==true && stillHaveCreatures(heroes,oppName)==true)
							heroes[oppName]->printAttackInfo();

						while(stillHaveCreatures(heroes,currHero)==true && stillHaveCreatures(heroes,oppName)==true){

							cout << heroes[currHero]->getName() << "'s "<< "turn:" << endl;
							attackValidation(heroes[currHero],heroes[oppName],attackerIn,defenderIn);
							heroes[currHero]->attack(heroes[oppName],attackerIn,defenderIn);
							if (stillHaveCreatures(heroes,oppName)==true && stillHaveCreatures(heroes,currHero)==true)
								heroes[oppName]->printAttackInfo();
							oppName = searchHero(heroes,copy_heroes,fightHero);
							if (stillHaveCreatures(heroes,oppName)==true && stillHaveCreatures(heroes,currHero)==true)
								heroes[currHero]->printAttackInfo();
							if (stillHaveCreatures(heroes,oppName) == false)
								break;
							cout << heroes[oppName]->getName() << "'s "<< "turn:" << endl;
							attackValidation(heroes[oppName],heroes[currHero],attackerIn,defenderIn);
							if (stillHaveCreatures(heroes,oppName)==true && stillHaveCreatures(heroes,currHero)==true)
								heroes[oppName]->attack(heroes[currHero],attackerIn,defenderIn);
							if (stillHaveCreatures(heroes,oppName)==true && stillHaveCreatures(heroes,currHero)==true)
								heroes[currHero]->printAttackInfo();
							oppName = searchHero(heroes,copy_heroes,fightHero);
							if (stillHaveCreatures(heroes,oppName)==true && stillHaveCreatures(heroes,currHero)==true)
								heroes[oppName]->printAttackInfo();

						}
						fightWinnerCheck(heroes[currHero],heroes[oppName]);
						if(heroes[currHero]->getIsDead()==true)
							currHero = heroes[currHero]->endTurn(heroes,currHero,copy_heroes);
						heroesAmount--;
						break;
				}
				break;
			case 2:
				if(heroes[currHero]->getTookGold() == false)
					heroes[currHero]->addGold();
				break;
			case 3:
				try{
					heroes[currHero]->purchaseCreatures();
					cout << heroes[currHero]->getNumOfCreatures() << endl;
					break;
				}
				catch(Exception &exc) {
					exc.notEnoughGold();
					break;
				}
				break;
			case 4:
				heroes[currHero]->showDetails();
				break;
			case 5:
				while(heroes[currHero]->getUsedAbillity()==false){
					try{
						heroes[currHero]->specialSkill(heroes,copy_heroes);
					}
					catch(Exception &e){
						e.heroNotExist();
					}
				}
				break;
			case 6:
				currHero = heroes[currHero]->endTurn(heroes,currHero,copy_heroes);
				count++;
				break;
			case 7:
				user_input = 7;
				saveData(heroes,currHero,copy_heroes,count,heroesAmount);
				for(int hero = 0; hero < copy_heroes; hero++)
					if (heroes[hero] != NULL)
						delete heroes[hero];
				delete [] heroes;
				delete [] print_order;
		}

	}

	return -1;
}

