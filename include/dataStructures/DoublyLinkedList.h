#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <limits>

// Define magic number -- max number -> INF
const int INF = std::numeric_limits<int>::max();

class Node {
public:
    int data;           // Data stored in the node
    Node* next;         // Pointer to the next node
    Node* prev;         // Pointer to the previous node
    Node(int val): data(val), next(nullptr), prev(nullptr) {};   // Node constructor with data
    Node(): data(INF), next(this), prev(this) {};                // Dummy node constructor
};

class DoublyLinkedList {
private:
    int size;           // Size of the linked list
    Node* dummy;        // Pointer to the dummy node
public:
    // Constructor
    DoublyLinkedList(): size(0), dummy(new Node()) {};

    // Destructor
    ~DoublyLinkedList();

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList& other);

    // Copy assignment operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    // Append a node with given value to the end of the list
    void append(const int val);

    // Insert a node with given value at the beginning of the list
    void insertAtBeginning(const int val);

    // Delete the first occurrence of a node with given value from the list
    void deleteNode(const int val);

    // Display the elements of the list
    void display() const;

    // Get the size of the list
    const int getSize() const;

    // Clear the list
    void clear();

    // Insert a node with given value at the specified index
    void insertAtIndex(const int val, const int index); 

    // Extract the value at the specified index
    const int extractAtIndex(const int index);
    
    // Peek the value at the specified index without modifying the list
    const int peak(const int index) const;
};

#endif
