#pragma once
#include<memory>
#include<iostream>

template <typename T>
class List
{
private:
    class Node {
    public:
        T data;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
    };

    std::shared_ptr<Node> head = nullptr;
    std::shared_ptr<Node> tail = nullptr;

public:
    List() = default;
    List(T newData) {
        auto newNode = std::make_shared<Node>();
        newNode->data = newData;
        head = newNode;
        tail = newNode;
    }

    bool empty() const {
        return (head == nullptr);
    }

    void push_front(T data) {
        if (empty()) {
            auto newNode = std::make_shared<Node>();
            newNode->data = data;
            head = newNode;
            tail = newNode;
        }
        else {
            auto newNode = std::make_shared<Node>();
            newNode->data = data;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T data) {
        if (empty()) {
            auto newNode = std::make_shared<Node>();
            newNode->data = data;
            head = newNode;
            tail = newNode;
        }
        else {
            auto newNode = std::make_shared<Node>();
            newNode->data = data;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    T front() const {
        return head->data;
    }

    T back() const {
        return tail->data;
    }

    void pop_front() {
        if (empty()) {
            return;
        }
        else if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
    }

    void pop_back() {
        if (empty()) {
            return;
        }
        else if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
    }

    void traverse(void (*doIt)(T data)) {
        std::shared_ptr<Node> current = head;
        while (current != nullptr) {
            doIt(current->data);
            current = current->next;
        }
    }
};
