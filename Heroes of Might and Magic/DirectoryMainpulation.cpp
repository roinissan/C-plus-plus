//
// Created by Roi on 06/01/2019.
//

#include "DirectoryMainpulation.h"



bool DirectoryManipulation::deletePlayersDirectory(char *path) {
	std::string file_path;
	std::string folder_name = path;
	std::string folder_name_new;
	struct dirent *entry = NULL;
	DIR *dir = NULL;
	int success;
	dir = opendir(path);
	if(dir == NULL)
		return true;
	char* abs_path[256];
	while(entry = readdir(dir))
	{
		file_path = entry->d_name;
		folder_name = folder_name + "/" + file_path;
		file_path =  folder_name + "/" + file_path + ".txt";

		success = remove(file_path.c_str());
		success =remove(folder_name.c_str());
		folder_name = path;
	}
	closedir(dir);
	success = remove(path);

}
bool DirectoryManipulation::deleteGameDirectory(char *path) {
	int success;
	std::string txt_file_path = path;
	txt_file_path = txt_file_path + "/general.txt";
	success = remove(txt_file_path.c_str());
	success = remove(path);


}
