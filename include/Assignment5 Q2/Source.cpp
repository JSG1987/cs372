#include <iostream>
#include"Question2.h"

void printNode(int data) {
    std::cout << data << " ";
}

int main() {
    Tree<int> myTree;
    myTree.insert(4);
    myTree.insert(2);
    myTree.insert(6);
    myTree.insert(1);
    myTree.insert(3);
    myTree.insert(5);
    myTree.insert(7);
   // myTree.remove(2);

    // Level traversal to print each node
    myTree.levelTraversal(myTree, printNode);
    std::cout << std::endl;

    int valueToSearch = 5;
    bool found = myTree.search(valueToSearch);
    std::cout << "Search for value " << valueToSearch << ": ";
    if (found) {
        std::cout << "Found" << std::endl;
    }
    else {
        std::cout << "Not Found" << std::endl;
    }

    int valueToRemove = 2;
    bool removed = myTree.remove(valueToRemove);
    std::cout << "Remove value " << valueToRemove << ": ";
    if (removed) {
        std::cout << "Removed successfully" << std::endl;
    }
    else {
        std::cout << "Not found or failed to remove" << std::endl;
    }
    Tree<int> prunedTree = myTree.prune(myTree);

    return 0;
}
