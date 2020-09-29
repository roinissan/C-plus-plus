/*
 * Employee.h
 *
 *  Created on: Dec 11, 2018
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Employee{

	char* name;
	int id;
	double salary;
	int numOfEmps;

public:

	Employee(char* nameEmployee,int idEmployee, int salaryEmployee);
	Employee();
	Employee(const Employee& other);
	~Employee();

	int planOfficeParty();

	bool setName(char* newName);
	bool setNumOfEmps(int numOfEmpsToAdd);

	int getId();
	double getSalary();
	char* getName();
	int getNumOfEmps();

	void print();
	bool operator==(const Employee& Emp)const;
	bool operator>(const Employee& Emp)const;
	Employee& operator=(const Employee& Emp);
	Employee& operator+(const Employee& Emp);
	Employee& operator++();
	Employee& operator+=(const Employee& Emp);
	Employee operator++(int x);
	friend ostream& operator<<(ostream& out, const Employee& Emp);




};

#endif /* EMPLOYEE_H_ */
