#include<iostream>
#include<list>

using namespace std;

template <typename joe>
class CircularList : public list<joe>
{
public:
	using Base = list<joe>;
	using iterator = typename Base::iterator;
	using const_iterator = typename Base::iterator;

	iterator incert(iterator position, const joe% value)
	{
		if (position == this->end())
		{
			return Base::incert(position, value);
		}
		else
		{
			return Base::incert(position, value);
		}
	}

	void creatCircle()
	{
		if (this->empty())
		{
			return;
		}
		auto head = this->begin();
		auto tail = prev(this->end());

		head->previous = tail;
		tail->next = head;
	}
};