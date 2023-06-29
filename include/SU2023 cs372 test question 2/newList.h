#pragma once
template <typename T>
class List
{
public:
	class Node {
	public:
		T  data;
		Node* prev;
		Node* next;
		bool deleted;
		Node() : prev(nullptr), next(nullptr), deleted(false) {}
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	int itemCount = 0;
	int deletedCount = 0;

	void setupList() {
		Node* newNode = new Node();
		newNode->next = nullptr;
		newNode->prev = nullptr;
		head = newNode;
		tail = newNode;
	}
	void deleteListContents() {
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->next;
			delete current;
			current = temp;
		}
	}
	void deleteMarkedNodes() 
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) 
		{
		if (current->deleted) 
		{
		temp = current->next;
			if (current == head) 
			{
			head = current->next;
			if (head)
			head->prev = nullptr;
			}
			else if (current == tail) 
			{
			tail = current->prev;
			if (tail)
			tail->next = nullptr;
			}
			else 
			{
			current->prev->next = current->next;
			current->next->prev = current->prev;
			}
			delete current;
			current = temp;
			deletedCount--;
			}
			else 
			{	
				current = current->next;
			}
		}
	}

public:
	List() = default;
	List(T newData) {
		setupList();
		head->data = newData;
		itemCount = 1;
	}
	List(List& rhs) { // copy constructor
		deleteListContents();
		setupList();
		Node* current = rhs.head;
		while (current != nullptr)
		{
			if (!current->deleted)
			{
				push_back(current->data);
			}
			current = current->next;
		}
		head = rhs.head;
		tail = rhs.tail;
	}
	~List() {// And a destructor
		deleteListContents();
	}
	bool  empty() {
		return (head == nullptr);
	}
	void push_front(T data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->deleted = false;
		newNode->next = head;
		if (head)
		{
			head->prev = newNode;

			head = newNode;
		}
		if (tail == nullptr)
		{
			tail = newNode;
			itemCount++;
		}
	}
	void push_back(T data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->deleted = false;
		newNode->prev = tail;
		if (tail)
			tail->next = newNode;
		tail = newNode;
		if (head == nullptr)
		{
			head = newNode;
			itemCount++;
		}
	}
	T front() {
		return (head->data);
	}
	T back() {
		return (tail->data);
	}
	void pop_back() {
		Node* lastNode = tail;
		tail = tail.prev;
		tail.next = nullptr;
		delete lastNode;
	}
	void pop_front() {
		Node* firstNode = head;
		head = head.next;
		head.prev = nullptr;
		delete firstNode;
	}
	void traverse(void (*doIt)(T data)) {
		Node* current = head;
		while (current != nullptr) {
			if (!current->deleted)
			{
				doIt(current->data);
				current = current->next;
			}
		}
	}
	void markNodeAsDeleted(Node* node) 
	{
		if (node && !node->deleted)
		{
			node->deleted = true;
			deletedCount++;
			if (deletedCount == itemCount)
				deleteMarkedNodes();
		}
	}
	void deleteAllDeletedNodes() 
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) 
		{
			if (current->deleted) 
			{
				temp = current->next;
				if (current == head) 
				{
					head = current->next;
					if (head)
						head->prev = nullptr;
				}
				else if (current == tail) 
				{
					tail = current->prev;
					if (tail)
						tail->next = nullptr;
				}
				else 
				{
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}
				delete current;
				current = temp;
				deletedCount--;
			}
			else 
			{
				current = current->next;
			}
		}
	}
};



