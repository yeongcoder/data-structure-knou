#include <iostream>

typedef struct ListNode {
    int data;
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void){
    linkedList_h* H;
    H = (linkedList_h*)malloc(sizeof(linkedList_h));
    H -> head = NULL;
    return H;
}

/*노드삽입*/
void addFirstNode(linkedList_h* H, int x){
    listNode* tempNode;
    listNode* NewNode;

    NewNode = (listNode*)malloc(sizeof(listNode));
    NewNode -> data = x;
    NewNode -> link = NULL;

    if ( H -> head == NULL){
        H -> head = NewNode;
        NewNode -> link = NewNode;
        return;
    }

    tempNode = H -> head;
    while(tempNode -> link != H -> head){
        tempNode = tempNode -> link;
    }
    NewNode -> link = tempNode -> link;
    tempNode -> link = NewNode;
    H -> head  = NewNode;

}

/*prev노드 바로 다음 노드 삭제*/
void deleteCircularNode(linkedList_h* H, listNode* prevNode){
    listNode* delNode;
    delNode = prevNode -> link;
    prevNode -> link = delNode -> link;
    if (delNode == H -> head) H -> head = delNode -> link;
    free(delNode);
}