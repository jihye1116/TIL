#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100
typedef int element; //int를 element로 재정의
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;

}Stack;

// element	stack[MAX_STACK_SIZE]; //1차원 배열로 스택 정의
// int	stack[MAX_STACK_SIZE]; //1차원 배열로 스택 정의

//전역변수로 스택 선언
// int top = -1;

Stack s;

bool isEmpty(){ //스택이 가득 차 있는가?
	if(s.top == -1) return 1;
	else return 0;
}
bool isFull(){ //스택이 공백상태인가?
	if(s.top == MAX_STACK_SIZE-1)
		return 1;
	else return 0;
}
void push(element item){ // 스택이 full이 아닐 때 data를 스택에 삽입
	s.top++;
	s.stack[s.top] = item;
}

element pop(){ //스택의 원소 출력 후 제거
	element temp;
	temp = s.stack[s.top];
	s.top--;
	return temp;
}

element peek(){ //스택의 원소 출력(반환)
	return s.stack[s.top];
}
int main(){
	push(1);
	push(2);
	push(3);
	printf("%d\n",pop());
	printf("%d\n",peek());
	printf("%d\n",pop());
	return 0;

}
