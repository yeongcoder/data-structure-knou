#include <iostream>

typedef struct ListNode {
    struct ListNode* Llink;
    int data;
    struct ListNode* Rlink;
} listNode;

typedef struct {
    listNode* Lhead;
    listNode* Fhead;
} linkedList_h;

/*이중 연결 리스트 생성*/
linkedList_h* crateLinkedList_h(void){
    linkedList_h* H;
    H = (linkedList_h*)malloc(sizeof(linkedList_h));
    H -> Lhead = NULL;
    H -> Fhead = NULL;
    return H;
}

/*노드 삽입*/
void addDNode(linkedList_h* H, listNode* prevNode, int x){
    listNode* NewNode;

    NewNode = (listNode*)malloc(sizeof(listNode));
    NewNode -> Llink = NULL;
    NewNode -> data = x;
    NewNode -> Rlink = NULL;

    NewNode -> Rlink = prevNode -> Rlink;
    prevNode -> Rlink = NewNode;
    NewNode -> Llink = prevNode;
    NewNode -> Rlink -> Llink = NewNode;
}

/*노드 삭제*/
void deleteDNode(linkedList_h* H, listNode* delNode){
    delNode -> Llink -> Rlink = delNode -> Rlink;
    delNode -> Rlink -> Llink = delNode -> Llink;
    free(delNode);
}