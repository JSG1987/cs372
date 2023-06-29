#include <iostream>
#include"newList.h"

int main() {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);

   
    myList.markNodeAsDeleted(myList.head->next); 
    myList.markNodeAsDeleted(myList.tail);       

    
    myList.traverse([](int data) 
        {
        std::cout << data << " ";
        });
    std::cout << std::endl;

  
    myList.deleteAllDeletedNodes();
   /* std::cout << myList.itemCount << std::endl;
    std::cout << myList.deletedCount << std::endl;*/

    myList.traverse([](int data) 
        {
        std::cout << data << " ";
        });
    std::cout << std::endl;

    std::cout << myList.itemCount << std::endl;
    std::cout << myList.deletedCount << std::endl;

    return 0;
}