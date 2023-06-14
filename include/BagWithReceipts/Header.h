#pragma once

//This is the template to question 3 with the added reciepts.  
using namespace std;
#include <vector>
#include<algorithm>
#include<stdexcept>
template <typename Thing>
class Bag {

private:
	std::vector<Thing> bagVector;
	struct Item 
	{
		Thing value;
		int receipt;
	};

public:
	ReceitpBag(): nextReceipt(1) {}

	int incert(const Thing& aThing)
	{
		int receipt = nextReceipt++;
		bagVector.push_back({ aThing, receipt });
	}

	Thing& remove(int receipt)
	{
		auto iter = std find_if(bagVector.begin(), bagVector.end(), [receipt](const Item item) {return item.reciept == receipt; });

		if (iter == bagVector.end())
		{
			throw std::runtime_error("This in not in the bag bro!")
		}
		Thing& removeItem = iter->value;
		bagVector.erase(iter);
		return removedItem;
	}

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
	int count(Thing& aThing)
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