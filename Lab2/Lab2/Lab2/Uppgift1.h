#ifndef UPPGIFT1_H
#define UPPGIFT1_H

#include <vector>

class Uppgift1 {
	std::vector<int> ivec;

	void createVector(int size); /* skapar en vektor med element fr�n 2-n */
	void deleteEvenNbrs(); /* stryker ut alla j�mn tal fr�n vektorn som �r st�rre �n 2 */
	void deletePrimeMultiples(); /* stryker ut primtalets multiplar och tal som �r st�rre �n primtalet */
	void printPrimeNbrs();

public:
	void runUppgift1();
};

#endif // !UPPGIFT1_H
