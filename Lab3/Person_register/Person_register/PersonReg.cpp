#include "PersonReg.h"
#include "Person.h"
#include <iostream>
#include <fstream>

using namespace std;

Person *personer;
int maxSize;
int index = 0;
int pos = 0;


PersonReg::PersonReg(int maxSize)
{
	this->maxSize = maxSize;
	personer = new Person[maxSize];
	cout << "maxSize: " << maxSize << "\n" << endl;
}

void PersonReg::addPerson(Person *person)
{
	bool foundEmptySlot = false;

	while ((index < maxSize) && (!foundEmptySlot)) {
		if (personer[index].getName().empty()) {
			foundEmptySlot = true;
		}
		else {
			++index;
		}
	}

	if (foundEmptySlot) {
		personer[index].setName(person->getName());
		personer[index].setAdress(person->getAdress());
		cout << "Added:" << endl;
		cout << "     Namn: " + personer[index].getName() << endl;
		cout << "     Address: " + personer[index].getAdress() << endl;
		if (!person->getNummer().empty()) 
		{
		personer[index].setNummer(person->getNummer());
		cout << "     Nummer: " + personer[index].getNummer() << endl;
		}
		cout << "" << endl;
	}

}

void PersonReg::deletePerson(Person *person)
{
	bool foundName = false;

	cout << "" << endl;
	cout << "Person to delete:" << endl;
	cout << "                Namn: " + person->getName() << endl;
	cout << "                Address: " + person->getAdress() + "\n" << endl;

	if (!person->getName().empty())
	{
		int i = 0;
		string name = person->getName();

		while (i < maxSize && !foundName)
		{
			if (name == personer[i].getName()) 
			{
				foundName = true;
			}
			else 
			{
				++i;
			}
		}

		if (foundName) 
		{
			for (Person* ptr = &personer[i]; ptr != personer + maxSize; ++ptr)
			{
				if (ptr == (personer + (maxSize - 1)))
				{
					ptr->setName("");
					ptr->setAdress("");
				}
				else
				{
					ptr->setName(ptr[1].getName());
					ptr->setAdress(ptr[1].getAdress());
				}
			}
			cout << name + " was deleted from the register" << endl;
		}

	}
}

Person* PersonReg::searchPerson(Person *person)
{
	bool foundPerson = false;
	if (!person->getName().empty())
	{
		string name = person->getName();
		int i = 0;
		while (i < maxSize && !foundPerson) 
		{
			if (name == personer[i].getName()) 
			{
				foundPerson = true;
			}
			else 
			{
				++i;
			}
		}
		
		if (foundPerson) 
		{
			Person *ptr = &personer[i];
			cout << ptr->getName() + " was found in the register" << endl;
			return ptr;
		}
		else 
		{
			cout << name + " was not found in the register" << endl;
			return nullptr;
		}
		
	}
}

void PersonReg::print()
{
	cout << "" << endl;
	cout << "" << endl;
	cout << "Print all person objects in the register" << endl;
	cout << "****************************************" << endl;
	for (Person* ptr = personer; ptr != personer + maxSize; ++ptr) 
	{
		ptr->print();
	}
	cout << "****************************************" << endl;
	cout << "" << endl;
	cout << "" << endl;

}

PersonReg::~PersonReg() 
{
	delete[] personer;
	maxSize = 0;
	index = 0;
	pos = 0;
	personer = nullptr;
}

bool PersonReg::ReadReg(PersonReg& reg, string fileName) 
{
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			while (line.length() == 0 && getline(myfile, line))
				;
			string name(line);
			string adress;
			getline(myfile, adress);
			reg.addPerson(&Person(name, adress));
		}
		myfile.close();
		return true;
	}
	else 
	{
		cout << "Unable to open file";
		return false;
	}
}

Person* PersonReg::sökFritt(string name, Person *ptr_person)
{
	if (ptr_person == nullptr) 
	{
		while (pos < maxSize) 
		{
			if (personer[pos].getName() == name) 
			{
				return &personer[pos];
			}
			++pos;
		}
		return nullptr;
	}
	else 
	{
		int tempSize = maxSize - pos;
		++ptr_person;
		while (pos < tempSize) 
		{
			if (ptr_person->getName() == name) 
			{
				return ptr_person;
			}
			++ptr_person;
			++pos;
		}
		return ptr_person = nullptr;
	}
}
