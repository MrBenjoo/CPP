#ifndef CLIENT_H
#define CLIENT_H

#include "Strategy.h"

class Client {
private:
	Strategy *strategy;

public:
	void setStrategy(Strategy* strategy);
	void compute(int nbr1, int nbr2);
};

#endif
