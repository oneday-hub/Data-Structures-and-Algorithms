// lecture : 50; time : 29:49
/*topic name : insertion at the kth position in a single linked list:
               ---> add the node at the start */
#include<iostream>
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

       //  function of :-  INSERTION AT start --> head

void insertAtHead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node -> next = head;
    head = new_node;
}
// to print display is the function
void display (Node*head){
    // for the traversal in the linked list you need to create the temp pointer
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 2);
    display(head);
    insertAtHead(head, 1);
    display(head);
    
    return 0;
}
    
    

           