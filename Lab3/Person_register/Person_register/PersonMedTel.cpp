#include "PersonMedTel.h"
#include <iostream>

using namespace std;

string nummer;

PersonMedTel::PersonMedTel() 
{

}

PersonMedTel::PersonMedTel(string nummer)
{
	this->nummer = nummer;
}

void PersonMedTel::print()
{
	cout << "personMedTel: nummer = " + this->nummer << endl;
}
