#include <iostream>
#include "Question1.h"

void printData(int data) {
    std::cout << data << " ";
}

int main() {
    // Create a List object
    List<int> myList;

    // Test push_front and push_back
    myList.push_front(1);
    myList.push_front(2);
    myList.push_back(3);
    myList.push_back(4);

    // Test traverse
    std::cout << "Traverse: ";
    myList.traverse(printData);
    std::cout << std::endl;

    // Test front and back
    std::cout << "Front: " << myList.front() << std::endl;
    std::cout << "Back: " << myList.back() << std::endl;

    // Test pop_front and pop_back
    myList.pop_front();
    myList.pop_back();

    // Test traverse after removal
    std::cout << "Traverse after removal: ";
    myList.traverse(printData);
    std::cout << std::endl;

    // Test empty
    std::cout << "Is empty? " << (myList.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
