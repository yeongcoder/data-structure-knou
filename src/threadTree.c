#include <stdio.h>

/*
스레드 트리 구현방법
    별도의 스레드 포인터 추가:
        오른쪽스레드포인터: 정해진순회 방법에 따른 후속노드를 가리킴
        왼쪽스레드포인터: 부모노드를 가리킴
    잎 노드의 빈 포인터 활용:
        스레드플레그: 왼쪽 포인터가 현재 스레드인지 아닌지 판단하는 플레그 1이면 스레드 0이면 왼쪽 자식노드
*/

/*별도의 스레드 포인터를 추가한 스레드 트리*/
struct TNode {
    int info;
    struct TNode *left;
    struct TNode *right;
    struct TNode *right_thread;
    struct TNode *left_thread;
};

/*잎노드의 빈 포인터를 활용한 스레드 트리*/
struct TFNode {
    int info;
    struct TFNode *left;
    struct TFNode *right;
    int threadFlag;
};

/*잎노드의 빈 포인터를 활용한 전위순회 스레드 트리의 전위순회*/
void Preordthr(struct TFNode *root){
    struct TFNode *p;
    p = root;
    while(p != NULL){
        printf("%d", p -> info);
        p = p -> left;
    }
}

/*별도의 스레드 포인터를 추가한 스레드트리의 중위순회*/
void inorder(struct TNode *firstin){
    struct TNode *p;
    p = firstin;
    while(p != NULL) {
        printf("%d", p -> info);
        p = p -> right_thread;
    }
}

/*별도의 스레드 포인터를 추가한 중위순회 스레드트리의 오른쪽 삽입연산*/
void Inesert(struct TNode *x, struct TNode *ttree){ // ttee = 삽입 할 노드, x = 삽입 할 노드의 부모가 될 노드
    ttree->left = NULL;
    ttree->right = x->right;
    ttree->left_thread = x; //왼쪽스레드가 선행노드를 가리키게 함
    ttree->right_thread = x->right_thread; // 오른쪽 스레드가 후속노드를 가리키게 함
    x->right = ttree;
    x->right_thread = ttree;
}