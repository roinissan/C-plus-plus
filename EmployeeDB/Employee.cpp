/*
 * Employee.cpp
 *
 *  Created on: Dec 11, 2018
 */
#include "Employee.h"

// Parametrized Constructor
Employee::Employee(char* nameEmployee,int idEmployee,int salaryEmployee){
	name = new char[strlen(nameEmployee) + 1];
	if(!name)
		name=NULL;
	else
		strcpy(name,nameEmployee);
	if(idEmployee)
		id=idEmployee;
	if(salaryEmployee)
		salary=salaryEmployee;
	numOfEmps = 0;
}

// Default Constructor
Employee::Employee(){

	name=(char*)"Name";
	id=0;
	salary=0;
	numOfEmps=0;

}

// Copy Constructor
Employee::Employee(const Employee& other){
	name = new char[strlen(other.name) + 1];
	if(!name)
		name=NULL;
	else
		strcpy(name,other.name);
	if(other.id)
		id=other.id;
	if(other.salary)
		salary=other.salary;
	numOfEmps = other.numOfEmps;

}

// Destructor
Employee::~Employee(){
	if(name)
		delete []name;
}

// changes the current name to new name
bool Employee::setName(char* newName){
	if (!newName)
		return false;
	char* temp;
	temp = new char[strlen(newName) + 1];
	if (!temp)
		return false;
	strcpy(temp, newName);
	if (name && strlen(name) >0)
		delete []name;
	name = temp;
	return true;
}
// change the numOfEmployees
bool Employee::setNumOfEmps(int numOfEmpsToAdd){
	this->numOfEmps = numOfEmpsToAdd;
	return true;
}

// Returns the ID of employee
int Employee::getId(){
	return id;
}

// Returns the salary of the employee
double Employee::getSalary(){
	return salary;
}
// Returns the name of the employee
char* Employee::getName(){
	return name;
}

// Returns the numOfEmployees
int Employee::getNumOfEmps(){
	return numOfEmps;
}

// Reurns the price needed for organizing a party
int Employee::planOfficeParty(){
	return numOfEmps*10;
}

// Prints the employee data
void Employee::print(){
	cout<<"Name:"<<name<<"\n"<<"ID:"<<id<<"\n"<<"Salary:"<<salary<<"\n"<<"\n";
}

// Override the "==" operator
bool Employee::operator==(const Employee& Emp)const{
	Employee* temp = new Employee(Emp);
	if(this->id==temp->id){
		delete temp;
		return true;
	}
	delete temp;
	return false;
}

// Override the ">" operator
bool Employee::operator>(const Employee& Emp)const{
	Employee* temp = new Employee(Emp);
	if(this->salary > temp->salary){
		delete temp;
		return true;
	}
	delete temp;
	return false;
}

// Override the "=" operator
Employee& Employee::operator=(const Employee& Emp){
	Employee* temp = new Employee(Emp);
	this->setName(temp->name);
	delete temp;
	return *this;
}

// Override the "+" operator
Employee& Employee::operator+(const Employee& Emp){
	Employee* temp = new Employee(Emp);
	this->salary=this->salary+temp->salary;
	delete temp;
	return *this;
}

// Override the " before ++"  operator
Employee& Employee::operator++(){
	this->salary = this->salary+100;
	return *this;
}

// Override the "+=" operator
Employee& Employee::operator+=(const Employee& Emp){
	Employee* tmp = new Employee(Emp);
	int size1 = strlen(this->name);
	int size2 = strlen(tmp->name);
	int totalSize = size1+size2+1;
	char* temp = new char[totalSize];
	for(int i =0;i<size1;i++){
		temp[i]=this->name[i];
	}
	int x = 0;
	for(int j = size1;j<totalSize;j++){
		temp[j]=tmp->name[x];
		x++;
	}
	this->setName(temp);
	delete[] temp;
	delete tmp;
	return *this;
}

// Override the "<<" operator
ostream& operator<<(ostream& out, const Employee& Emp){
	Employee* temp = new Employee(Emp);
	temp->print();
	delete temp;
	return out;
}

// Override the "after ++" operator
Employee Employee::operator++(int x){
	Employee temp (*this);
	operator++();
	return temp;

}

