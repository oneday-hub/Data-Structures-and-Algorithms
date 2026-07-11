#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // Needed for find()
using namespace std;

// Class representing a Hash Table using Separate Chaining
class Hashing {
public:
    vector<list<int>> hashtable;  // Vector of lists for separate chaining
    int buckets;  // Number of buckets in the hash table

    // Constructor to initialize the hash table with a given number of buckets
    Hashing(int size) {
        buckets = size;
        hashtable.resize(size); // Resize the vector to hold 'size' empty lists
    }

    // Hash function to compute index for a given key
    int hashValue(int key) {
        return key % buckets; // Division method to get index
    }

    // Function to insert a key into the hash table
    void addKey(int key) {
        int idx = hashValue(key); // Compute index
        hashtable[idx].push_back(key); // Insert key at the computed index (chaining)
    }

    // Function to search for a key and return an iterator to the key's position
    list<int>::iterator searchKey(int key) {
        int idx = hashValue(key); // Compute index
        return find(hashtable[idx].begin(), hashtable[idx].end(), key); // Search in the linked list
    }

    // Function to delete a key from the hash table
    void deleteKey(int key) {
        int idx = hashValue(key); // Compute index
        auto it = searchKey(key); // Get iterator to key
        
        // If the key is found, delete it
        if (it != hashtable[idx].end()) {  
            hashtable[idx].erase(it);
            cout << key << " is deleted" << endl;
        } else {
            cout << key << " not found in hash table" << endl;
        }
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < buckets; i++) {  // Loop through each bucket
            cout << "Bucket " << i << ": ";
            for (int value : hashtable[i]) { // Print all elements in the bucket
                cout << value << " -> ";
            }
            cout << "NULL" << endl;  // Indicate end of the list
        }
    }
};

// Driver Code (Main Function)
int main() {
    Hashing h(5); // Creating a hash table with 5 buckets

    // Adding keys to the hash table
    h.addKey(5);
    h.addKey(9);
    h.addKey(3);
    h.addKey(14);
    h.addKey(22);

    // Display hash table after insertion
    cout << "Hash Table after insertion:\n";
    h.display();

    // Deleting key 3
    h.deleteKey(3);

    // Display hash table after deletion
    cout << "Hash Table after deletion:\n";
    h.display();

    return 0;
}
