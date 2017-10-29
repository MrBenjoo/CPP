#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "Uppgift1a.h"

using namespace std;

void Uppgift1a::createVector() {

	for (int i = 0; i < 10; ++i) 
	{
		int r = rand() % 100 + 1;
		ivec.push_back(r);
	}

	cout << "**** Uppgift1a ****\n\nPrinting all the elements in the vector..." << endl;
	printElements();

	cout << "\n\nSorting elements\n" << endl;
	sort(ivec.begin(), ivec.end());

	cout << "Printing all the elements in the vector..." << endl;
	printElements();
	cout << "\n\n" << endl;
}

void Uppgift1a::printElements()
{
	for (int i = 0; i < ivec.size(); ++i) 
	{
		cout << ivec[i] << " ";
	}
}

