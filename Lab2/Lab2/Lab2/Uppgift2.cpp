#include "Uppgift2.h"
#include <iostream>

using namespace std;

void Uppgift2::Substitue2(std::string & iostring, const std::string & before, const std::string & after)
{
	int index = 0;
	bool noMatch = false;

	cout << "\nString before replace: " << iostring << endl;

	while (!noMatch)
	{
		index = iostring.find(before, index); // Letar i input och returnerar indexet till den eftersökta strängen
		if (index > 0) { // find metoden hittade strängen
			iostring.replace(index, before.size(), after); 
			index += after.size();
		}
		else { // index < 0 (find metoden hittade inte strängen)
			noMatch = true;
		}
	}

	cout << "String after replace: " << iostring << endl;
}

void Uppgift2::runUppgift2()
{
	string io_string("");
	cout << "Input string:" << endl;
	getline(cin, io_string);

	string before("");
	cout << "\nwhich characters needs to be replaced?" << endl;
	getline(cin, before);

	string after("");
	cout << "\nwhich are the characters you want to replace it with?" << endl;
	getline(cin, after);

	Substitue2(io_string, before, after);
}
