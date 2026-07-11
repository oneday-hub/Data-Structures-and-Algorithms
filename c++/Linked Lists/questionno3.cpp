//lecture no : 50 ; time : 
/*question : given the head of a single linked list and print the reversed list
input : 1->2->3->4
output : 4->3->3->1 */

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
void reversePrint(Node*head){
    // base case
    if(head==NULL){
        return ;
    }
    //recursive case
    reversePrint(head->next);
        cout<<head->val<<" ";
    }



int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.display();
    reversePrint(l1.head);
    
    
    


    return 0;
}



    

