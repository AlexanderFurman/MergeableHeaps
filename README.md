# Mergeable Heaps

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Data Structure Overview](#data-structure-overview)
  - [`Node`](#node)
  - [`DoublyLinkedList`](#doublylinkedlist)
  - [`MergeableHeap`](#mergeableheap)
  - [`SortedHeap`](#sortedheap)
  - [`UnsortedHeap`](#unsortedheap)
- [Sorting Namespace Overview](#sorting-namespace-overview)
  - [`Sorting`](#sorting)
- [Command Line Interface Overview](#command-line-interface-overview)
  - [`CLI`](#cli)
- [Usage](#usage)
  - [Introduction](#introduction-1)
  - [Run](#run)
  - [Available Commands](#available-commands)
  - [Example](#example)

## Introduction


A mergeable heap is an extension of a regular heap, which also allows the user to merge two heaps together.
While heaps are usually implemented with a tree, this project uses a linked-list instead of a traditional tree structure. The project includes two types of heaps: `SortedHeap` and `UnsortedHeap`, both of which inherit from the abstract class `MergeableHeap`.

## Features

- **Insertion:** Insert elements into the heap.
- **Deletion:** Remove the minimum element.
- **Heap Merging:** Merge two heaps efficiently.
- **Two Heap Types:** Supports heaps for both sorted and unsorted inputs.

## Data Structure Overview:
### `Node`
A simple data-holding struct used as elements in `DoublyLinkedList`.

#### Properties
- `data`: An integer value representing the data stored in the node.
- `next`: A pointer to the next node in the doubly linked list.
- `prev`: A pointer to the previous node in the doubly linked list.

#### Constructors
- `Node(int val)`: Constructor for creating a node with the specified data value.
- `Node()`: Constructor for creating a dummy node with a default data value set to infinity (INF).

### `DoublyLinkedList`
An implementation of a doubly-linked-list data structure.

#### Properties
- `size`: Integer representing the size of the linked list.
- `dummy`: Pointer to the dummy node serving as the sentinel node.

#### Constructors
- `DoublyLinkedList()`: Default constructor initializing the size to 0 and creating a dummy node.
- `~DoublyLinkedList()`: Destructor for releasing memory allocated for the list.
- `DoublyLinkedList(const DoublyLinkedList& other)`: Copy constructor for creating a new list by copying another list.
- `DoublyLinkedList& operator=(const DoublyLinkedList& other)`: Copy assignment operator for assigning one list to another.

#### Methods
- `append(const int val)`: Appends a node with the given value to the end of the list.
- `insertAtBeginning(const int val)`: Inserts a node with the given value at the beginning of the list.
- `deleteNode(const int val)`: Deletes the first occurrence of a node with the given value from the list.
- `display() const`: Displays the elements of the list.
- `getSize() const`: Returns the size of the list.
- `clear()`: Clears the list.
- `insertAtIndex(const int val, const int index)`: Inserts a node with the given value at the specified index.
- `extractAtIndex(const int index)`: Extracts the value at the specified index.
- `peak(const int index) const`: Peeks the value at the specified index without modifying the list.

#### Constructors
- `MergeableHeap()`: Default constructor initializing the internal doubly linked list.
- `~MergeableHeap()`: Destructor.

#### Pure Virtual Methods
- `insert(const int val)`: Inserts a value into the unsorted heap.
- `minimum() const`: Returns the minimum value in the heap.
- `extractMin()`: Extracts and returns the minimum value from the heap.
- `heapUnion(MergeableHeap& other)`: Merges another heap into the current heap.

#### Methods
- `getSize() const`: Returns the size of the heap.
- `display() const`: Displays the contents of the heap.
- `makeHeap()`: Empties current data from the heap.
- `getList() const`: Returns a const reference to the internal doubly linked list.

#### Protected Members
- `list`: Doubly-linked-list of type `DoublyLinkedList` storing the elements of the heap.

#### Protected Methods
- `peakAt(const int index) const`: Peaks at the value in the list at a certain index.
- `extractAt(const int index)`: Extracts the value from the list at a certain index.

#### Friend Classes
- `UnsortedHeap`
- `SortedHeap`


### `SortedHeap`
A class representing a mergeable heap which receives only sorted data, inheriting from `MergeableHeap`.

#### Methods
- `insert(const int val) override`: Inserts a value into the sorted heap.
- `minimum() const override`: Returns the minimum value in the sorted heap.
- `extractMin() override`: Extracts and returns the minimum value from the sorted heap.
- `heapUnion(MergeableHeap& other) override`: Merges another heap into the current sorted heap.

### `UnsortedHeap`
A class representing a mergeable heap which receives unsorted data, inheriting from `MergeableHeap`.

#### Methods
- `insert(const int val) override`: Inserts a value into the unsorted heap.
- `minimum() const override`: Returns the minimum value in the unsorted heap.
- `extractMin() override`: Extracts and returns the minimum value from the unsorted heap.
- `heapUnion(MergeableHeap& other) override`: Merges another heap into the current unsorted heap.

#### Private Methods
- `moveMinToFront()`: Moves the minimum value to the front of the list.

## Sorting Namespace Overview:
### `Sorting`
A namespace containing functions for sorting operations.

#### Functions
- `sortHeap(UnsortedHeap& heap)`: Sorts an unsorted heap.
- `mergeSort(DoublyLinkedList& inputList)`: Performs the Merge Sort algorithm on a doubly-linked-list.
- `merge(DoublyLinkedList& list1, DoublyLinkedList& list2, DoublyLinkedList& mergedList)`: Performs the Merge operation on a pair of lists, used in the Merge Sort algorithm.
- `createSortedHeap(const UnsortedHeap& heap, SortedHeap& sortedHeap)`: Creates a new sorted heap based on the current unsorted heap.


## Command Line Interface Overview

### `CLI`
A singleton class responsible for handling interactions with the user on the command line.

#### Methods
- `parse(const string& input) const`: Parses the input string into individual commands.
- `execute(const vector<string>& commands)`: Executes a sequence of commands.
- `welcome() const`: Displays a welcome message.
- `intro() const`: Displays an introduction.
- `menu() const`: Displays menu options.

#### Private Members
- `heaps`: Map to store unique pointers to heap objects using their inputted names as keys.

#### Private Methods
- `heapExists(const string& heapName) const`: Checks if a heap with the given name exists.
- `heapType(const string& heapName) const`: Gets the type of heap associated with a given name.
- `makeHeap(const string& sortType, const string& heapName)`: Creates a new heap with the given sorting type and name.
- `load(const string& heapName, const string& filename)`: Loads data from a file into a heap.
- `insert(const string& heapName, int value)`: Inserts a value into the heap.
- `minimum(const string& heapName) const`: Gets the minimum value from the heap.
- `extractMin(const string& heapName)`: Extracts the minimum value from the heap.
- `sort(const string& heapName)`: Sorts the heap.
- `unionHeap(const string& heapName1, const string& heapName2)`: Merges two heaps.
- `display(const string& heapName) const`: Displays the contents of the heap.


## Usage

### Introduction
In this program, you will be able to try out an implementation of a mergeable heap using linked-lists!

### Run
Run the program with the following command:
```
    ./main.exe
```

### Available Commands
You can execute the following commands in the terminal:

- `make heap {SORT_TYPE} {NAME}`: Creates a new heap (either sorted or unsorted).
- `heap {NAME} load {FILENAME}`: Inserts all values from a file `{FILENAME}` into the selected heap.
- `heap {NAME} insert {INT}`: Inserts an integer into the selected heap.
- `heap {NAME} minimum`: Prints the minimum value in the heap.
- `heap {NAME} extractmin`: Removes the minimum value in the heap and prints it.
- `heap {NAME} sort`: Sorts the contents of the heap.
- `heap {NAME_1} union heap {NAME_2}`: Merges `heap_2` into `heap_1`.
- `heap {NAME} display`: Displays the heap.
- `help`: Displays this menu again.
- `quit`: Quits the program.

### Example
Create an unsorted heap A
```
Enter a command ('quit' to exit // 'help' for menu): make heap unsorted A
Heap A (unsorted input) created!
```

Load its values from a file ('testing/6.txt')
```
Enter a command ('quit' to exit // 'help' for menu): heap A load testing/6.txt
Inserted 5 into heap A (unsorted input)!
Displaying heap A (unsorted input): HEAD -> 5
Inserted 2 into heap A (unsorted input)!
Displaying heap A (unsorted input): HEAD -> 2 -> 5
Inserted 3 into heap A (unsorted input)!
Displaying heap A (unsorted input): HEAD -> 2 -> 5 -> 3
Inserted 8 into heap A (unsorted input)!
Displaying heap A (unsorted input): HEAD -> 2 -> 5 -> 3 -> 8
```
Create an unsorted heap B
```
Enter a command ('quit' to exit // 'help' for menu): make heap unsorted B
Heap B (unsorted input) created!
```
Load its values from a file ('testing/2.txt')
```
Enter a command ('quit' to exit // 'help' for menu): heap B load testing/2.txt
Inserted 9 into heap B (unsorted input)!
Displaying heap B (unsorted input): HEAD -> 9
Inserted 1 into heap B (unsorted input)!
Displaying heap B (unsorted input): HEAD -> 1 -> 9
Inserted 2 into heap B (unsorted input)!
Displaying heap B (unsorted input): HEAD -> 1 -> 9 -> 2     
Inserted 7 into heap B (unsorted input)!
Displaying heap B (unsorted input): HEAD -> 1 -> 9 -> 2 -> 7
```
Merge heap B into heap A

```
Enter a command ('quit' to exit // 'help' for menu): heap A union heap B
Merged heap B (unsorted input) into heap A (unsorted input)
Displaying heap A (unsorted input): HEAD -> 1 -> 2 -> 5 -> 3 -> 8 -> 9 -> 2 -> 7
Displaying heap B (unsorted input): HEAD
```
Sort heap A
```
Enter a command ('quit' to exit // 'help' for menu): heap A sort
Here is the sorted contents of heap A (unsorted input): HEAD -> 1 -> 2 -> 2 -> 3 -> 5 -> 7 -> 8 -> 9
```