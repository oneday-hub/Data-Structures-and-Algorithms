// lecture : 57; time : 
// topic : implemetation of queue using linked list
//         -- this is commented explaination of topic 1 ..ie (implementation of queue)


#include<iostream>
#include<vector>
using namespace std;

// Define a Queue class that uses a vector for storage
class Queue {
    int front; // Index of the front of the queue
    int back;  // Index of the back of the queue
    vector<int> v; // Vector to store the elements of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        this->front = -1; // Initially, the queue is empty
        this->back = -1;  // No elements, so back is also -1
    }

    // Method to add an element to the queue
    void enqueue(int data) {
        v.push_back(data); // Add the element to the end of the vector
        this->back++;      // Update the back index to the new element

        // If this is the first element, update the front index
        if (this->back == 0) this->front = 0;
    }

    // Method to remove an element from the queue
    void dequeue() {
        // If the queue becomes empty after removal
        if (this->front == this->back) {
            this->front = -1; // Reset indices to indicate empty queue
            this->back = -1;
            this->v.clear(); // Clear the vector
        } else {
            this->front++; // Increment the front index to remove the front element
        }
    }

    // Method to get the element at the front of the queue
    int getfront() {
        if (this->front == -1) return -1; // If the queue is empty, return -1
        return this->v[this->front];     // Return the front element
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return this->front == -1; // Queue is empty if front is -1
    }
};

int main() {
    Queue qu;

    // Add elements to the queue
    qu.enqueue(10); // Queue: [10]
    qu.enqueue(20); // Queue: [10, 20]
    qu.enqueue(30); // Queue: [10, 20, 30]

    // Remove the front element
    qu.dequeue();   // Queue: [20, 30]
    
    // Add another element
    qu.enqueue(40); // Queue: [20, 30, 40]

    // Remove elements from the front
    qu.dequeue();   // Queue: [30, 40]
    qu.dequeue();   // Queue: [40]
    qu.dequeue();   // Queue: []

    // Add new elements
    qu.enqueue(400); // Queue: [400]
    qu.enqueue(500); // Queue: [400, 500]

    // Print and remove elements until the queue is empty
    while (!qu.isEmpty()) {
        cout << qu.getfront() << endl; // Print the front element
        qu.dequeue();                  // Remove the front element
    }

    return 0;
}
