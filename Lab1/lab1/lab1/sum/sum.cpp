#include <iostream>

float val = 0;
float sum = 0;

int main()
{
	while(std::cin >> val)
	{
		sum += val;
	}
	std::cout << sum;
	return 0;
}