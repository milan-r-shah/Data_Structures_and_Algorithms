#include <iostream>

// Node class
class Node {
public:
    int data;
    Node* next;
    Node() : data{0} {};
    Node(int data) : data{data} {}
};

// LinkedList class
class LinkedList {
public:
    LinkedList();
    void printLinkedList() const;
    void addNodeAtBeginning(int data = 0);
    void addNodeAtEnd(int data = 0);

private:
    Node* head;
    Node* n2;
    Node* n3;
    Node* n4;
};

// LinkedList constructor
LinkedList::LinkedList() {
    // Creating 4 nodes
    head = new Node();
    n2 = new Node();
    n3 = new Node();
    n4 = new Node();

    head->data = 10;
    head->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = n4;

    n4->data = 40;
    n4->next = nullptr;
}

// LinkedList class method for printing LinkedList
void LinkedList::printLinkedList() const {
    Node* tempNode = head;
    while (tempNode) {
        std::cout << tempNode->data << " --> ";
        tempNode = tempNode->next;
    }
    std::cout << "nullptr\n";
}

// LinkedList class method for adding a Node at the beginning
void LinkedList::addNodeAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// LinkedList class method for adding a Node at the end
void LinkedList::addNodeAtEnd(int data) {
    Node* newNode = new Node(data);

    // creating a tempNode which will iterate through all the nodes
    Node* tempNode = head;
    while (tempNode->next) {
        tempNode = tempNode->next;
    }

    tempNode->next = newNode;
    newNode->next = nullptr;
}

int main() {
    LinkedList llobj;
    llobj.printLinkedList();
    llobj.addNodeAtBeginning(13);
    llobj.printLinkedList();
    llobj.addNodeAtEnd(5);
    llobj.printLinkedList();

    return 0;
}