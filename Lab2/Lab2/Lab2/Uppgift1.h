#ifndef UPPGIFT1_H
#define UPPGIFT1_H

#include <vector>

class Uppgift1 {
	std::vector<int> ivec;

	void createVector(int size); /* skapar en vektor med element från 2-n */
	void deleteEvenNbrs(); /* stryker ut alla jämn tal från vektorn som är större än 2 */
	void deletePrimeMultiples(); /* stryker ut primtalets multiplar och tal som är större än primtalet */
	void printPrimeNbrs();

public:
	void runUppgift1();
};

#endif // !UPPGIFT1_H
