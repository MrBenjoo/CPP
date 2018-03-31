#include <string>
#ifndef PersonReg_H
#define PersonReg_H

class Person; // forward declaration to make sure person is declared before use (cyclic dependeancy)

class PersonReg
{
	Person *personer;
	int maxSize;
	int index;
	int pos;

public:
	PersonReg(int maxSize);
	~PersonReg();
	Person *sökFritt(std::string name, Person *ptr_person);
	bool ReadReg(PersonReg& reg, std::string filename);
	void addPerson(Person*);
	void deletePerson(Person*);
	Person *searchPerson(Person*);
	void print();
};

#endif // !PersonReg



