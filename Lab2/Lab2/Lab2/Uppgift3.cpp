
#include <iostream>
#include "uppgift3.h"

using namespace std;

void Uppgift3::runUppgift3()
{
	string inputString;
	const char before = 'j';
	char * const after = "eje";

	cout << "\nUppgift3\nEnter a string: ";
	getline(cin, inputString);

	int counts = beforeCounts(inputString, before); // Count number of instances of 'before' in inputString

	if (counts != 0) { // replace characters
		inputSize = inputString.size() + (counts*(strlen(after)) - counts); // old size + (the number of characters to replace all 'before' with - 'before' characters)

		char* input = new char[inputSize + 1]; // +1 for '\0'
		strcpy_s(input, inputSize + 1, inputString.c_str());

		substitute3(input, before, after);

		std::cout << "After: " << std::string(input) << std::endl;
		delete[] input;
	}
	else 
	{
		cout << "no characters to replace" << endl;
	}
	
}

char * Uppgift3::substitute3(char * const input, const char before, char * const after)
{
	char* tmp = new char[inputSize];

	// Replace all instances of variable before with variable after
	for (int i = 0, t = 0; i < strlen(input); i++)
	{
		if (before == input[i])
		{
			// Traverse variable after
			for (int a = 0; a < strlen(after); a++)
			{
				tmp[t++] = after[a];
			}
				
		}
		else  
		{
			tmp[t++] = input[i];
		}
			
	}

	// Copy over contents from tmp to input
	for (int i = 0; i < inputSize; i++)
	{
		input[i] = tmp[i];
	}
	input[inputSize] = '\0';

	delete[] tmp;

	return input;
}

int Uppgift3::beforeCounts(std::string input, const char before)
{
	int counts = 0;
	for (int i = 0; i != input.size(); i++)
	{
		if (input[i] == before)
		{
			counts++;
		}
	}
	return counts;
}


