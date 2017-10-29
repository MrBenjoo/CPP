#include <iostream>
#include "Uppgift1b.h"
#include <algorithm>

using namespace std;

void Uppgift1b::createCArray() {
	arraySize = 10;
	ptr_array = new int[arraySize]();
	for (int i = 0; i != arraySize; ++i) 
	{
		int randomNbr = rand() % 100;
		ptr_array[i] = randomNbr;
	}

	cout << "**** Uppgift1b ****\n\nPrinting all the elements in the array..." << endl;
	printElements(); 

	cout << "\n\nSorting the elements...\n" << endl;
	sort(ptr_array, ptr_array+9);

	cout << "Printing all the elements in the array...\n" << endl;
	printElements();

	delete ptr_array;
	ptr_array = nullptr;
}

void Uppgift1b::printElements()
{
	for (int i = 0; i != arraySize; ++i)
	{
		cout << ptr_array[i] << " ";
	}
}

