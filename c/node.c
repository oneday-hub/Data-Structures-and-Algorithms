#include<stdio.h>
#include<stdlib.h>
    struct Node{
    int data;
    struct Node *link;
};
int main (){

    struct Node *head = NULL;
    struct Node *node_1;
    struct Node *node_2;
    struct Node *node_3;
    node_1 = malloc(sizeof(struct Node));
    node_1->data=101;
    node_1->link=NULL;
    head= node_1;
    node_2 = malloc(sizeof(struct Node));
    node_2->data=102;
    node_2->link=NULL;
    node_1->link= node_2;
    node_3 = malloc(sizeof(struct Node));
    node_3->data=103;
    node_3->link=NULL;
    node_2->link= node_3;
     printf("Data: %d\n", head->data);
    printf("Link: %u\n", head->link);
}