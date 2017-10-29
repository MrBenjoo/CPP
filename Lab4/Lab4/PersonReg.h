#ifndef PERSONREG_H
#define PERSONREG_H

#include <string>

class Person; // forward declaration to make sure person is declared before use (cyclic dependeancy)

class PersonReg
{

private:
	Person *personer;
	int regSize;

public:
	PersonReg(int maxSize);
	~PersonReg();
	bool ReadReg(PersonReg& reg, std::string filename);
	void addPerson(Person*);
	Person* begin();
	Person* end();
	void print();
	void shuffle();
	void sortRegister();
};

#endif // PERSONREG_H
