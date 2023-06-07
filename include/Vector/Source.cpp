#include<iostream>
#include"Bag.h"


int main()
{
	std::cout << "Bag test" << std::endl;
	Bag<float>* testptr = new Bag<float>();
	testptr->insert(32.65);
	float result = testptr->pop();
	std::cout << result << std::endl; 
	Bag<int>* newTestPtr = new Bag<int>();
	newTestPtr->insert(75);
	int result2 = newTestPtr->isSameThing(75,32);
	std::cout << result2 << std::endl;

	return 0;
}