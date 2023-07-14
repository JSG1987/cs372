#pragma once
#include <memory>
#include<functional>
#include<queue>

template <typename T>
class Tree
{
private:
    class Node {
    public:
        T data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(const T& newData) : data(newData), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

public:
    Tree() : root(nullptr) {}

    void insert(const T& value) {
        if (root == nullptr) {
            root = std::make_shared<Node>(value);
        }
        else {
            insertNode(root, value);
        }
    }

    bool search(const T& value) const {
        return searchNode(root, value);
    }

    bool remove(const T& value) {
        return removeNode(root, value);
    }

    template<typename T, typename Func> //Question 4
    void levelTraversal(const Tree<T>& tree, Func&& doIt) {
        std::queue<std::shared_ptr<typename Tree<T>::Node>> nodeQueue;
        if (tree.root != nullptr) {
            nodeQueue.push(tree.root);
        }

        int level = 0;
        while (!nodeQueue.empty()) {
            int currentLevelSize = nodeQueue.size();
            for (int i = 0; i < currentLevelSize; ++i) {
                std::shared_ptr<typename Tree<T>::Node> current = nodeQueue.front();
                nodeQueue.pop();
                doIt(current->data);

                if (current->left != nullptr) {
                    nodeQueue.push(current->left);
                }
                if (current->right != nullptr) {
                    nodeQueue.push(current->right);
                }
            }
            ++level;
        }
    }
    //Question 5
    template<typename T>
    void printTree(const std::shared_ptr<typename Tree<T>::Node>& node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        printTree<T>(node->left);
        printTree<T>(node->right);
    }
    template<typename T>
    std::shared_ptr<typename Tree<T>::Node> pruneNode(const std::shared_ptr<typename Tree<T>::Node>& node) {
        if (node == nullptr) {
            return nullptr;
        }
        else if (node->left == nullptr && node->right == nullptr) {
            return nullptr;
        }
        else {
            node->left = pruneNode<T>(node->left);
            node->right = pruneNode<T>(node->right);
            return node;
        }
    }

    template<typename T>
    Tree<T> prune(const Tree<T>& tree) {
        Tree<T> prunedTree;
        prunedTree.root = pruneNode<T>(tree.root);

        std::cout << "Pruned Tree: ";
        printTree<T>(prunedTree.root);
        std::cout << std::endl;

        return prunedTree;
    }


    

private:
    void insertNode(std::shared_ptr<Node>& node, const T& value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = std::make_shared<Node>(value);
            }
            else {
                insertNode(node->left, value);
            }
        }
        else if (value > node->data) {
            if (node->right == nullptr) {
                node->right = std::make_shared<Node>(value);
            }
            else {
                insertNode(node->right, value);
            }
        }
    }

    bool searchNode(const std::shared_ptr<Node>& node, const T& value) const {
        if (node == nullptr) {
            return false;
        }
        else if (value == node->data) {
            return true;
        }
        else if (value < node->data) {
            return searchNode(node->left, value);
        }
        else {
            return searchNode(node->right, value);
        }
    }
    //Question 3
    bool removeNode(std::shared_ptr<Node>& node, const T& value) {
        if (node == nullptr) {
            return false;
        }
        else if (value < node->data) {
            return removeNode(node->left, value);
        }
        else if (value > node->data) {
            return removeNode(node->right, value);
        }
        else {
           
            if (node->left == nullptr && node->right == nullptr) {
                
                node = nullptr;
            }
            else if (node->left == nullptr) {
                
                node = node->right;
            }
            else if (node->right == nullptr) {
              
                node = node->left;
            }
            else {
               
                std::shared_ptr<Node> baby = getMinValueNode(node->right);
                node->data = baby->data;
                removeNode(node->right, baby->data);
            }
            return true;
        }
    }
    


    std::shared_ptr<Node> getMinValueNode(const std::shared_ptr<Node>& node) const {
        std::shared_ptr<Node> current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

};


