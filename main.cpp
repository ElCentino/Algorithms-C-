#include <iostream>
#include <string>
#include <ctime>
#include "Queue.h"
#include "Quicksort.h"
#include "BinarySearch.h"
#include "Tree.h"
#include "Linkedlist.h"
#include "Bubblesort.h"
#include "crypt.h"

#define employeesSize 10

using namespace std;

class Employee {

private:
	int *age;
	int *salary;
	string *name;

public:
	Employee(string *name, int *age, int *salary)
	{
		Employee::name = name;
		Employee::salary = salary;
		Employee::age = age;
	}

	Employee(string net, string we)
	{

	}

	~Employee()
	{
		delete age, salary, name;
	}

	string getName()
	{
		return *name;
	}

	int getAge()
	{
		return *age;
	}

	int getSalary()
	{
		return *salary;
	}

	void displayEmployee(Employee[]);

private:
	void swap(Employee[], int, int);
	void sortEmployee(Employee[]);
	void sortEmployee(Employee[], int, int);
	int partition(Employee[], int, int, int);
};

void Employee::sortEmployee(Employee employees[])
{
	int size = sizeof(employees) / sizeof(employees[0]);
	sortEmployee(employees, 0, size);
}

void Employee::sortEmployee(Employee employees[], int left, int right)
{
	if (left >= right)
		return;

	int pivot = *employees[(sizeof(employees) / sizeof(employees[0])) / 2].age;

	int index = partition(employees, left, right, pivot);

	sortEmployee(employees, left, index);
	sortEmployee(employees, index + 1, right);
}

int Employee::partition(Employee employee[], int left, int right, int pivot)
{
	while (*employee[left].age < pivot)
	{
		left++;
	}

	while (*employee[right].age > pivot)
	{
		right--;
	}

	if (left <= right)
	{
		swap(employee, left, right);
		left++;
		right--;
	}

	return left;
}

void displayEmployee(Employee *employees[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "No : " << i << "; Name :" << employees[i]->getName() << endl;
		cout << "No : " << i << "; Age :" << employees[i]->getAge() << endl;
		cout << "No : " << i << "; Salary :" << employees[i]->getSalary() << endl;
	}
}

void Employee::swap(Employee employees[], int left, int right)
{
	Employee temp = employees[left];
	employees[left] = employees[right];
	employees[right] = temp;
}

int main() 
{
	crypt crp;

	int keys = 1213432;
	
	string ciphertext = "Ciphertext";
	string deciphedtext = crp.IXOR(ciphertext, keys);
	string tempdeci = "╗æêÉ¥èî¥Çî";

	//cout << crp.IXOR(ciphertext, keys) << endl;
	cout << crp.IXOR(tempdeci, 248);

	char key[] = {'1','2','3'};

	cout << crp.BruteForkey(ciphertext, deciphedtext, 123, 100, 100 , 0) << endl;

	

	getchar();
}