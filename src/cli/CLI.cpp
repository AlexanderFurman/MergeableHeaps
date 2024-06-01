#include "CLI.h"
#include <sstream>
#include <iostream>
#include <fstream>

vector<string> CLI::parse(const string& input) const{
    vector<string> words;
    stringstream ss(input);
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    return words;
}

void CLI::execute(const vector<string>& commands) {
    //CHECK INVALID
    if (commands.size() < 3){
        cout << "Invalid operation" << endl;
        return;
    }

    // MAKE HEAP
    if (commands[0] + commands[1] == "makeheap" && commands.size() == 4){
            auto sortType = commands[2];
            auto name = commands[3];
            makeHeap(sortType, name);
            return;
    }

    //CHECK INVALID
    if (commands[0] != "heap"){
        cout << "Invalid operation" << endl;
        return;
    }

    //DEFINE NAME
    auto name = commands[1];

    // Execute operations based on commands
    if (commands.size() == 3 && commands[2] == "display") {
        display(name);
    }
    else if (commands.size() == 3 && commands[2] == "minimum") {
        minimum(name);
    }
    else if (commands.size() == 3 && commands[2] == "extractmin") {
        extractMin(name);
    }
    else if (commands.size() == 3 && commands[2] == "sort") {
        sort(name);
    }
    else if (commands.size() == 4 && commands[2] == "load") {
        auto file = commands[3];
        load(name, file);
    }
    else if (commands.size() == 4 && commands[2] == "insert") {
        int val = std::stoi(commands[3]);
        insert(name, val);
    }
    else if (commands.size() == 5 && commands[2] == "union"){
        auto name2 = commands[4];
        unionHeap(name, name2);
    }
    else{
        cout << "Invalid operation" << endl;
        return;
    }
}

const bool CLI::heapExists(const string& heapName) const{
    // Check if heap with the given name exists
    return heaps.count(heapName) > 0;
}

void CLI::makeHeap(const string& sortType, const string& heapName){
    unique_ptr<MergeableHeap> ptr;
    // Create a new heap based on the sorting type
    if (sortType == "sorted")
        ptr = make_unique<SortedHeap>();
    else if (sortType == "unsorted")
        ptr = make_unique<UnsortedHeap>();
    else {
        cout << "sort type '" << sortType << "' does not exist." << endl;
        return;
    }

    // Check if heap already existed
    bool heapAlreadyExisted = heapExists(heapName);
    
    // Store the new heap in the map
    heaps[heapName] = move(ptr);

    // Print message based on if the heap already existed
    if (heapAlreadyExisted)
        cout << "Heap " << heapName << " " << heapType(heapName) <<  " cleared!" << endl;
    else
        cout << "Heap " << heapName << " " << heapType(heapName) <<  " created!" << endl;
}


void CLI::load(const string& heapName, const string& filename) {
    // Open the file for reading
    ifstream file(filename);
    
    // Check if the file is opened successfully
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    int num;
    while (file >> num) {
        // Read each number from the file and add it to the heap
        insert(heapName, num); 
    }

    // Close the file
    file.close();
}

void CLI::insert(const string& heapName, int value){
    if (!heapExists(heapName)){
        cout << "Heap " << heapName << " does not exist!" << endl;
        return;
    }
    // Insert the value into the heap
    heaps[heapName]->insert(value);
    cout << "Inserted " << value << " into heap " << heapName << " " << heapType(heapName) <<  "!" << endl;
}

void CLI::minimum(const string& heapName) const{
    if (!heapExists(heapName)){
        cout << "Heap " << heapName << " does not exist!" << endl;
        return;
    }
    // Print the minimum value of the heap
    cout << "Minimum of heap " << heapName << " " << heapType(heapName) << " = " << heaps.at(heapName)->minimum() << endl;
}

void CLI::extractMin(const string& heapName){
    if (!heapExists(heapName)){
        cout << "Heap " << heapName << " does not exist!" << endl;
        return;
    }
    // Extract the minimum value from the heap and print it
    cout << "Extracted minimum from heap " << heapName << " " << heapType(heapName) << ": " << heaps[heapName]->extractMin() << endl;
}

void CLI::unionHeap(const string& heapName1, const string& heapName2){
    if (!heapExists(heapName1)){
        cout << "Heap" << heapName1 << " does not exist!" << endl;
        return;
    }
    if (!heapExists(heapName2)){
        cout << "Heap" << heapName2 << " does not exist!" << endl;
        return;
    }
    // Merge the second heap into the first heap
    heaps[heapName1]->heapUnion(*heaps[heapName2]);
    cout << "Merged heap " << heapName2 << " " << heapType(heapName2) << " into heap " << heapName1 << " " << heapType(heapName1) <<  endl;
}

void CLI::display(const string& heapName) const{
    if (!heapExists(heapName)){
        cout << "Heap" << heapName << " does not exist!" << endl;
    }
    // Display the contents of the heap
    cout << "Displaying heap " << heapName << " " << heapType(heapName) << ": ";
    heaps.at(heapName)->display();
}

void CLI::sort(const string& heapName){
    if (!heapExists(heapName)){
        cout << "Heap" << heapName << " does not exist!" << endl;
    }
    // Get a pointer to the heap object
    MergeableHeap* heapPtr = heaps[heapName].get();

    //If heap type is UnsortedHeap, then sort the heap
    if (UnsortedHeap* unsortedPtr = dynamic_cast<UnsortedHeap*>(heapPtr)){
        // Create a new sorted heap
        unique_ptr<SortedHeap> sortedPtr(new SortedHeap());

        // Sort the unsorted heap and store the result in the sorted heap
        Sorting::createSortedHeap(*unsortedPtr, *sortedPtr);

        // Replace the original heap with the sorted heap
        heaps[heapName] = move(sortedPtr);

        cout << "Sorted heap " << heapName << "!" << endl;
    }
    else {
        cout << "Heap " << heapName << " " << heapType(heapName) <<  " already sorted!" << endl;
    }
}

const char* CLI::heapType(const string& heapName) const{
    // Get a pointer to the heap object
    MergeableHeap* heapPtr = heaps.at(heapName).get();

    // Check the type of heap and return the corresponding string
    if (UnsortedHeap* unsortedPtr = dynamic_cast<UnsortedHeap*>(heapPtr)){
        return "(unsorted)";
    }
    else{
        return "(sorted)";
    }
}

void CLI::welcome() const{
    cout << Text::welcome << endl;
}
void CLI::intro() const{
    cout << Text::intro << endl;
}
void CLI::menu() const{
    cout << Text::operations << endl;
}