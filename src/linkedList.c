#include <stdio.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

/*노드생성*/
linkedList_h* createLinkedList_h(void){
    linkedList_h* H;
    H = (linkedList_h*)malloc(sizeof(linkedList_h));
    H -> head = NULL;
    return H;
}

/*노드 삽입*/
void addNode(linkedList_h* H, int x){
    listNode* NewNode;
    listNode* LastNode;
    NewNode = (listNode*)malloc(sizeof(listNode));
    NewNode -> data = x;
    NewNode -> link = NULL;
    if(H -> head ==  NULL){
        H -> head = NewNode;
        return;
    }
    LastNode = H -> head;
    while(LastNode->link != NULL){
        LastNode = LastNode->link;
    }
    LastNode -> link = NewNode;
}

/*노드 삭제*/
void deleteNode(linkedList_h* H){
    listNode* prevNode;
    listNode* delNode;
    if(H -> head == NULL) {
        return;
    }
    if(H -> head -> link == NULL){
        free(H -> head);
        H -> head = NULL;
        return;
    } else {
        prevNode = H -> head;
        delNode = H -> head -> link;
        while(delNode -> link != NULL){
            prevNode = delNode;
            delNode = delNode -> link;
        }
        free(delNode);
        prevNode -> link = NULL;
        return;
    }
}

/*preNode 바로 뒤에 노드 삽입*/
void additNode(linkedList_h* H, listNode* prevNode, int itdata){
    listNode* NewNode;
    NewNode = (listNode*)malloc(sizeof(listNode));
    NewNode -> data = itdata;
    NewNode -> link = NULL;

    NewNode -> link = prevNode -> link;
    prevNode -> link = NewNode;
    return;
}

/*특정 노드 검색*/
void searchNode(linkedList_h* H, int itdata){
    listNode* tempNode;
    tempNode = H -> head;
    while(tempNode -> data != itdata){
        tempNode = tempNode -> link;
    }
    printf("Search successfull!! \n");
}

/*노드 출력*/
void retrieve(linkedList_h* H){
    listNode* tempNode = H -> head;
    while(tempNode != NULL){
        printf("[%d] -> ", tempNode->data);
        tempNode = tempNode -> link;
    }
    printf("\n");
    return;
}

int main(void){
    linkedList_h* H = createLinkedList_h();
    addNode(H, 1);
    addNode(H, 2);
    addNode(H, 3);
    addNode(H, 4);
    addNode(H, 5);
    retrieve(H);
    deleteNode(H);
    deleteNode(H);
    deleteNode(H);
    retrieve(H);

    return 0;
}