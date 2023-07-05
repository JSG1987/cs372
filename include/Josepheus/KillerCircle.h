#pragma once
#include <cmath>

template <typename T>
class KillerCircle
{
private:
	class Node
	{
	public:
		T data;
		Node* prev;
		Node* next;
		bool :: deleted;
		Node() : prev(nullptr), next(nullptr), deleted(false) {}
	};

	Node* head;
	Node* tail;
	int people;
	int deadpeople;

public:
	KillerCircle() : head(nullptr), tail(nullptr), people(0), deadpeople(0) {}

	~KillerCircle() {
		clearCircle();
	}

	void createCircle(int n) {
		for (int i = 0; i < n; i++) {
			Node* newNode = new Node();
			newNode->data = i + 1;

			if (head == nullptr) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}

			tail->next = head;
			head->prev = tail;

			people++;
		}
	}

	void eliminatePeople(int m) {
		Node* current = head;

		while (people > 1) {
			int count = 0;
			while (count < m - 1) {
				if (!current->deleted) {
					count++;
				}
				current = current->next;
			}

			while (current->deleted) {
				current = current->next;
			}

			current->deleted = true;
			deadpeople++;
			people--;

			current = current->next;
		}
	}

	T getWinningPosition() const {
		Node* current = head;
		while (current->deleted) {
			current = current->next;
		}
		return current->data;
	}

private:
	void clearCircle() {
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
		head = nullptr;
		tail = nullptr;
		people = 0;
		deadpeople = 0;
	}
};
