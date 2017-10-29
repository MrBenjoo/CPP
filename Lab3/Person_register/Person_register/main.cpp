#include "PersonReg.h"
#include "Person.h"
#include "PersonMedTel.h"
#include <iostream>


using namespace std;

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	locale::global(locale("swedish"));


	/******************** TEST 1 ********************************/
	/*
	PersonReg *persongReg = new PersonReg(3);

	Person person1("benjamin", "Kaptensgränd 94, 310 83  UNNARYD");
	persongReg->addPerson(&person1);

	Person person2("Olle", "Esplanadgatan 45, 776 03  DALA-HUSBY");
	persongReg->addPerson(&person2);

	Person person3("Haris", "Hårds väg");
	persongReg->addPerson(&person3);

	Person person4("Johan", "blabla");

	persongReg->print();

	Person *search_person1 = persongReg->searchPerson(&person1);
	Person *search_person2 = persongReg->searchPerson(&person2);
	Person *search_person3 = persongReg->searchPerson(&person3);
	Person *search_person4 = persongReg->searchPerson(&person4);


	persongReg->deletePerson(&person3);
	persongReg->print();

	delete persongReg;
	*/


	/**************** TEST 2***************************************************/
	/*
	PersonReg *persongReg = new PersonReg(6);
	persongReg->ReadReg(*persongReg, "../PersonExempel.txt");

	Person* x1 = persongReg->sökFritt("Olle", nullptr); //x1 blir första träffen
	Person* x2 = persongReg->sökFritt("Olle", x1);      //x2 blir andra träffen
	Person* x3 = persongReg->sökFritt("Olle", x2);      //x3 blir tredje träffen


	if (x1 != nullptr) {
	cout << "x1 namn: " + x1->getName() << endl;
	cout << "x1 adress: " + x1->getAdress() + "\n" << endl;
	}
	if (x2 != nullptr) {
	cout << "x2 namn: " + x2->getName() << endl;
	cout << "x2 adress: " + x2->getAdress() + "\n" << endl;
	}
	if (x3 != nullptr) {
	cout << "x3 namn: " + x3->getName() << endl;
	cout << "x3 adress: " + x3->getAdress() + "\n" << endl;
	}

	delete persongReg;
	*/


	
	/******************** TEST 3 ********************************/
	
	PersonReg *persongReg = new PersonReg(7);
	persongReg->ReadReg(*persongReg, "../PersonExempel.txt");

	Person *personMedTel = new PersonMedTel("0725294688");
	personMedTel->print();

	persongReg->addPerson(personMedTel);
	persongReg->print();
	
	delete persongReg;
	delete personMedTel;
	
	return 0;
}

