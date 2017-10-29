#include "Uppgift1c.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Uppgift1c::createVector() {
	
	for (int i = 0; i < 10; ++i) {
		int r = rand() % 100 + 1;
		ivec.push_back(r);
	}

	cout << "\n\n\n**** Uppgift1c ****\nPrinting all the elements in the vector..." << endl;
	printElements();

	cout << "\n\nSorting elements in descending order.." << endl;
	sort(ivec.rbegin(), ivec.rend());

	cout << "\nPrinting all the elements in the vector..." << endl;
	printElements();
}

void Uppgift1c::printElements()
{
	for (int i = 0; i < ivec.size(); ++i)
	{
		cout << ivec[i] << " ";
	}
}
