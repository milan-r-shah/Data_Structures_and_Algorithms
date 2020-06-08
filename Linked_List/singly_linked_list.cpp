#include <iostream>

// Node class
class Node {
public:
    int data;
    Node* next;
};

// LinkedList class
class LinkedList {
public:
    LinkedList();
    void printLinkedList();

private:
    Node* n1;
    Node* n2;
    Node* n3;
    Node* n4;
};

// LinkedList constructor
LinkedList::LinkedList() {
    // Creating 4 nodes
    n1 = new Node();
    n2 = new Node();
    n3 = new Node();
    n4 = new Node();
    
    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = n4;
    
    n4->data = 40;
    n4->next = nullptr;
}

void LinkedList::printLinkedList() {
    Node* tempNode = n1;
    while(tempNode) {
        std::cout << tempNode->data << " --> ";
        tempNode = tempNode->next; 
    }
    std::cout << "nullptr\n";
}

int main() {
    LinkedList llobj;
    llobj.printLinkedList();

    return 0;
}