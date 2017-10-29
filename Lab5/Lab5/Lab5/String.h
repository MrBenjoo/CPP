#include <iostream>
#ifndef STRING_H
#define STRING_H

class String {
	char *ptr_c_array;
	int length;
	int memorySize;

public:
	~String();
	String();
	String(const String& rhs);
	String(const char* cstr);
	String& operator=(const String& rhs);
	char& operator[](int i);
	const char& operator[](int i) const;
	int size() const;
	int capacity() const;
	void push_back(char c);
	friend bool operator==(const String& lhs, const String& rhs);
	friend std::ostream& operator<< (std::ostream& out, const String& rhs);

private:
	void Invariant();

	
};

#endif // STRING_h
