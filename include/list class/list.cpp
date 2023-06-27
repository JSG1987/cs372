#include "fuctionsForList.h"
#include <iostream>

// A sample function to be used with the traverse() function
template<typename T>
void printData(T data) {
    std::cout << data << " ";
}

int main() {
    // Create an instance of List<int>
    list<int> myList;

    // Check if the list is empty
    if (myList.empty()) {
        std::cout << "List is empty" << std::endl;
    }

    // Add elements to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    // Get the front and back elements of the list
    std::cout << "Front: " << myList.front() << std::endl;
    std::cout << "Back: " << myList.back() << std::endl;

    
    myList.traverse(printData<int>);
    std::cout << std::endl;

    // Remove elements from the list
    myList.pop_front();
    myList.pop_back();

    // Check if the list is empty
    if (myList.empty()) {
        std::cout << "List is empty" << std::endl;
    }

    return 0;
}

