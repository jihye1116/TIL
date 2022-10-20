#include<stdio.h>
#include<string.h>
#define NUM 3

//전역에 구조체 정의
typedef struct Person{ //전역에 구조체 정의
	char name[10];
	int age;
}PERSON;
void inputData( PERSON *p );
void outputData( PERSON *p );	

int main(){
		//구조체 포인터 배열 선언
	int i;
	printf("%d", p[0].age);
	
	for(i=0; i<3; i++){
		inputData(&p[i]);
	}
	for(i=0; i<3; i++){
		outputData(&p[i]);
	}
	//구조체포인터 배열로 입력함수 호출
			//구조체포인터 배열로 출력함수 호출
		return 0;
}
void inputData( PERSON *p ){
	//구조체포인터 변수에 입력
	// scanf("%s", (*p).name);
	scanf("%s", &p->name);
	scanf("%d", &p->age);
	
}
void outputData( PERSON *p ){
		//구조체포인터 변수에 출력
	printf("%s, %d\n", p->name, p->age);

} 