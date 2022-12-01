#include <stdio.h>
#include <stdlib.h>
typedef int element;
//1) 노드의 구조체 정의
typedef struct Node{
	element data;
	struct Node *link;
}Node;
//2) 스택리스트의 시작 구조체 정의
typedef struct {
	Node *top;
}SList;

void init(SList *s){
	s->top = NULL;
}
int isEmpty(SList* s){
	return (s->top == NULL);
}
int isFull(SList* s){
	return 0;
}

void push(SList *s, element data)
{
	Node *temp = (Node *)malloc(sizeof(Node)); // 동적할당
	temp->data = data;
	temp->link = s->top;
	s->top = temp;
}

int pop(SList *s)
{
	if(isEmpty(s)){ // 스택이 비어 있는지 확인
		printf("stack empty\n");
	}
	else{
		Node *temp = s->top; // temp포인터를 top노드를 가르키도록 함
		int data= temp->data; // 삭제한 값 반환하기 위해서 기존의 데이터를 temp노드에 삽입
		s->top = s->top->link; // top 노드는 기존의 top노드가 가르키는 노드가 됨
		free(temp);
	}
}

void printList(SList* s){
	Node* p = s->top;
	while(p!=NULL){
		printf("%d->",p->data);
		p = p->link;
	}
	printf("NULL\n");
}

int main() {
	SList s;
	init(&s);
	push(&s,1); printList(&s);
	push(&s,2); printList(&s);
	push(&s,3); printList(&s);
	pop(&s); printList(&s);
	pop(&s); printList(&s);
	pop(&s); printList(&s);
	return 0;
}