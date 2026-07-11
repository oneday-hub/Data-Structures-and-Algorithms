// lecture : 51 ; time :

/* question : Given head, the head of a linked list, determine if the linked list is a palindrome or not

*/

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*next;

    Node(int data ){
        val = data;
        next = NULL;
    }
};
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void insertAtTail(int value){
        Node*new_node= new Node(value);
        if(head == NULL){ // LinkedList is empty
            head = new_node; 
            return;
        }
        Node* temp = head;
        while(temp ->next!=NULL){
            temp = temp->next;
        }
        temp -> next = new_node;
        
    }
    void display(){
        Node*temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;

        }cout<<"NULL"<<endl;
    }

};

bool isPalindrome(Node* head){

    // 1.find the middle element
    Node*fast = head;
    Node*slow = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    // now slow is pointing to middle element
    // 2. break the linked list in the middle

    Node*curr = slow->next;
    Node*prev = slow;
    slow->next = NULL;

    // 3. reverse the second half of linked list
    while (curr){
        Node* nextNode = curr->next;

    }
    
    
}



int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    l1.display();
    
    
    return 0;
}
