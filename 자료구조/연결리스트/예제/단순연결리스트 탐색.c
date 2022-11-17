 #include <stdio.h>//201p(단어입력) + 203(탐색)
#include <stdlib.h>
#include<string.h>
typedef struct Node{
	char data[100];
	struct Node* next;
}Node;
Node* insertFirst(Node* head, char* data){
	Node* node = (Node *)malloc(sizeof(Node));
	//node->data = data;
	strcpy(node->data, data);
	node->next = head; 
	head = node; 
	return head;
}
Node* insert(Node* head, Node* pre, char* data){
	Node* node = (Node *)malloc(sizeof(Node));
	//node->data = data;
	strcpy(node->data, data);
	node->next = pre->next;
	pre->next =  node; 
}
Node* deleteFirst(Node* head){
	 if (head == NULL) return NULL;
	 Node* removed = head;
   Node* newhead = head -> next;
   free(removed);
	 removed = NULL;
   return newhead;
}
Node* delete(Node* head, Node* pre){
	//프리가 가리키는 다음 노드를 삭제
	Node* removed = pre->next;
	pre->next = pre->next->next;
	free(removed);
}
void printList(Node* head){
	while(head!=NULL){
		printf("%s->", head->data);
		head = head->next;
	}
	printf("NULL\n");
		
}
int main(){
	Node* head = NULL;
	Node* p;
  char str[3][10] ={"melon","kiwi","apple"};
	char find[10];
	//코드 작성
	head= insertFirst(head,str[0]); //melon 입력
	printList(head);
	head= insertFirst(head,str[1]); //
	printList(head); //
	head= insertFirst(head,str[2]); //
	printList(head); //
	
	//수정할 부분
	printf("찾을 데이터를 입력하세요\n");
	scanf("%s",find);
	for(p=head;p!=NULL;p=p->next){
		//printf("%s",p->data);
		if	(strcmp(p->data,find) == 0) printf("%s를 찾았습니다.",find);
	}
	return 0;
}

