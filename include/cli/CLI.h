#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>

#include "MergeableHeap.h"
#include "Sorting.h"

#include "text.h"

using namespace std;

// Class responsible for handling interactions with the user on the command line.
class CLI{
    public:
        // Singleton design pattern: getInstance() returns a reference to the single instance of CLI.
        static CLI& getInstance(){
            static CLI instance;
            return instance;
        }

        // Parse the input string into individual commands.
        vector<string> parse(const string& input) const;
        
        // Execute a sequence of commands.
        void execute(const vector<string>& commands);

        // Display welcome message.
        void welcome() const;

        // Display introduction.
        void intro() const;

        // Display menu options.
        void menu() const;

    private:
        // Map to store heap objects using their names as keys.
        unordered_map<string, unique_ptr<MergeableHeap>> heaps;

        // Check if a heap with the given name exists.
        const bool heapExists(const string& heapName) const;

        // Get the type of heap associated with a given name.
        const char* heapType(const string& heapName) const;

        // Create a new heap with the given sorting type and name.
        void makeHeap(const string& sortType, const string& heapName);

        // Load data from a file into a heap.
        void load(const string& heapName, const string& filename);

        // Insert a value into the heap.
        void insert(const string& heapName, int value);

        // Get the minimum value from the heap.
        void minimum(const string& heapName) const;

        // Extract the minimum value from the heap.
        void extractMin(const string& heapName);

        // Sort the heap.
        void sort(const string& heapName);

        // Merge two heaps.
        void unionHeap(const string& heapName1, const string& heapName2);

        // Display the contents of the heap.
        void display(const string& heapName) const;
};

#endif // CLI_H
