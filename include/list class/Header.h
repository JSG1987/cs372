#pragma once
#pragma once
#include"fuctionsForList.h"
template <typename Thing>
class ReceiptBag {
private:
    struct Item {
        Thing value;
        int receipt;
        typename list<Item>::Node* node; // Pointer to the corresponding node in the linked list *error c2248*
    };

    list<Item> bagList;
    int nextReceipt;

public:
    typename list<Item>::Node* node;
    ReceiptBag() : nextReceipt(1) {}

    int insert(const Thing& aThing) {
        int receipt = nextReceipt++;
        typename list<Item>::Node* newNode = new typename list<Item>::Node();
        newNode->data = { aThing, receipt, newNode };
        bagList.push_back(newNode);
        return receipt;
    }

    Thing& remove(int receipt) {
        typename list<Item>::Node* curr = bagList.front();
        while (curr != nullptr && curr->data.receipt != receipt) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            throw std::runtime_error("This is not in the bag!");
        }

        Thing& removeItem = curr->data.value;
        bagList.pop_node(curr);
        return removeItem;
    }

    int size() const {
        int count = 0;
        bagList.traverse([&](const typename list<Item>::Node* node) {
            count++;
            });
        return count;
    }

    bool isSameThing(const Thing& a, const Thing& b) const {
        return (a == b);
    }

    int count(const Thing& aThing) const {
        int count = 0;
        bagList.traverse([&](const typename list<Item>::Node* node) {
            if (isSameThing(node->data.value, aThing)) {
                count++;
            }
            });
        return count;
    }
};
