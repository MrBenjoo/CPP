#include <iostream>
#include "Uppgift1d.h"
#include <algorithm>

using namespace std;


bool Greater(int x, int y)
{
	return x>y;
}

void Uppgift1d::sortDesc() {
	arraySize = 10;
	ptr_array = new int[arraySize]();

	for (int i = 0; i < arraySize; ++i)
	{
		int randomNbr = rand() % 100;
		ptr_array[i] = randomNbr;
	}
	
	cout << "\n\n**** Uppgift1d ****\n\nPrinting all the elements in the array..." << endl;
	printElements();

	cout << "\n\nSorting elements in desc order." << endl;
	sort(ptr_array, ptr_array + 9, Greater);

	cout << "\nPrinting all the elements in the array..." << endl;
	printElements();

	delete ptr_array;
	ptr_array = nullptr;
}

void Uppgift1d::printElements()
{
	for (int i = 0; i != arraySize; ++i)
	{
		cout << ptr_array[i] << " ";
	}
}


