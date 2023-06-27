#pragma once
#include<iostream>
template <typename T>
class list {
private:
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    void deleteListContents()
    {

        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }

    }
    void setupList()
    {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
public:
    list()
    {
            setupList();   
    }
    list(T newData)
    {
        setupList();
        head->data = newData;
    }
    list(list& rhs)
    {
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }
    ~list()
    {
        deleteListContents();
    }
    bool  empty()
    {
        return head == nullptr;
    }
    void push_front(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }
    void push_back(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    T front()
    {
        return head->data;
    }
    T back()
    {
        return tail->data;
    }
    void pop_back()
    {
        Node* lastNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete lastNode;


    }
    void pop_front()
    {
        Node* firstNode = head;
        head = head->next;
        head->prev = nullptr;
        delete firstNode;
    }

    void traverse(void (*doIt)(T data))
    {
        Node* current = head->next;
        while (current != tail)
        {
            doIt(current->data);
            current = current->next;
        }

    }
};