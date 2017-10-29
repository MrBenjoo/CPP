#include "Uppgift1a.h"
#include "Uppgift1b.h"
#include "Uppgift1c.h"
#include "Uppgift1d.h"
#include "PersonReg.h"
#include "Uppgift3.h"


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// UPPGIFT 1a 
	Uppgift1a uppgift1a;
	uppgift1a.createVector(); 

	// UPPGIFT 1b 
	Uppgift1b uppgift1b;
	uppgift1b.createCArray(); 

	// UPPGIFT 1c
	Uppgift1c uppgift1c;
	uppgift1c.createVector();

	// UPPGIFT 1d
	Uppgift1d uppgift1d;
	uppgift1d.sortDesc();

	// UPPGIFT 2A / 2B
	PersonReg *persongReg = new PersonReg(6);
	persongReg->ReadReg(*persongReg, "../PersonExempel.txt");
	persongReg->shuffle();
	persongReg->print();
	persongReg->sortRegister();
	persongReg->print();
	delete persongReg;

	// UPPGIFT 3
	Uppgift3 uppgift3;
	uppgift3.createContainer();
	uppgift3.printContainer();
	uppgift3.shuffleContainer();
	uppgift3.printContainer();
	uppgift3.removeEvenNumbers();
	uppgift3.printContainer();

	return 0;
}