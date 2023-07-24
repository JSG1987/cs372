#pragma once
#include<memory>
#include<bitset>
template < typename T>
class List
{
private:
	struct Node
	{
		T data;
		std::shared_ptr<Node> prev;
		std::shared_ptr<Node> next;

	};
	std::shared_ptr<Node> head = nullptr;
	std::shared_ptr<Node> tail = nullptr;
	void setList() {
		auto newNode = std::make_shared<Node>();
		newNode->next = nullptr;
		newNode->prev = nullptr;
		head = newNode;
		tail = newNode;
	}
	void deleteListContents() {
		auto current = head;
		auto temp = std::shared_ptr<Node>(nullptr);
		while (current != nullptr) {
			temp = current->next;
			current.reset();
			current = temp;
		}
	}
public:
};

