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
    void addNodeAtPosFromEnd(int index, int data = 0);

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
    // head->next = nullptr;
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
// Here, indexing starts from 1. So, for index = 1, this method will add a Node
// at the start of linked list i.e. it would become a 'head'
void LinkedList::addNodeAtPosFromStart(int index, int data) {
    if (index < 1) {
        std::cout << "Invalid index\n";
        return;
    }

    Node* newNode = new Node(data);

    if (index == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* tempNode = head;
    for (int i = 1; i < index - 1; ++i) {
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

// LinkedList class method for adding a Node at a given Position from the End
// Indexing starts from 1 i.e. for index = 1, this method will add a Node at the End
// for index = 2, the method will add a Node at the second last place from the End
void LinkedList::addNodeAtPosFromEnd(int index, int data) {
    if (index < 1) {
        std::cout << "Invalid index\n";
        return;
    }

    // Node* newNode = new Node(data);
    // Node* ptr1 = head;
    // Node* ptr2 = head;

    // for (int i = 1; i < index; ++i) {
    //     ptr1 = ptr1->next;
    // }

    // std::cout << ptr2->data << " | " << ptr1->data << "\n";

    // // if(ptr1->next == nullptr) {
    // //     addNodeAtStart(data);
    // // }

    // while(ptr1->next) {
    //     ptr1 = ptr1->next;
    //     ptr2 = ptr2->next;
    // }

    // std::cout << ptr2->data << " | " << ptr1->data << "\n";

    // newNode->next = ptr2->next;
    // ptr2->next = newNode;

    Node* newNode = new Node(data);
    newNode->next = head;
    Node* ptr1 = newNode;
    Node* ptr2 = newNode;

    // the first pointer would be iterate through Nodes based on the index
    // So, later on, when the first one reaches at the End, the 
    // second pointer reaches at the required index, if valid
    for (int i = 1; i < index; ++i) {
        if (ptr1->next)
            ptr1 = ptr1->next;
        else {
            std::cout << "Index out of range!\n";
            return;
        }
    }

    while (ptr1->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // to check the place where a Node should be added is the 'Start' or not
    if (ptr2 != newNode) {
        newNode->next = ptr2->next;
        ptr2->next = newNode;
    } else {
        ptr2->next = head;
        head = ptr2;
    }
}

int main() {
    LinkedList llobj;
    llobj.printLinkedList();
    llobj.addNodeAtStart(13);
    llobj.printLinkedList();
    llobj.addNodeAtEnd(5);
    llobj.printLinkedList();
    llobj.addNodeAtPosFromStart(3, 31);
    llobj.printLinkedList();
    llobj.addNodeAtPosFromEnd(2, 27);
    llobj.printLinkedList();

    return 0;
}