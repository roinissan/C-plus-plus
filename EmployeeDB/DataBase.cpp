/*
 * DataBase.cpp
 *
 *  Created on: Dec 11, 2018
 */
#include "DataBase.h"


// Default Constructor
DataBase::DataBase(){
	Employee** list = new Employee*[3];
	if(list){
		employees = list;
		numOfEmp=0;
		currCapacity = 3;
	}
}

// Copy Constructor
DataBase::DataBase(const DataBase& other){
	if(other.employees){
		employees = copyList(other.employees,other.numOfEmp);
	}
	if(other.numOfEmp)
		numOfEmp = other.numOfEmp;
	if(other.currCapacity)
		currCapacity = other.currCapacity;
	//delete other;
}

// Destructor
DataBase::~DataBase(){
	for(int employee_id = 0; employee_id < this->numOfEmp; employee_id++)
		if (employees[employee_id])
			delete employees[employee_id];
	delete[] employees;
}

// Get the numberOfEmployees field
int DataBase::getNumberOfEmployees(){
	return numOfEmp;
}

// Adds a new employee to the database
// If exists or failed in memory allocation return false
bool DataBase::addEmployee(Employee* newEmp){
	if(newEmp==NULL)
		return false;

	if(searchEmployee(newEmp->getId())==true){
		cout<<"This employee is already in the database\n"<<"\n";
		delete newEmp;
		return false;
	}
	if(numOfEmp==currCapacity){
		currCapacity = currCapacity+currCapacity;
		Employee** newList = new Employee*[currCapacity];
		if(!newList){
			currCapacity = currCapacity / 2;
			return false;
		}
		for(int i = 0;i<numOfEmp;i++){
			newList[i]=new Employee(*employees[i]);
			newList[i]->setNumOfEmps(numOfEmp++);
			if(!newList[i]){
				for(int j=0;j<i;j++)
					delete newList[i];
				currCapacity = currCapacity / 2;
				delete[] newList;
				return false;
			}
		}
		newList[numOfEmp] = new Employee(*newEmp);
		newList[numOfEmp]->setNumOfEmps(numOfEmp+ 1);
		for(int j = 0; j<numOfEmp;j++){
			delete employees[j];
		}
		delete[] employees;
		employees = newList;
		numOfEmp++;
		return true;
	}


	employees[numOfEmp]= new Employee(*newEmp);
	for(int j = 0; j <= numOfEmp;j++){
		employees[j]->setNumOfEmps(numOfEmp+1);
	}
	numOfEmp++;
	delete newEmp;
	return true;
}


// Remove and existing employee from the DB
// If does not exists or failed in new allocation of memory for the new employee array returns false
bool DataBase::removeEmployee(int idEmployee){
	if(searchEmployee(idEmployee)==false){
		cout<<"This employee isn't in the database\n"<<"\n";
		return false;
	}
	int index = indexOfEmployee(idEmployee);
	Employee** newList = new Employee*[numOfEmp-1];
	if(!newList)
		return false;
	for(int i = 0;i<numOfEmp;i++){
		if(i<index){
			newList[i]= new Employee(*employees[i]);
			newList[i]->setNumOfEmps(numOfEmp-1);
			if(!newList[i]){
				for(int j=0;j<i;j++)
					delete newList[j];
				delete[] newList;
				return false;
			}
		}
		if(i>index){
			newList[i-1] = new Employee(*employees[i]);
			newList[i-1]->setNumOfEmps(numOfEmp-1);
			if(!newList[i-1]){
				for(int j=0;j<i-1;j++)
					delete newList[j];
				delete []newList;
				return false;
			}
		}
	}
	for(int j = 0; j<numOfEmp;j++){
		delete employees[j];
	}
	delete[] employees;
	employees = newList;
	numOfEmp--;
	return true;
}


// Checks whether if employee exists given an id
bool DataBase::searchEmployee(int idEmployee){
	for(int i = 0; i<numOfEmp;i++){
		if(employees[i]->getId()==idEmployee)
			return true;
	}
	return false;
}

// returns the index in the employee array of an employee given an id
int DataBase::indexOfEmployee(int idEmployee){
	int index=0;
	for(int i = 0; i<numOfEmp;i++){
		if(employees[i]->getId()==idEmployee)
			index = i;
	}
	return index;
}

// prints all the employees and the rest of the fields of the DB
void DataBase::print(){
	cout<<"Employees database:\n";
	for(int i = 0; i<numOfEmp;i++){

		cout<<"\n"<<"Name:"<<employees[i]->getName()<<"\n"<<"ID:"<<employees[i]->getId()<<"\n"<<"Salary:"<<employees[i]->getSalary()<<"\n"<<"\n";
	}
}


//copies the employees array
Employee** DataBase::copyList(Employee** list,int numEmp){
	if(list==NULL)
		return NULL;
	Employee** newList = new Employee*[numEmp];
	for(int i = 0; i<numEmp;i++){
		newList[i] = new Employee(*list[i]);
	}
	return newList;
}

// returns pointer to the given employee
Employee* DataBase::getEmployee(int idEmployee){
	for(int i=0;i<numOfEmp;i++){
		if(employees[i]->getId()==idEmployee)
			return employees[i];
	}
	return NULL;
}


