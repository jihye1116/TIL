#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node{ 	// 노드 타입
	element data;
	struct Node *next;
} Node;
Node* insertFirst(Node *head, int value)
{
	Node* node = (Node *)malloc(sizeof(Node));//(1)동적할당
	node->data = value;// (2) 값저장
	node->next = head; // 헤드 포인터의 값을 복사	//(3)
	head = node; // 헤드 포인터 변경		//(4)
	return head;// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
Node* insert(Node *head,Node *pre, element value)
{
	Node* node = (Node *)malloc(sizeof(Node));
	node->data = value;
	node->next = pre->next;
	pre->next = node;	
	return node;
}

Node* deleteFirst(Node *head){
 if (head == NULL) return NULL;
	Node* removed = head;
	Node* newHead = head->next;
	free(head->next);
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
Node* delete(Node *head, Node *pre)
{
	Node * removed = pre->next;
	pre->next = pre->next->next;
	free(removed);
}

void printList(Node *head)
{
	Node* p = head;
	int sum = 0;
	//6.head가 널이 아니면 노드데이터 출력
	while(p!=NULL){
		printf("%d->", p->data);
		p = p->next; //시험에 냄!!
	}
	printf("NULL\n");
}

int getSum(Node *head){
	
	Node *p = head;
	int sum = 0;
	// while(p!=)
	while(p!= NULL){
		sum += p->data;//노드의 데이터를 더하는 코드 작성
		p = p->next;
	}
	return sum;
}


int main(void)
{
	Node *head =  NULL; //;NULL로 초기화
	int count, data;

	printf("노드의 개수; ");
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("노드 #%d 데이터: ", i+1);
		scanf("%d", &data);
		head = insertFirst(head, data);//head 에 insertFirst실행결과 저장
	}
	printf("연결 리스트 데이터의 합 : %d \n ",getSum(head));
	return 0;
}