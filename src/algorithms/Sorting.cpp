#include "Sorting.h"

// Merge sort implementation - O(NlogN)
void Sorting::mergeSort(DoublyLinkedList& inputList){

    int inputListSize = inputList.getSize();

    // Base case: If the list has only one element, it's considered sorted
    if (inputListSize == 1){
        return;
    }

    // Divide the list into two sublists - O(n)
    DoublyLinkedList subList_L;
    DoublyLinkedList subList_R;
    int middleIndex = inputListSize / 2;

    int count = 0;
    while (count < middleIndex){
        subList_L.append(inputList.extractAtIndex(0));
        count ++;
    }
    while (inputList.getSize() > 0){
        subList_R.append(inputList.extractAtIndex(0));
    }

    // Recursively sort each sublist (in total we do this logN times)
    mergeSort(subList_L);
    mergeSort(subList_R);

    // Merge the sorted sublists -O(n)
    merge(subList_L, subList_R, inputList);
}

// Merge two sorted lists into a single sorted list
void Sorting::merge(DoublyLinkedList& list1, DoublyLinkedList& list2, DoublyLinkedList& mergedList){
    int minimum1 = list1.extractAtIndex(0);
    int minimum2 = list2.extractAtIndex(0);

    while (minimum1 != INF || minimum2 != INF){
        if (minimum2 == INF || minimum1 < minimum2){
            mergedList.append(minimum1);
            minimum1 = list1.extractAtIndex(0);
        }
        else {
            mergedList.append(minimum2);
            minimum2 = list2.extractAtIndex(0);
        }
    }
}

// Create a sorted heap from an unsorted heap
void Sorting::createSortedHeap(const UnsortedHeap& heap, SortedHeap& sortedHeap) {
    // get the list from the unsorted heap
    DoublyLinkedList helperList = heap.getList();

    // Sort the list using merge sort
    mergeSort(helperList);
    
    // Insert elements from the newly sorted list into the sorted heap
    int first;
    while (helperList.getSize() > 0)
    {
        first = helperList.extractAtIndex(0);
        sortedHeap.insert(first);
    }
}

// Sort an unsorted heap
void Sorting::sortHeap(UnsortedHeap& heap){
    // get the list from the heap
    DoublyLinkedList helperList = heap.getList();

    // Sort the list using merge sort
    mergeSort(helperList);
    
    // Empty current heap
    heap.makeHeap();

    // Insert elements from the newly sorted list into the heap
    int first;
    while (helperList.getSize() > 0)
    {
        first = helperList.extractAtIndex(0);
        heap.insert(first);
    }
}
