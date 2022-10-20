#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
	char name[20];
	int* p;
} data;

int main()
{
	int n = 50;
	data d1;
	data *d2 = (data*)malloc(sizeof(data));
	d1.p = &n;
	d2->p = &n;
	printf("%d\n", *d1.p + *d2->p ); //구조체멤버를 역참조, 100
	strcpy(d2->name,"hobby");
	printf("%s\n", (*d2).name); //구조체멤버를 역참조 hobby
	printf("%c\n", *(*d2).p); // 2

	free(d2);

	return 0;
}