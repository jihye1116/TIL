#include <stdio.h>
#include <stdlib.h>
// 구조체 설정
typedef struct Node{
    char data;
    struct Node *left;
    struct Node *right;
}node;
// 노드 생성
node *makeNode(char ch){
    node *nd = (node*)malloc(sizeof(node));
    nd->data = ch;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}
// 이미 넣은 알파벳인지 확인 후 넣기
node *searchNode(node *nd, char ch){
    if(nd != NULL){
        if(nd->data == ch){
            return nd;
        }
        else{ // 왼쪽 뒤지고, 없으면 오른쪽 뒤짐
            node *ndd = searchNode(nd->left, ch);
            if(ndd != NULL){
                return ndd;
            }
            else
                return searchNode(nd->right, ch);
        }
    }
    else
        return NULL;
}
// 노드에 값 집어넣기
void setNode(node *nd, char fir, char sec, char thr){
    nd->data = fir;
    if (sec != '.'){
        nd->left = makeNode(sec);
    }
    if(thr != '.'){
        nd->right = makeNode(thr);
    }
}
 
void preorder(node* root){
	if(root != NULL){
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// 중위 순회
void inorder(node* root)
{
	if(root != NULL){
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

// 후위순회
void postorder(node* root)
{
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

int main() {
    int n;
    char a, b, c; // 노드와 왼쪽자식, 오른쪽 자식 노드
    node *tree = makeNode(NULL); 
    node *tree2;
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        scanf("%c %c %c", &a, &b, &c);
        getchar();
				tree2 = searchNode(tree, a);   
        if(tree2 != NULL){
            setNode(tree2, a, b, c);
        }
        else{
            setNode(tree, a, b, c);
        }
    }

    preorder(tree); // 전위
    printf("\n");
    inorder(tree); // 중위
    printf("\n");
    postorder(tree); // 후위
    return 0;
}
``