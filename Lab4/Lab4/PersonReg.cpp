#include "PersonReg.h"
#include "Person.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int index = 0;

PersonReg::PersonReg(int regSize)
{
	this->regSize = regSize;
	personer = new Person[regSize];
}

void PersonReg::addPerson(Person *person)
{
	bool foundEmptySlot = false;

	while ((index < regSize) && (!foundEmptySlot)) {
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
		cout << "" << endl;
	}

}

Person * PersonReg::begin()
{
	return personer;
}

Person * PersonReg::end()
{
	return personer + regSize;
}

void PersonReg::print()
{
	cout << "\n\nPrinting all the person objects in the register..." << endl;
	cout << "****************************************" << endl;
	for (Person* ptr = personer; ptr != personer + regSize; ++ptr)
	{
		ptr->print();
	}
	cout << "****************************************\n\n" << endl;

}

void PersonReg::shuffle()
{
	cout << "\n\nShuffling persons\n" << endl;
	random_shuffle(begin(), end());
}

void PersonReg::sortRegister()
{
	cout << "\n\Sorting persons\n" << endl;
	sort(begin(), end());
}

PersonReg::~PersonReg()
{
	delete[] personer;
}

bool PersonReg::ReadReg(PersonReg& reg, string fileName)
{
	cout << "\n\n**** Uppgift2a ****\n\n" << endl;
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
