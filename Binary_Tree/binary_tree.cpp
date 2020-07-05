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
    BinaryTree(){};

private:
    Node* _head;
};

int main() {
    BinaryTree btobj;

    return 0;
}