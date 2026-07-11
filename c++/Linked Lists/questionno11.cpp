// lecture : 52; time : 
/*question : Pattern : Merging multiple linked list

             you are given an array of k linked-lists lists, each linked-list is sorted in ascending arder. 
             Merge all the linked-lists into one sorted linked-list and return it.
             */

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data){
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
        Node* new_node = new Node(value);
        if(head == NULL){ // LinkedList is empty
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* mergeLinkedLists(Node* &head1, Node* &head2){
    Node* dummyHeadNode = new Node(-1);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyHeadNode;

    while (ptr1 && ptr2){
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next; // This line should be inside the loop
    }

    if(ptr1){
        ptr3->next = ptr1;
    }else{
        ptr3->next = ptr2;
    }

    return dummyHeadNode->next; // return the head of the merged list
}

Node* mergeKLinkedList(vector<Node*> &lists){
    if(lists.size() == 0){
        return NULL;
    }
    while(lists.size() > 1){
        Node* mergedHead = mergeLinkedLists(lists[0], lists[1]);  // Correct function call
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

/* vector-> head1 head2 head3 head4
step 1 : head1 and head2 linkedlist will be merged
remove : head1 and head2

so now we have vector-> : head3 head4 mergedhead1_2

step 2 : head3 and head4 linkelist will be merged
remove : head3 and head4

so now we have vector-> : mergedhead1_2  mergedhead3_4 

step 3 : mergedhead1_2 mergehead3_4 will be merged
remove : mergedhead1_2 and mergehead3_4

so finally we have vector-> : mergedhead1_2_3_4

*/

int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(7);
    l1.insertAtTail(8);
    l1.display();

    LinkedList l2;
    l2.insertAtTail(2);
    l2.insertAtTail(4);
    l2.insertAtTail(5);
    l2.display();

    LinkedList l3;
    l3.insertAtTail(3);
    l3.insertAtTail(6);
    l3.display();

    vector<Node*> lists;
    lists.push_back(l1.head);
    lists.push_back(l2.head);
    lists.push_back(l3.head);

    LinkedList mergedLL;
    mergedLL.head = mergeKLinkedList(lists);
    mergedLL.display();

    return 0;
}
