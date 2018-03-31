#include "PersonMedTel.h"
#include <iostream>

using namespace std;

PersonMedTel::PersonMedTel() { /* empty constructor */ }

PersonMedTel::PersonMedTel(string nummer)
{
	this->nummer = nummer;
}

void PersonMedTel::print()
{
	cout << "personMedTel: nummer = " + this->nummer << endl;
}