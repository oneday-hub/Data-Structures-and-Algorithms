// lecture : 57; time : 
// topic : implemetation of queue using linked list
//         -- this is commented explaination of topic 1 ..ie (implementation of queue)

#include <iostream>
using namespace std;

// Define a Node class to represent each element in the queue
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Define a Queue class that uses a linked list to implement the queue
class Queue {
    Node* head; // Pointer to the front of the queue
    Node* tail; // Pointer to the rear of the queue
    int size;   // Keeps track of the number of elements in the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    // Method to add an element to the rear of the queue
    void enqueue(int data) {
        Node* newNode = new Node(data); // Create a new node
        if (this->head == NULL) {       // If the queue is empty
            this->head = this->tail = newNode; // Set both head and tail to the new node
        } else {
            this->tail->next = newNode; // Link the new node to the current tail
            this->tail = newNode;       // Update the tail to the new node
        }
        this->size++; // Increase the size of the queue
    }

    // Method to remove an element from the front of the queue
    void dequeue() {
        if (this->head == NULL) { // If the queue is empty, do nothing
            return;
        } else {
            Node* oldHead = this->head;       // Store the current head
            Node* newHead = this->head->next; // Move the head to the next node
            this->head = newHead;             // Update the head pointer
            if (this->head == NULL)           // If the queue becomes empty
                this->tail = NULL;            // Set tail to NULL as well
            oldHead->next = NULL;             // Isolate the old head
            delete oldHead;                   // Free the memory of the old head
            this->size--;                     // Decrease the size of the queue
        }
    }

    // Method to get the size of the queue
    int getSize() {
        return this->size; // Return the size
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return this->head == NULL; // Return true if head is NULL (queue is empty)
    }

    // Method to get the front element of the queue
    int front() {
        if (this->head == NULL) // If the queue is empty, return -1
            return -1;
        return this->head->data; // Return the data of the front node
    }
};

int main() {
    Queue qu; // Create an instance of the Queue

    // Add elements to the queue
    qu.enqueue(10); // Add 10 to the queue
    qu.enqueue(20); // Add 20 to the queue
    qu.enqueue(30); // Add 30 to the queue

    // Remove one element from the front of the queue
    qu.dequeue(); // Removes 10

    // Add another element to the queue
    qu.enqueue(40); // Add 40 to the queue

    // Print and remove elements from the queue until it's empty
    while (not qu.isEmpty()) {
        cout << qu.front() << endl; // Print the front element
        qu.dequeue();               // Remove the front element
    }

    return 0;
}
