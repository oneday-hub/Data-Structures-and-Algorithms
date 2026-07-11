// lecture : 58; time : 55:23
// topic : circular queue
//         -- implementing the cicular queue using arrays
//         -- this is commented explaination 

#include<iostream>
#include<vector>
using namespace std;

// Class to implement a Queue using a dynamic array (vector)
class Queue {
    int front; // Index of the front of the queue
    int back;  // Index of the back of the queue
    vector<int> v; // Vector to store the elements of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        this->front = -1; // Front index starts as -1 (empty queue)
        this->back = -1;  // Back index starts as -1 (empty queue)
    }

    // Method to add an element to the queue
    void enqueue(int data) {
        v.push_back(data); // Add the new element to the vector
        this->back++;      // Increment the back index to point to the new element
        if (this->back == 0) this->front = 0; // If first element, update front index to 0
    }

    // Method to remove an element from the queue
    void dequeue() {
        if (this->front == this->back) { // If there's only one element left
            this->front = -1;           // Reset the queue to empty state
            this->back = -1;
            this->v.clear();            // Clear the vector
        } else {
            this->front++; // Move the front index to the next element
        }
    }

    // Method to get the front element of the queue
    int getfront() {
        if (this->front == -1) return -1; // If queue is empty, return -1
        return this->v[this->front];      // Return the element at the front index
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return this->front == -1; // Queue is empty if front index is -1
    }
};

int main() {
    Queue qu;

    // Add elements to the queue
    qu.enqueue(10);  // Queue: [10]
    qu.enqueue(20);  // Queue: [10, 20]
    qu.enqueue(30);  // Queue: [10, 20, 30]

    // Remove the front element
    qu.dequeue();    // Queue: [20, 30]

    // Add another element to the queue
    qu.enqueue(40);  // Queue: [20, 30, 40]

    // Remove more elements
    qu.dequeue();    // Queue: [30, 40]
    qu.dequeue();    // Queue: [40]
    qu.dequeue();    // Queue is now empty

    // Add more elements
    qu.enqueue(400); // Queue: [400]
    qu.enqueue(500); // Queue: [400, 500]

    // Print and remove all elements from the queue
    while (!qu.isEmpty()) {
        cout << qu.getfront() << endl; // Print the front element
        qu.dequeue();                  // Remove the front element
    }

    return 0;
}
