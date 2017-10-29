#include "Uppgift1.h"
#include <iostream>


void Uppgift1::runUppgift1()
{
	int vectorSize;
	std::cout << "Hur stor n?" << std::endl;
	std::cin >> vectorSize;
	std::cout << "" << std::endl;
	createVector(vectorSize);
	deleteEvenNbrs();
	deletePrimeMultiples();
	printPrimeNbrs();
}

void Uppgift1::createVector(int size)
{
	for (int i = 2; i < size; i++)  
	{
		ivec.push_back(i);
	}
}

void Uppgift1::deleteEvenNbrs()
{
	for (int j = 1; j < ivec.size(); j++)
	{
		if (((ivec[j] % 2) == 0))
		{
			ivec.erase(ivec.begin() + j);
		}
	}
}

void Uppgift1::deletePrimeMultiples()
{
	int index = 0;
	int primeNbr = ivec[index];
	while (primeNbr < ivec.size())
	{
		for (int k = 0; k < ivec.size(); k++)
		{
			if (((ivec[k] % primeNbr) == 0) && (ivec[k] > primeNbr))
			{
				ivec.erase(ivec.begin() + k);
			}
		}
		primeNbr = ivec[index++]; 
	}
}

void Uppgift1::printPrimeNbrs()
{
	for (int elem : ivec)
	{
		std::cout << elem << std::endl;
	}
}


