#include "DoublyLinkedList.h"
#include <stdexcept>
#include <iostream>

// Destructor
DoublyLinkedList::~DoublyLinkedList(){
    clear(); // Clear the list before deleting dummy
    delete dummy; // Delete the dummy node
}; 

// Clear the list
void DoublyLinkedList::clear(){
    // start at Node next to dummy, and iteratively delete each node until only dummy remains
    auto current = dummy->next;
    while (current != dummy){
        auto next = current->next;
        delete current;  // Delete the current node
        current = next;
        size--; // Decrease size
    }
    // Ensure next and prev of dummy points to itself
    dummy->next = dummy;
    dummy->prev = dummy;
}

// Add a node at the end of the list
void DoublyLinkedList::append(const int val){
    //Note: using append and delete operations causes a FIFO structure
    auto prevPtr = dummy->prev;
    Node* currentPtr = new Node(val);

    currentPtr->next = dummy;
    currentPtr->prev = prevPtr;

    prevPtr->next = currentPtr;
    dummy->prev = currentPtr;

    size ++; // Increase size
};

// Add a node at the beginning of the list
void DoublyLinkedList::insertAtBeginning(const int val){
    auto nextPtr = dummy->next;
    Node* currentPtr = new Node(val);

    currentPtr->prev = dummy;
    currentPtr->next = nextPtr;

    nextPtr->prev = currentPtr;
    dummy->next = currentPtr;

    size++; // increase size
};

void DoublyLinkedList::deleteNode(const int val){
    //Note: using append and delete operations causes a FIFO structure
    auto current = dummy->next;
    while (current != dummy){
        if (current->data == val){
            auto prevPtr = current->prev;
            auto nextPtr = current->next;

            prevPtr->next = nextPtr;
            nextPtr->prev = prevPtr;

            delete current; 
            size --;
            return;
        }
        current = current->next;
    }
    throw std::runtime_error("Node with value " + std::to_string(val) + " not found.");
};

// Display the list
void DoublyLinkedList::display() const{
    std::cout << "HEAD";
    auto current = dummy->next;
    while (current != dummy){
        std::cout << " -> " << current->data;
        current = current->next;
    }
    std::cout << std::endl;
};

// peak the value of the list at index i
const int DoublyLinkedList::peak(const int index) const{
    if (size == 0) {
        return INF;
    }
    if (index < 0 || index > size){
        throw std::runtime_error("Index " + std::to_string(index) + " is out of bounds.");
    }
    
    int count = 0;
    auto current = dummy->next;
    while (count < index){
        current = current->next;
        count++;
    }
    return current->data;
}

// Get size of list
const int DoublyLinkedList::getSize() const{
    return size;
}

// insert element at index i
void DoublyLinkedList::insertAtIndex(const int val, const int index){
    if (index < 0 || index > size){
        throw std::runtime_error("Index " + std::to_string(index) + " is out of bounds.");
    }

    Node* newPtr = new Node(val);
    
    int count = 0;
    auto current = dummy->next;
    while (count < index){
        current = current->next;
        count++;
    }

    auto prev = current->prev;

    prev->next = newPtr;
    current->prev = newPtr;

    newPtr->prev = prev;
    newPtr->next = current;

    size ++;
}

//extract a value from index i
const int DoublyLinkedList::extractAtIndex(const int index){
    if (index < 0 || index > size){
        throw std::runtime_error("Index " + std::to_string(index) + " is out of bounds.");
    }
    
    int count = 0;
    auto current = dummy->next;
    while (count < index){
        current = current->next;
        count++;
    }

    auto prev = current->prev;
    auto next = current->next;
    auto data = current->data;

    prev->next = next;
    next->prev = prev;
    size--;

    return data;
}

// Copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other): dummy(new Node(INF)){
    auto prevNode = dummy;

    // Copy the contents of the other list
    Node* dummyOther = other.dummy;
    Node* current = dummyOther->next;
    while (current != dummyOther){
        Node* newNode = new Node(current->data);
        prevNode->next = newNode;
        newNode->prev = prevNode;

        newNode->next = dummy;
        dummy->prev = newNode;

        prevNode = newNode;
        current = current->next;
    }
    size = other.getSize();
}

// Copy assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other) {
    if (this == &other){
        return *this;
    }
    // Delete the existing list
    clear();

    // Copy the contents of the other list
    Node* current = other.dummy->next;
    Node* prevNode = dummy;

    while (current != other.dummy) {
        Node* newNode = new Node(current->data);
        prevNode->next = newNode;
        newNode->prev = prevNode;

        newNode->next = dummy;
        dummy->prev = newNode;
        
        prevNode = newNode;
        current = current->next;
        size++;
    }
    return *this;
}


