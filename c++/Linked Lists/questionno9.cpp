// lecture : 51 ; time : 
/*question : given the head of a linked list, remove the k-th node from the end of
             the list and return its head

             using the concept of two pointers 
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
    
    // assuming k is always less than/equal length of linked list
    void removeKthNodeFromEnd(Node* &head, int k){

        Node ptr1 = head;
        Node ptr2 = head;

        //move ptr2 by k steps ahead
        int count = k;
        while(count--){
            ptr2= ptr2->next;
        }

        // now ptr2 is k steps ahead of ptr1
        // when ptr2 is at NULL (end of list), ptr1 will be at node to be deleted
        while(ptr2->next!=NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            
        }
        //now ptr1 is pointing to the node before kth node from end
        // node to be deleted is ptr1->next
        Node* temp = ptr1->next;
        ptr1->next = ptr1 ->next ->next;
        free(temp);

    }

};
int main(){
    return 0;
}