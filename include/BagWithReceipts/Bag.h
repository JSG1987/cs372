#pragma once

//This is the template to question 3 with the added reciepts.  
using namespace std;
#include <vector>
#include<algorithm>
#include<stdexcept>
template <typename Thing>
class ReceiptBag {

private:
	
	struct Item 
	{
		Thing value;
		int receipt;
	};


	std:: vector<Item> bagVector;
	int nextReceipt;

public:
	 ReceiptBag() : nextReceipt(1) {}

	 int insert(const Thing& aThing)
	 
	 {
		 int receipt = nextReceipt++;
		 bagVector.push_back({ aThing, receipt });
		 return receipt;
	 }


	Thing& remove(int receipt)
	{
		auto iter = std::find_if(bagVector.begin(), bagVector.end(),
			[receipt](const Item& item) { return item.receipt == receipt; });

		if (iter == bagVector.end())
		{
			throw std::runtime_error("This in not in the bag bro!");
		}

		Thing& removeItem = iter->value;
		bagVector.erase(iter);
		return removeItem;
	}

	/*Bag() = default;*/

	//void insert(Thing aThing)
	//{
	//	bagVector.push_back(aThing);
	//	//cout << aThing << endl;
	//}

	int size() const {
		return bagVector.size();
	}

	bool isSameThing(const Thing& a, const Thing& b) const {
		return (a == b);
	}

	int count(const Thing& aThing) const {
		int count = 0;
		for (const auto& item : bagVector) {
			if (isSameThing(item.value, aThing)) {
				count++;
			}
		}
		return count;
	}
};