#include <iostream>

// Node class
class Node {
public:
    int data;
    Node* next;
    Node() : data{0}, next{nullptr} {};
    Node(int data) : data{data}, next{nullptr} {}
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
    void reverseLinkedList();

private:
    Node* _head;
    Node* _n2;
    Node* _n3;
    Node* _n4;
};

// LinkedList constructor
LinkedList::LinkedList() {
    // Creating 4 nodes
    _head = new Node();
    _n2 = new Node();
    _n3 = new Node();
    _n4 = new Node();

    _head->data = 10;
    _head->next = _n2;

    _n2->data = 20;
    _n2->next = _n3;

    _n3->data = 30;
    _n3->next = _n4;

    _n4->data = 40;
    _n4->next = nullptr;
    // _head = nullptr;
}

// LinkedList class method for printing LinkedList
void LinkedList::printLinkedList() const {
    if (_head == nullptr) {
        std::cout << "Empty linked list!\n";
        return;
    }

    Node* curr = _head;

    while (curr) {
        std::cout << curr->data << " --> ";
        curr = curr->next;
    }

    std::cout << "nullptr\n";
}

// LinkedList class method for adding a Node at the Start
void LinkedList::addNodeAtStart(int data) {
    Node* new_node = new Node(data);
    new_node->next = _head;
    _head = new_node;
}

// LinkedList class method for adding a Node at the end
void LinkedList::addNodeAtEnd(int data) {
    if (_head == nullptr) {
        _head = new Node(data);
    } else {
        // creating a temporary node which will iterate through all the nodes
        Node* curr = _head;

        while (curr->next)
            curr = curr->next;

        curr->next = new Node(data);
    }
}

// LinkedList class method for adding a Node at a given Position from the Start
// Here, indexing starts from 0. So, for `index` = 0, this method will add a Node at
// the start of linked list i.e. it will become a `_head`
void LinkedList::addNodeAtPosFromStart(int index, int data) {
    if (index < 0) {
        std::cout << "Invalid input: negative index!\n";
        return;
    }

    // measure the length of linked list
    Node* curr = _head;
    int length = 0;
    while (curr) {
        length++;
        curr = curr->next;
    }

    // e.g. if length is 3 and index is 4 then it won't be possible to add
    // a node at the 4th place from the end
    if (index > length) {
        std::cout << "Invalid input: index is more than the length of linked list!\n";
        return;
    }

    Node* new_node = new Node(data);

    // if index == 0 then make the `new_node` as `_head`
    if (index == 0) {
        new_node->next = _head;
        _head = new_node;
    } else {
        curr = _head;
        // e.g. for linked list 10 -> 20 -> 30 & index 1, curr should be at 10
        for (int i = 0; i < index - 1; ++i)
            curr = curr->next;

        new_node->next = curr->next;
        curr->next = new_node;
    }
}

// LinkedList class method for adding a Node at a given Position from the End
// Indexing starts from 0 i.e.
// for index = 0, this method will add a Node at the End
// for index = 1, the method will add a Node at the second from the last place
void LinkedList::addNodeAtPosFromEnd(int index, int data) {
    if (index < 0) {
        std::cout << "Invalid input: negative index!\n";
        return;
    }

    // if the linked list is empty!
    if (_head == nullptr) {
        if (index != 0) {
            std::cout << "Invalid input: index out of range!\n";
            return;
        } else {
            _head = new Node(data);
            return;
        }
    }

    // measure the length of linked list
    Node* curr = _head;
    int length = 0;
    while (curr) {
        length++;
        curr = curr->next;
    }

    // e.g. if length is 3 and index is 4 then it won't be possible to add
    // a node at the 4th place from the end
    if (index > length) {
        std::cout << "Invalid input: index is more than the length of linked list!\n";
        return;
    }

    curr = _head;
    // e.g. for linked list 10 -> 20 -> 30 & index 1, curr should be at 20
    for (int i = 0; i < (length - index) - 1; ++i)
        curr = curr->next;

    Node* new_node = new Node(data);
    new_node->next = curr->next;
    curr->next = new_node;
}

// LinkedList class method for reversing LinkedList
void LinkedList::reverseLinkedList() {
    // 3 pointers
    Node* prev = nullptr;  // keep the address of previous node
    Node* curr = _head;    // keep the address of current node
    Node* nxt = nullptr;

    while (curr) {
        nxt = curr->next;  // keep the address of next node i.e. curr->next
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    // point '_head' to 'prev' not 'curr' because after while loop ends,
    // 'curr' will be pointing to 'nullptr' while 'prev' will be pointing to
    // the last node in the original Linked List.
    _head = prev;
}

int main() {
    LinkedList llobj;
    llobj.printLinkedList();

    // llobj.addNodeAtStart(13);
    // llobj.printLinkedList();

    // llobj.addNodeAtEnd(5);
    // llobj.printLinkedList();

    // llobj.addNodeAtPosFromStart(1, 31);
    // llobj.printLinkedList();

    // llobj.addNodeAtPosFromEnd(2, 27);
    // llobj.printLinkedList();

    llobj.reverseLinkedList();
    llobj.printLinkedList();

    return 0;
}