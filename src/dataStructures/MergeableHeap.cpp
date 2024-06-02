#include "MergeableHeap.h"

// Empties current data from the heap
void MergeableHeap::makeHeap(){
    list.clear();
}

// Returns the size of the heap.
const int MergeableHeap::getSize() const {
    return list.getSize();
};

// Displays contents of the Heap
void MergeableHeap::display() const{
    list.display();
}

// returns first value in list
const int MergeableHeap::peakAt(const int index) const
{
    return list.peak(index);
}

// extracts first value in list
const int MergeableHeap::extractAt(const int index){
    return list.extractAtIndex(index);
}

// returns const reference to the list
const DoublyLinkedList& MergeableHeap::getList() const{
    return list;
}