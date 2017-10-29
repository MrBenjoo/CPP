#include "Uppgift3.h"
#include <algorithm>
#include <iostream>

using namespace std;

bool Even(int i) 
{
	return i % 2 == 0;
}

void Uppgift3::createContainer()
{
	cout << "\n\n**** Uppgift3 ****\n" << endl;
	for (int i = 0; i < 10; ++i)
	{
		ivec.push_back(i);
	}		
}

void Uppgift3::shuffleContainer()
{
	cout << "\n\nShuffle container\n\n" << endl;
	random_shuffle(ivec.begin(), ivec.end());
}

void Uppgift3::printContainer()
{
	cout << "Print Container\n" << endl;
	for (int elem : ivec)
	{
		cout << elem << " ";
	}
	cout << " " << endl;
}

//     13579 
void Uppgift3::removeEvenNumbers()
{
	cout << "\n\RemoveEvenNumbers\n" << endl;
	ivec.erase(remove_if(ivec.begin(), ivec.end(), Even), ivec.end());
}
