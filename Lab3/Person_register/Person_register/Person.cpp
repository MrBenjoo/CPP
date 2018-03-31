#include <iostream>
#include "Person.h"

using namespace std;

Person::Person() // default constructor
{
}

Person::Person(string name, string adress) 
{
	this->name = name;
	this->adress = adress;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setAdress(string adress)
{
	this->adress = adress;
}

string Person::getName()
{
	return this->name;
}

string Person::getAdress()
{
	return this->adress;
}


void Person::print() 
{
	if (this->name != "") {
		cout << "Namn: " + this->name << endl;
		cout << "Address: " + this->adress << endl;
		cout << "" << endl;
	}
}

Person::~Person()
{

}

