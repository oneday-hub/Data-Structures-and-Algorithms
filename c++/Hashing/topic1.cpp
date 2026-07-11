// lecture : 60 ; time : 
// topic : Implement hash table with closed addressing 
//         using (seperate chaining)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // Needed for find()
using namespace std;

class Hashing {
public:
    vector<list<int>> hashtable;
    int buckets;

    Hashing(int size) {
        buckets = size;
        hashtable.resize(size);
    }

    int hashValue(int key) {
        return key % buckets; // Division method
    }

    void addKey(int key) {
        int idx = hashValue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator searchKey(int key) {
        int idx = hashValue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }

    void deleteKey(int key) {
        int idx = hashValue(key);
        auto it = searchKey(key); // Store iterator
        
        if (it != hashtable[idx].end()) {
            hashtable[idx].erase(it);
            cout << key << " is deleted" << endl;
        } else {
            cout << key << " not found in hash table" << endl;
        }
    }

    // **Newly added function to display the hash table**
    void display() {
        for (int i = 0; i < buckets; i++) {
            cout << "Bucket " << i << ": ";
            for (int value : hashtable[i]) {
                cout << value << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    Hashing h(5); // Creating a hash table with 5 buckets
    h.addKey(5);
    h.addKey(9);
    h.addKey(3);
    h.addKey(14);
    h.addKey(22);

    cout << "Hash Table after insertion:\n";
    h.display();  // Displaying hash table

    h.deleteKey(3);
    cout << "Hash Table after deletion:\n";
    h.display();  // Displaying updated hash table

    return 0;
}
