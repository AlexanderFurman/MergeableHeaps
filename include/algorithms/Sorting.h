#ifndef SORTING_H
#define SORTING_H

#include "MergeableHeap.h"

namespace Sorting {

    // create a new SortedHeap based off of the current heap.
    void createSortedHeap(const UnsortedHeap& heap, SortedHeap& sortedHeap);

    // performs Merge Sort algorithm on a list
    void mergeSort(DoublyLinkedList& inputList);

    // performs Merge operation on pair of lists -- used in Merge Sort algorithm
    void merge(DoublyLinkedList& list1, DoublyLinkedList& list2, DoublyLinkedList& mergedList);
}

#endif // SORTING_H
