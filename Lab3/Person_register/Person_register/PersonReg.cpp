#include "PersonReg.h"
#include "Person.h"
#include <iostream>
#include <fstream>

using namespace std;

PersonReg::PersonReg(int maxSize)
{
	this->maxSize = maxSize;
	this->personer = new Person[maxSize];
	this->index = 0;
	this->pos = 0;
	cout << "maxSize: " << maxSize << "\n" << endl;
}

void PersonReg::addPerson(Person *person)
{
	Person *pbeg = personer;
	Person *pend = personer + maxSize;
	bool foundEmptySlot = false;

	while (pbeg != pend && !foundEmptySlot)
	{
		if (pbeg->getName().empty()) {
			pbeg->setName(person->getName());
			pbeg->setAdress(person->getAdress());
			cout << "Added:" << endl;
			cout << "     Namn: " + pbeg->getName() << endl;
			cout << "     Address: " + pbeg->getAdress() << endl;
			foundEmptySlot = true;
		}
		else
			++pbeg;
	}

}

void PersonReg::deletePerson(Person *person)
{
	cout << "\nPerson to delete:" << endl;
	cout << "                Namn: " + person->getName() << endl;
	cout << "                Address: " + person->getAdress() + "\n" << endl;
	*person = personer[maxSize];
}

Person* PersonReg::searchPerson(Person *person)
{
	Person *pbeg = personer;
	Person *pend = personer + maxSize;
	bool foundPerson = false;

	while (pbeg != pend && !foundPerson)
	{
		if (person->getName() == pbeg->getName())
		{
			cout << "Found person:" << endl;
			cout << "            Namn: " + pbeg->getName() << endl;
			cout << "            Address: " + pbeg->getAdress() << endl;
			foundPerson = true;
		}
		else
			++pbeg;
	}

	if (foundPerson)
		return pbeg;
	else
		return nullptr;

}


void PersonReg::print()
{
	cout << "\n\nPrint all person objects in the register" << endl;
	cout << "****************************************" << endl;
	for (Person* ptr = personer; ptr != personer + maxSize; ++ptr)
	{
		ptr->print();
	}
	cout << "****************************************\n\n" << endl;
}

PersonReg::~PersonReg()
{
	delete[] personer;
}

bool PersonReg::ReadReg(PersonReg& reg, string fileName)
{
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			while (line.length() == 0 && getline(myfile, line));
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
	Person *pbeg = personer;
	Person *pend = personer + maxSize;
	if (ptr_person != nullptr)
		pbeg = ++ptr_person; // start search from last found person + 1

	bool foundPerson = false;

	while (pbeg != pend && !foundPerson)
	{
		if (pbeg->getName() == name || pbeg->getAdress() == name)
		{
			cout << "Found person:" << endl;
			cout << "            Namn: " + pbeg->getName() << endl;
			cout << "            Address: " + pbeg->getAdress() << endl;
			foundPerson = true;
		}
		else
			++pbeg;
	}

	if (foundPerson)
		return pbeg;
	else
		return nullptr;

}
