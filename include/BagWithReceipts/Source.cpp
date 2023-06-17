#include<iostream>
#include"Bag.h"

int main() 
{
   ReceiptBag<std::string> bag;

 
   
    int receipt1 = bag.insert("Apple");
    int receipt2 = bag.insert("Banana");
    int receipt3 = bag.insert("Orange");

    std::cout << "Bag size: " << bag.size() << std::endl;

    std::string item1 = bag.remove(receipt2);
    std::cout << "Removed item: " << item1 << std::endl;

    std::cout << "Bag size after removal: " << bag.size() << std::endl;

    int receipt4 = bag.insert("Grape");
    int receipt5 = bag.insert("Apple");

    std::cout << "Count of 'Apple': " << bag.count("Apple") << std::endl;

    return 0;
}