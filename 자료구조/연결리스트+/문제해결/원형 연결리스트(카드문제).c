#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct Node{
	element data;
	struct Node* next;
}Node;

Node* insertFirst(Node* head, element data){
	Node* node = (Node *)malloc(sizeof(Node));
	node->data = data; //
	if (head == NULL){
		head = node;
		node->next = node;
	}
	else{
		node->next = head->next;
		head->next = node;
	}
	return head;
}
Node* insertLast(Node* head, element data){
	Node* node = (Node *)malloc(sizeof(Node));
	node->data =data;
	if (head == NULL){
		head= node;
		node->next= node;
	}
	else{
		node->next = head->next;
		head->next = node;
		head =  node;
	}
	return head;
}

void printList(Node* head){
	Node *p = head->next;
	
	int cnt = 0;
	if (head == NULL) return;
	do {
		if(p == NULL) break;
		printf("%d->", p->data);
		p = p->next;
		cnt++;
	} while(p != head->next);
	printf("\n");
}

Node* changeCard(Node* head){
	Node* removed = head->next;
	head->next = head->next->next;
	return head->next;
}


int main() {
	Node *head=NULL;
	int n;
	printf("카드개수 입력\n");
	scanf("%d", &n);
	for(int i = 1;i<= n;i++){
		head = insertLast(head, i);
	}
	
	while(head->next != head){
		head = changeCard(head);
		printList(head);
	}
	
	printf("마지막 카드번호 : %d", head->data);
	
	return 0;
}


