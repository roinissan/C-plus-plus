//
// Created by Roi on 06/01/2019.
//

#ifndef ASSIGNMENT_5_DIRECTORYMAINPULATION_H
#define ASSIGNMENT_5_DIRECTORYMAINPULATION_H


#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <string.h>

class DirectoryManipulation{
public:
	// methods
	DirectoryManipulation(){};
	~DirectoryManipulation(){};
	bool deletePlayersDirectory(char *path);
	bool deleteGameDirectory(char *path);
	bool CreateDirectory(char *path, char *name);

	// fields
	std::string name;
};


#endif //ASSIGNMENT_5_DIRECTORYMAINPULATION_H
