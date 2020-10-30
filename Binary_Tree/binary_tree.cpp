#include <iostream>

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node() : data{0}, left{nullptr}, right{nullptr} {};
    Node(int data) : data{data}, left{nullptr}, right{nullptr} {};
    Node(int data, Node* left, Node* right) : data{data}, left{left}, right{right} {};
};

// Binary Tree class
class BinaryTree {
public:
    BinaryTree();
    void printBinaryTreePreOrderTraversal(Node* node) const;
    void printBinaryTreeInOrderTraversal(Node* node) const;
    void printBinaryTreePostOrderTraversal(Node* node) const;
    Node* getHead();

private:
    Node* _head;
    Node* _left;
    Node* _right;
    Node* _left_left;
    Node* _left_right;
    Node* _right_left;
    Node* _right_right;
};

// BinaryTree class constructor
BinaryTree::BinaryTree() {
    _left_left = new Node(4);
    _left_right = new Node(5);

    _right_left = new Node(6);
    _right_right = new Node(7);

    _left = new Node(2, _left_left, _left_right);
    _right = new Node(3, _right_left, _right_right);

    _head = new Node(1, _left, _right);
}

// BinaryTree class method for prining the tree using Pre-Order Traversal
void BinaryTree::printBinaryTreePreOrderTraversal(Node* node) const {
    if (node == nullptr)
        return;

    std::cout << node->data << " ";

    printBinaryTreePreOrderTraversal(node->left);
    printBinaryTreePreOrderTraversal(node->right);
}

// BinaryTree class method for prining the tree using In-Order Traversal
void BinaryTree::printBinaryTreeInOrderTraversal(Node* node) const {
    if (node == nullptr)
        return;

    printBinaryTreeInOrderTraversal(node->left);
    std::cout << node->data << " ";
    printBinaryTreeInOrderTraversal(node->right);
}

// BinaryTree class method for prining the tree using Post-Order Traversal
void BinaryTree::printBinaryTreePostOrderTraversal(Node* node) const {
    if (node == nullptr)
        return;

    printBinaryTreePostOrderTraversal(node->left);
    printBinaryTreePostOrderTraversal(node->right);
    std::cout << node->data << " ";
}

// BinaryTree class method for returning the head of the current tree
Node* BinaryTree::getHead() {
    return _head;
}

int main() {
    BinaryTree binary_tree;
    std::cout << "Pre-Order Traversal:\t";
    binary_tree.printBinaryTreePreOrderTraversal(binary_tree.getHead());
    std::cout << "\n";
    std::cout << "In-Order Traversal:\t";
    binary_tree.printBinaryTreeInOrderTraversal(binary_tree.getHead());
    std::cout << "\n";
    std::cout << "Post-Order Traversal:\t";
    binary_tree.printBinaryTreePostOrderTraversal(binary_tree.getHead());
    std::cout << "\n";

    return 0;
}