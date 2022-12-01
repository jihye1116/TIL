// 백준 1158
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int data;
}Node;

Node* head = NULL;
Node* tail = NULL;

Node* makenode(int data){
    struct Node* new = malloc(sizeof(struct Node));
    new->next = NULL;
    new->prev = NULL;
    new->data = data;
    return new;
}
 
void insertLast(int data){
    struct Node* temp = head;
    struct Node* newnode = makenode(data);
 
    if (head == NULL) {
        head = newnode;
        tail = head;
    }
    else {
        temp = tail;
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
    }
}
 
void R(Node* head,int num ,int key)
{
    Node* tmp = head->prev;
    int c = 0;
    int t = 0;
    printf("<");
    while (c < num) {
        t = key;
        while (t--) tmp = tmp->next;
        printf(c++ ? ", %d" : "%d", tmp->data);
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
    }
    printf(">");
 
}

int main() {
 
    int num;
    int key;
    int count = 0;
    scanf("%d %d", &num, &key);
    for (int i = 1; i <= num; i++){
        insertLast(i);
    }
    head->prev = tail;
    tail->next = head;
 		R(head,num, key);
    return 0;
}
