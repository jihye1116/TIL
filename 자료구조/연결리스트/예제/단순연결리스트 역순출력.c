#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef int element;

//
typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
	p->data = value;//(2)
	p->link = head;	// 헤드 포인터의 값을 복사//(3)
	head = p;		// 헤드 포인터 변경//(4)
	return head;
}

//
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link){
		if(p->link==NULL){
			printf("%d", p->data);
		} else {
		printf("%d->", p->data);
		}
	}
	printf("\n");
}

ListNode* reverse(ListNode* head)
{
	ListNode* p, * q, * r;
	p = head;   
	q = NULL;        
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r; 
	}
	return q;
}

// 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;
	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	head = insert_first(head, 40);
	print_list(head);
	head = insert_first(head, 50);
	print_list(head);

	printf("역순으로 출력\n");
	head = reverse(head);
	print_list(head);

	return 0;
}