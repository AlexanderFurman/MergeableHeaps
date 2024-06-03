#ifndef MEARGEABLEHEAP_H
#define MEARGEABLEHEAP_H

#include "DoublyLinkedList.h"
#include <memory>
#include <stdexcept>

// Abstract class for Mergeable Heap
class MergeableHeap {
    public:
        MergeableHeap(): list(DoublyLinkedList()) {};
        virtual ~MergeableHeap() {};

        // #################### PURE VIRTUAL METHODS: #########################

        // Inserts a value into the unsorted heap.
        virtual void insert(const int val) = 0;

        // Returns the minimum value in the heap.
        virtual const int minimum() const = 0;

        // Extracts and returns the minimum value from the heap.
        virtual const int extractMin() = 0;

        // Merges another heap into the current heap.
        virtual void heapUnion(MergeableHeap& other) = 0;

        // ####################################################################

        // Returns the size of the heap.
        const int getSize() const;

        // Displays contents of the Heap
        void display() const;

        // Empties current data from the heap
        void makeHeap();
        
        // return const reference to the list
        const DoublyLinkedList& getList() const;

        // Declare UnsortedHeap, SortedHeap as friends of MergeableHeap, allowing them to access protected members and methods of MergeableHeap
        friend class UnsortedHeap;
        friend class SortedHeap;

    protected:
        DoublyLinkedList list;

        // Peak at value in list at certain index
        const int peakAt(const int index) const;

        // Extract value from list at certain index
        const int extractAt(const int index);
};

class SortedHeap: public MergeableHeap {
    public:
        SortedHeap(){};
        ~SortedHeap(){};
        void insert(const int val) override;
        const int minimum() const override;
        const int extractMin() override;
        void heapUnion(MergeableHeap& other) override;
};

class UnsortedHeap: public MergeableHeap {
    public:
        UnsortedHeap(){};
        ~UnsortedHeap(){};
        void insert(const int val) override;
        const int minimum() const override;
        const int extractMin() override;
        void heapUnion(MergeableHeap& other) override;
        
    private:
        // moves min value to front of the list
        void moveMinToFront();
};      


#endif