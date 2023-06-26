#include <iostream>
#include "Header.h"

int main() {
    ReceiptBag<int> bag;

    int receipt1 = bag.insert(10);
    int receipt2 = bag.insert(20);
    int receipt3 = bag.insert(10);

    std::cout << "Size: " << bag.size() << std::endl; // Output: Size: 3

    bag.remove(receipt2);

    std::cout << "Size: " << bag.size() << std::endl; // Output: Size: 2

    int count = bag.count(10);
    std::cout << "Count: " << count << std::endl; // Output: Count: 2

    return 0;
}
