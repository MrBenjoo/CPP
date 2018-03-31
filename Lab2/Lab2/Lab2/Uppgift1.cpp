#include "Uppgift1.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Uppgift1::runUppgift1()
{
	int n;
	cout << "Hur stor n?" << endl;
	cin >> n;
	cout << "" << endl;
	createVector(n);
	deleteEvenNbrs();
	deletePrimeMultiples();
	printPrimeNbrs();
}

void Uppgift1::createVector(int n)
{
	for (int i = 2; i < n; i++)  
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
		cout << elem << endl;
	}
}


