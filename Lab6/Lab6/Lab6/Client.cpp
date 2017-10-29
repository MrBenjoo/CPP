#include "Client.h"
#include <iostream>

using namespace std;

void Client::setStrategy(Strategy * mStrat)
{
	this->strategy = mStrat;
}

void Client::compute(int nbr1, int nbr2)
{
	strategy->compute(nbr1, nbr2);
}
