#include <iostream>
#include "poly2.h"

int main(int argc, char** argv)
{
	float value_x1 = 0;
	float value_x2 = 0;
	int rootNbr = 0;
	
	float coeff_1 = 0;
	float coeff_2 = 0;
	float coeff_3 = 0;
	
	std::cout << "Root-finding started..." << std::endl;

	while(std::cin >> coeff_1 >> coeff_2 >> coeff_3)
	{
		
		Poly2 poly2(coeff_1, coeff_2, coeff_3);
		poly2.findRoots(value_x1, value_x2, rootNbr);
		
		if (rootNbr == 1) 
		{
			std::cout << "x1 = " << ( value_x1 ) << std::endl;
			std::cout << "eval x1 = " << poly2.eval(value_x1) << std::endl;
			std::cout << " " << std::endl;
		}
		else if (rootNbr == 2)
		{
			std::cout << "x1 = " << value_x1 << std::endl;
			std::cout << "x2 = " << value_x2 << std::endl;
			std::cout << "eval x1 = " << poly2.eval(value_x1) << std::endl;
			std::cout << "eval x2 = " << poly2.eval(value_x2) << std::endl;
			std::cout << " " << std::endl;
		}
		else 
		{
			std::cout << "Roots = imaginary" << std::endl;
			std::cout << " " << std::endl;
		}
		
	}
	
	return 0;
}