#pragma once
#include"fuctionsForList.h"

template<typename T>
void list<T>::deleteListContents()
{
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current->next;
        delete current;
        current = temp;
    }
}

template<typename T>
void list<T>::setupList()
{
    Node* newNode = new Node();
    newNode->next = nullptr;
    newNode->prev = nullptr;
    head = newNode;
    tail = newNode;
}

template<typename T>
list<T>::list()
{
    setupList();
}

template<typename T>
list<T>::list(T newData)
{
    setupList();
    head->data = newData;
}

template<typename T>
list<T>::list(list& rhs)
{
    deleteListContents();
    head = rhs.head;
    tail = rhs.tail;
}

template<typename T>
list<T>::~list()
{
    deleteListContents();
}

template<typename T>
void list<T>::push_front(T data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;
    head -> prev = newNode;
    head = newNode;
}

template<typename T>
void list<T>::push_back(T data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

template<typename T>
T list<T>::front()
{
    return head->data;
}

template<typename T>
T list<T>::back()
{
    return tail->data;
}

template<typename T>
bool list<T>::empty()
{
    return head == nullptr;
}

template<typename T>
void list<T> ::pop_front()
{
    Node* firstNode = head;
    head = head ->next;
    head ->prev = nullptr;
    delete firstNode;
}

template<typename T>
void list<T> ::pop_back()
{    
        Node* lastNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete lastNode;


}

template<typename T>
inline void list<T>::traverse(void(*doIt)(T data))
{
    Node* current = head->next;
    while (current != tail)
    {
        doIt(current->data);
        current = current->next;
    }

}


