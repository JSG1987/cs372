#pragma once
template <typename T>
class CircularList : public list<T> {
private:
    using Node = typename list<T>::Node;

public:
    CircularList() : list<T>() {
        if (this->head != nullptr && this->tail != nullptr) {
            this->head->prev = this->tail;
            this->tail->next = this->head;
        }
    }

    void push_front(T data) override {
        list<T>::push_front(data);
        this->head->prev = this->tail;
        this->tail->next = this->head;
    }

    void push_back(T data) override {
        list<T>::push_back(data);
        this->head->prev = this->tail;
        this->tail->next = this->head;
    }

    void pop_front() override {
        list<T>::pop_front();
        this->head->prev = this->tail;
        this->tail->next = this->head;
    }

    void pop_back() override {
        list<T>::pop_back();
        this->head->prev = this->tail;
        this->tail->next = this->head;
    }

    void circle() {
        Node* current = this->head;
        while (current != nullptr) {
            // Perform the desired operation on the current node
            // ...
            current = current->next;
            if (current == this->head) {
                // Reached the end of the circular list
                break;
            }
        }
    }
};
