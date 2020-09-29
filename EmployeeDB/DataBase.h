/*
 * DataBase.h
 *
 *  Created on: Dec 11, 2018
 */

#ifndef DATABASE_H_
#define DATABASE_H_
using namespace std;
#include "Employee.h"

class DataBase{

	Employee** employees;
	int numOfEmp;
	int currCapacity;

public:
	DataBase();
	DataBase(const DataBase& other);
	~DataBase();
	int getNumberOfEmployees();
	Employee* getEmployee(int idEmployee);
	bool addEmployee(Employee* newEmp);
	bool removeEmployee(int idEmployee);
	void print();
	bool searchEmployee(int idEmployee);
	int indexOfEmployee(int idEmployee);
	Employee** copyList(Employee** list,int numEmp);
};


#endif /* DATABASE_H_ */
