#include <string>
#include "Person.h"

#ifndef PERSONMEDTEL_H
#define PERSONMEDTEL_H


class PersonMedTel : public Person {
	
private:
	std::string nummer;

public:
	PersonMedTel();
	PersonMedTel(std::string nummer);
	void print();
};

#endif 