// lecture : 50 ; time : 
/*question no : given the head of a linked list delete every alternate element from the list starting
              from the second element */
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
// function to delete the Alternate Nodes
void deleteAltenateNodes(Node* &head){
    Node*curr_node = head;
    while(curr_node!=NULL && curr_node -> next!=NULL){
        Node*temp = curr_node -> next; // this is the node to be deleted
        curr_node ->next = curr_node -> next ->next;
        free(temp);
        curr_node = curr_node -> next;
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
    deleteAltenateNodes(l1.head);
    l1.display();
    


    return 0;
}
