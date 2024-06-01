#include "MergeableHeap.h"

void SortedHeap::insert(const int val) {
    // Insert a new value into the list.
    // The list is expected to maintain its sorted order after insertion.
    list.append(val);
}

const int SortedHeap::minimum() const{
    // Return the smallest value in the list.
    // Since the list is sorted, the smallest value is at the front (index 0).
    return list.peak(0);
}

const int SortedHeap::extractMin(){
    // Retrieve the minimum value using the minimum() method.
    int min = minimum();

    // If the minimum value is not infinity (i.e. list size > 0),
    // delete the node containing the minimum value from the list.
    // (Note this operation is O(1) since min is first node)
    if (min != INF){
        list.deleteNode(min);
    }

    // Return the minimum value.
    return min;
}

void SortedHeap::heapUnion(MergeableHeap& other){
    // Union this heap with another heap (other).

    // Create a new helper heap to store the merged elements.
    SortedHeap helperHeap;

    // Extract the minimum elements from both heaps.
    int minimum = extractMin();
    int minimumOther = other.extractMin();

    // Merge the elements from both heaps in sorted order.
    while (minimum != INF || minimumOther != INF){
        // If the other heap is out of elements, OR this heap's min is less then other heap's min:
        // insert the minimum from the current heap and extract the next minimum.
        if (minimumOther == INF || minimum <= minimumOther){
            helperHeap.insert(minimum);
            minimum = extractMin();
        }
        // Otherwise, insert the minimum from the other heap and extract the next minimum.
        else {
            helperHeap.insert(minimumOther);
            minimumOther = other.extractMin();
        }
    }
    // Replace the current heap with the merged healperHeap.
    *this = helperHeap;
}

