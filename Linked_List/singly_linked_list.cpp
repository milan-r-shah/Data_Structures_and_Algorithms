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
    void addNodeAtStart(int data = 0);
    void addNodeAtEnd(int data = 0);
    void addNodeAtPosFromStart(int index, int data = 0);

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

// LinkedList class method for adding a Node at the Start
void LinkedList::addNodeAtStart(int data) {
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

// LinkedList class method for adding a Node at a given Position from the Start
// indexing starts from 0 i.e. for 0th index, this method will add a Node at the start of linked list
void LinkedList::addNodeAtPosFromStart(int index, int data) {
    if (index == 0) {
        addNodeAtStart(data);
        return;
    }

    Node* newNode = new Node(data);
    Node* tempNode = head;
    for (int i = 0; i < index - 1; ++i) {
        if (tempNode->next)
            tempNode = tempNode->next;
        else {
            std::cout << "Index out of range!\n";
            return;
        }
    }

    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

int main() {
    LinkedList llobj;
    llobj.printLinkedList();
    // llobj.addNodeAtStart(13);
    // llobj.printLinkedList();
    // llobj.addNodeAtEnd(5);
    // llobj.printLinkedList();
    llobj.addNodeAtPosFromStart(4, 31);
    llobj.printLinkedList();

    return 0;
}