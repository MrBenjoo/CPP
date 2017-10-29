#include <iostream>
#include "Client.h"
#include "OperationAdd.h"
#include "OperationMultiply.h"
#include "OperationSubtract.h"

using namespace std;

int main() 
{
	Client *client = new Client();

	// OperationAdd
	OperationAdd *operationAdd = new OperationAdd();
	client->setStrategy(operationAdd);
	client->compute(10, 10);

	// OperationMultiply
	OperationMultiply *operationMultiply = new OperationMultiply();
	client->setStrategy(operationMultiply);
	client->compute(10, 10);

	// OperationSubtract
	OperationSubtract *operationSubtract = new OperationSubtract();
	client->setStrategy(operationSubtract);
	client->compute(20, 10);
	
	return 0;

}