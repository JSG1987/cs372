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
    void deleteListContents();
    void setupList(); 
public:
    list();
    list(T newData);
    list(list& rhs); // copy constructor
    ~list();
    bool  empty();
    void push_front(T data);
    void push_back(T data);
    T front();
    T back();
    void pop_back();
    void pop_front();
    void traverse(void (*doIt)(T data));
};