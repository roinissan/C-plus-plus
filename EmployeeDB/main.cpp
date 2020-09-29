#include "DataBase.h"
using namespace std;
int main() {

	DataBase dataBase;

	dataBase.addEmployee(new Employee((char*)"Sharon",11,10000));

	dataBase.addEmployee(new Employee((char*)"Yael",11,11000));
	dataBase.addEmployee(new Employee((char*)"Yael",12,20000));
	dataBase.addEmployee(new Employee((char*)"Barak",10,11000));
	DataBase copy(dataBase);

	copy.print();

	copy.removeEmployee(1);
	copy.removeEmployee(11);
	copy.print();


	copy.print();
	Employee *yael = copy.getEmployee(12);
	Employee *barak = copy.getEmployee(10);


	cout<<"Cost party for Barak: "<< barak->planOfficeParty() << "\n" <<endl;

	if(*barak>*yael)
	{
		cout<<"Barak's salary is higher than Yael's \n"<<endl;
	}

	//double salaryBefore =((*barak)++).getSalary();
	//cout<< "Salary before:"<< salaryBefore <<"\n"<<endl;
	cout <<++(*barak)<<endl;
	//cout <<(*yael)<<endl;

	*barak+*yael;
	*barak += *yael;
//	*barak + ++*yael;


	copy.print();

	if(*barak>*yael)
	{
		cout<<"Barak's salary is higher than Yael's \n"<<endl;
	}
	//dataBase.removeEmployee(12);
	//dataBase.removeEmployee(10);

	return 0;

}
