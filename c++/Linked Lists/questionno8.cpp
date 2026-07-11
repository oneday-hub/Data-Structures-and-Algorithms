// lecture no : 51 ; time : 
/* question : Given the heads of two singly linked- lists headA and headB, return 
              the node at which the two list intersect, if the two linked list have no intersection at 
              all, return null 
              
              input : 1->2->3->4->5
              output:   
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
int getLength(Node*head){
    Node*temp = head;
    int lenght = 0;
    
    while(temp!=NULL){
        lenght++;
        temp = temp->next;
    }
    return lenght;
}

void moveHeadByk(Node* head, int k){
    Node* ptr = head;
    while (k--){
        ptr = ptr->next;
    }
    return ptr ;


}
Node* getIntersection(Node* head1, Node*head2){
    Node*ptr1=head1;
    Node*ptr2 =head2;
    // step 1 : calculate lenght of both linked lists
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    // step 2 : find the difference k between linkedlists and move longer linkedlist ptr by k steps
    Node* ptr1;
    Node* ptr2;
    if(l1>l2){ // l1 is longer
        int k = l1-l2;
        ptr1 = moveHeadByk(head1, k);
        ptr2 = head2;
    }
    else{// l2 is longer
        int k = l2-l1;
        ptr1 = head2;
        ptr2 = moveHeadByk(head2, k);

    }

    // step 3 : compare ptr1 and ptr2 nodes
    while (ptr1){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return NULL;
    

}
int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    // 1->2->3->4->5->null

    LinkedList l2;
    l2.insertAtTail(6);
    l2.insertAtTail(7);
    l2.head->next->next = l1.head->next->next->next;
    // 6->7->4->5->null
    l2.display();

    Node* intersection = getIntersection(l1.head, l2.head);
    if(intersection){
        cout<<intersection->val<<endl;
    }
    else{
        cout<< "-1" <<endl;
    }
    
    return 0;
}