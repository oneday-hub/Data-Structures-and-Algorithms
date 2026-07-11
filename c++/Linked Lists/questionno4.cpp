//lecture no : 50 ; time : 
/*question : given the head of a single linked list, reverse the list, and return the reversed list
             remember : you have to return the reversed list not to print it

             this is iterative way 
             
input : 1->2->3->4->5
output : 5->4->3->3->1 */

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
Node* reverseL1(Node*&head){
    Node*preptr = NULL;
    Node*currptr = head;
    //currptr->next = preptr;
    // move all 3 ptrs by one step a head
    while(currptr!=NULL){
        Node*nextptr = currptr->next;
        currptr->next = preptr;
        preptr = currptr;
        currptr = nextptr;

    }
    //when this loop ends, preptr pointing to my last node which is new head
    Node* new_head = preptr;
    return new_head;
}



int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.display();
    l1.head = reverseL1(l1.head);
    l1.display();
    
    return 0;
}



    
