Heroes.exe: Main.o Hero.o Necromancer.o Thief.o Warrior.o Creature.o Archer.o BlackDragon.o Vampire.o Wizard.o Zombie.o Exception.o DirectoryMainpulation.o
	g++ Main.o Hero.o Necromancer.o Thief.o Warrior.o Creature.o Archer.o BlackDragon.o Vampire.o Wizard.o Zombie.o Exception.o DirectoryMainpulation.o -o Heroes.exe

Main.o: Main.cpp DirectoryMainpulation.h Warrior.h Necromancer.h Thief.h Hero.h Exception.h
	g++ -c Main.cpp

Hero.o: Hero.cpp Hero.h
	g++ -c Hero.cpp

Necromancer.o: Necromancer.cpp Necromancer.h
	g++ -c Necromancer.cpp

Thief.o: Thief.cpp Thief.h
	g++ -c Thief.cpp

Warrior.o: Warrior.cpp Warrior.h
	g++ -c Warrior.cpp

Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp

Archer.o: Archer.cpp Archer.h
	g++ -c Archer.cpp

BlackDragon.o: BlackDragon.cpp BlackDragon.h
	g++ -c BlackDragon.cpp

Vampire.o: Vampire.cpp Vampire.h
	g++ -c Vampire.cpp

Wizard.o: Wizard.cpp Wizard.h
	g++ -c Wizard.cpp

Zombie.o: Zombie.cpp Zombie.h
	g++ -c Zombie.cpp

Exception.o: Exception.cpp Exception.h
	g++ -c Exception.cpp

DirectoryMainpulation.o: DirectoryMainpulation.cpp DirectoryMainpulation.h
	g++ -c DirectoryMainpulation.cpp

Clean:
	rm -rf *o run
