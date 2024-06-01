#include "MergeableHeap.h"

// Inserts a value into the unsorted heap.
void UnsortedHeap::insert(const int val) {
    // If the value is less than or equal to the current minimum, insert at the beginning of the list.
    if (val <= minimum()){
        list.insertAtBeginning(val);
    }
    // Otherwise, append the value to the end of the list.
    else {
        list.append(val);
    }
}

// Returns the minimum value in the heap.
// The minimum value is assumed to be at the beginning of the list.
const int UnsortedHeap::minimum() const{
    return list.peak(0);
}

// Extracts and returns the minimum value from the heap.
const int UnsortedHeap::extractMin(){
    // Get the minimum value.
    int min = minimum();
    // If the min value is not INF, i.e. not the dummy node, delete the node from the list.
    if (min != INF){
        list.deleteNode(min);
        // Move the new minimum to the front of the list.
        moveMinToFront();
    }
    return min;
}

// Moves the minimum value to the front of the list.
// This is done by using the insert() method on all elements into a helper heap, 
// which ensures the minimum is placed at the front.
void UnsortedHeap::moveMinToFront(){
    UnsortedHeap helperHeap;
    int first;
    // While there are elements in the current heap, extract them and insert into the helper heap.
    while (getSize() > 0){
        first = extractAt(0);
        helperHeap.insert(first);
    }
    // Assign the current heap to be the helper heap.
    *this = helperHeap;
}

// Merges another heap into the current heap.
//NOTE: Assumes other heap is Unsorted.
void UnsortedHeap::heapUnion(MergeableHeap& other){
    int first;
    // While there are elements in the other heap, extract them and insert into the current heap.
    while (other.getSize() > 0){
        first = other.extractAt(0);
        insert(first);
    }
}
