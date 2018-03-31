#include "Uppgift1.h"
#include "Uppgift2.h"
#include "Uppgift3.h"

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	/*Uppgift1 *uppgift1 = new Uppgift1;
	uppgift1->runUppgift1();
	delete uppgift1;*/

	/*Uppgift2 *uppgift2 = new Uppgift2;
	uppgift2->runUppgift2();
	delete uppgift2;*/

	Uppgift3 *uppgift3 = new Uppgift3;
	uppgift3->runUppgift3();
	delete uppgift3;

	return 0;
}