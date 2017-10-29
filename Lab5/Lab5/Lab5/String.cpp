#include "String.h"
#include <iostream>
#include <cassert>

using namespace std;


// Deconstructor
String::~String()
{
	Invariant();
	delete[] ptr_c_array;
}

// Constructs an empty string, with a length of zero characters.
String::String()
{
	memorySize = 15; // capacity 15
	ptr_c_array = new char[memorySize]; 
	length = 0;
	Invariant();
}

// Constructs a copy of rhs.
String::String(const String & rhs)
{
	bool capacityChanged = false;
	while(rhs.size() >= capacity()) 
	{
		memorySize += 16;
		capacityChanged = true;
	}

	if (capacityChanged) {
		delete[] ptr_c_array;
		ptr_c_array = new char[memorySize];
	}

	for (int index = 0; index < rhs.size(); ++index)
	{
		//cout << "copying character: " << rhs.ptr_c_array[index] << " to index " << dest_index << endl;
		ptr_c_array[index] = rhs.ptr_c_array[index];
	}

	length = rhs.size();
	Invariant();
}

// Creates the string from c-string
String::String(const char * cstr)
{
	cout << "" << endl;
	cout << "*** Creating string from c-string ***" << endl;

	int cstr_size = 0;
	for (int i = 0; cstr[i] != '\0'; i++)
	{
		cstr_size++;
	}

	memorySize = 15;
	while (cstr_size >= memorySize)
	{
		memorySize += 16;
	}
	cout << "cstr_size = " << cstr_size << endl;
	cout << "capacity = " << capacity() << endl;


	ptr_c_array = new char[memorySize];

	for (int index = 0; index < cstr_size; index++)
	{
		cout << "copying character: " << cstr[index] << " to index " << index << endl;
		ptr_c_array[index] = cstr[index];
	}

	length = cstr_size;
	Invariant();
}

String & String::operator=(const String & rhs)
{
	cout << "assignment operator called" << endl;
	int rhsSize = rhs.size();
	cout << "rhsSize = " << rhsSize << endl;
	cout << "memorySize = " << memorySize << endl;

	bool capacityChanged = false;
	while (rhsSize >= memorySize)
	{
		cout << "rhsSize > memorySize" << endl;
		memorySize += 16;
		capacityChanged = true;
	}

	if (capacityChanged)
	{
		cout << "capacityChanged" << endl;
		delete[] ptr_c_array;
		ptr_c_array = new char[memorySize];
	}

	for (int index = 0; index < rhsSize; ++index) 
	{
		ptr_c_array[index] = rhs.ptr_c_array[index];
	}
	length = rhsSize;
	return *this;
}

char & String::operator[](int i)
{
	//cout << "Get character of string " << ptr_c_array[i] << endl;
	return ptr_c_array[i];
}

const char & String::operator[](int i) const
{
	//cout << "Get character of string const " << ptr_c_array[i] << endl;
	return ptr_c_array[i];
}


int String::size() const
{
	return this->length;
}

int String::capacity() const
{
	return this->memorySize;
}

void String::push_back(char c)
{
	cout << " " << endl;
	cout << "Pushback: " << c << endl;
	
	int currentSize = size();
	cout << "currentSize: " << currentSize << endl;
	cout << "capacity: " << capacity() << endl;
	char *temp_ptr = nullptr;
	if (currentSize >= capacity())
	{
		memorySize += 16;
		temp_ptr = new char[memorySize];
		for (int i = 0; i < size(); ++i) 
		{
			temp_ptr[i] = ptr_c_array[i];
		}
		delete[] ptr_c_array;
		ptr_c_array = new char[memorySize];	
	}
	else {
		temp_ptr = new char[memorySize];
		for (int i = 0; i < size(); ++i)
		{
			temp_ptr[i] = ptr_c_array[i];
		}
		delete[] ptr_c_array;
		ptr_c_array = new char[memorySize];
	}
	int dest_index = 0;
	for (int index = 0; index < currentSize; ++index) {
		cout << "copying character: " << ptr_c_array[index] << " to index " << dest_index << endl;
		ptr_c_array[dest_index++] = temp_ptr[index];
	}

	cout << "appending character: " << c << " to index " << dest_index << endl;
	ptr_c_array[dest_index++] = c;

	length = (currentSize + 1);
	cout << "new length= " << length << endl;
	delete[] temp_ptr;
	//cout << " " << endl;
	
}

void String::Invariant()
{
	assert(length >= 0);
	assert(ptr_c_array != nullptr);
	assert(memorySize > 0);
	assert(length <= memorySize);
}

bool operator==(const String & lhs, const String & rhs)
{
	if (lhs.length == rhs.length) 
	{
		int stringLength = lhs.length;
		int index = 0;
		while (index < stringLength) 
		{
			if (lhs.ptr_c_array[index] != rhs.ptr_c_array[index] ) {
				return false;
			}
			++index;
		}
		return true;

	}
	return false;

}

std::ostream & operator<<(std::ostream & out, const String & rhs)
{
	for (int i = 0; i < rhs.size(); ++i) 
	{
		out << rhs[i];
	}
	return out;
}