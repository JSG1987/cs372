#pragma once
//This is the template to question 2 and 3 
using namespace std;
#include <vector>

template <typename Thing>
class Bag {

private :
	std::vector<Thing> bagVector;

public:
	 
	Bag() = default;

	void insert(Thing aThing)
	{
		bagVector.push_back(aThing);
		//cout << aThing << endl;
	}

	Thing& pop()
	{
		Thing aValue = bagVector.back();
		bagVector.pop_back();
		return aValue;
	}
	int size()
	{
		bagVector.size();
	}
	bool isSameThing(Thing a, Thing b)
	{
		return(a == b);
	}
	int count(Thing &aThing)
	{
		count = 0;
		for (auto anotherThing : bagVector)
		{
			if (anotherThing == aThing)
			{
				count++;
			}
		}
		return count;
	}
};