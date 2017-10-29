#ifndef UPPGIFT3_H
#define UPPGIFT3_H

#include <string>

class Uppgift3 {
	int inputSize;
	char* substitute3(char* const input, const char before, char* const after);
	int beforeCounts(std::string, const char before);

public:
	void runUppgift3();
	

};

#endif // !UPPGIFT3_H

