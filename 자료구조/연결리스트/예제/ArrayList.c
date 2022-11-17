#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 //리스트의 최대크기
typedef int element;
//배열리스트 구조체타입 정의
typedef struct{
   element array[MAX_LIST_SIZE];
   int size;
} ArrayListType;
//오류 처리 함수
void error(char *m){
   fprintf(stderr,"%s\n",m);
   exit(1);
}
void init(ArrayListType* L){ //배열리스트 초기화
  L->size = 0;
}
//리스트가 비어 있으면 1을 반환   
//그렇지 않으면 0을 반환
int isEmpty(ArrayListType* L){
   return L->size == 0;  
}
int isFull(ArrayListType* L){
    return L->size == MAX_LIST_SIZE;
}
element getEntry(ArrayListType* L, int pos){
     if(pos < 0 || pos >= L->size)
       error("위치 오류");
   return L->array[pos];
}
//list출력
void printList(ArrayListType* L){
   for(int i=0;i<L->size;i++)
      printf("%d->",L->array[i]);
   printf("\n");
}
void insertLast(ArrayListType* L, element item){
   if(isFull(L)){
      printf("리스트 오버플로우\n");
   }
   else{
      L->array[L->size++] = item;
   }
}
void insert(ArrayListType* L, int pos, element item){
   int i;
   if(isFull(L)){
      printf("리스트 오버플로우\n");
   }
   else if(pos >= 0 && pos <= L->size){
      for(i = (L->size - 1); i >= pos; i--){
         L->array[i + 1] = L->array[i];
      }
      L->array[pos] = item;
      L->size++;
   }
}
element delete(ArrayListType* L,int pos){
   element item;
   
   if(pos < 0||pos >= L->size){
      error("위치 오류");
   }
   item = L->array[pos];
   for (int i = pos; i < (L->size - 1); i++){
      L->array[i] = L->array[i + 1];
   }
   L->size--;
   return item;
}
int main(){
   ArrayListType list;
   
   init(&list);
   insertLast(&list, 10);
   printList(&list);
   insertLast(&list, 20);
   printList(&list);
   insertLast(&list, 30);
   printList(&list);
   insertLast(&list, 40);
   printList(&list);
   insert(&list,2,100);
   printList(&list);
   delete(&list, 1);
   printList(&list);
   
   return 0;
}