#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{

private:
	std::string name;
	std::string adress;

public:
	Person();
	Person(std::string name, std::string adress);
	void setName(std::string name);
	void setAdress(std::string adress);
	std::string getName();
	std::string getAdress();
	virtual void print();
	virtual ~Person();
	bool operator<(const Person& that);
		
};

#endif // !PERSON_H



