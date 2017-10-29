#include "poly2.h"
#include <cmath>
#include <iostream>

float x_square;
float discriminant;

Poly2::Poly2(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

float Poly2::eval(float x)
{
    
    x_square = pow(x, 2);
    
	return (a*x_square) + (b*x) + c;

}

void Poly2::findRoots(float &x1, float &x2, int &rootNbr)
{
    discriminant = pow(b, 2.0) - (4.0 * a * c);
	
	if(discriminant == 0)
	{
		rootNbr = 1;
		x1 = (-b) / (2.0 * a);
	}
	
	else if (discriminant > 0)
	{
		rootNbr = 2;
		x1 = (-b + sqrt(discriminant)) / (2.0 * a);
		x2 = (-b - sqrt(discriminant)) / (2.0 * a);
	}
	
	else
	{
		rootNbr = 0;
	}

} 