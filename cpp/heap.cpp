#include <iostream>

#define MAX_DATA 7

typedef struct {
    int heap[MAX_DATA];
    int heap_size;
} HeapType;

/*힙에서 노드 삭제(최소힙)*/
int deleteHeap(HeapType *h){
    int parent, child;
    int item, temp;
    item = h->heap[1]; // 루트노드 꺼냄 (첫번쨰 인덱스가 1부터 시작일때)
    temp = h->heap[(h->heap_size)--]; // 마지막 노드 꺼내고 사이즈 줄임
    parent = 1; child = 2;

    while(child <= h->heap_size){
        if((child < h->heap_size) && (h->heap[child] > h->heap[child+1])){ //비교를 위한 child 인덱스는 힙의 크기보다 작아야 함. 오른쪽 왼쪽 자식중 작은 것을 비교하기 위한 조건문
            child++; //오른쪽 자식과 왼쪽 자식 중 가장 작은 값의 인덱스값
        } if(temp <= h->heap[child]){ //끝노드인 temp걊과 chil값을 비교하여 temp가 더 작으면 중단
            break;
        }
        h->heap[parent] = h->heap[child]; //부모값을 자식값으로 대체
        parent = child; //부모인덱스를 자식인덱스로 대체
        child *= 2; //기존 자식인덱스에서 한레벨 내려감
    }
    h->heap[parent] = temp; //chil보다 temp가 더 작으니 child의 부모로 temp를 할당
    return item; //삭제된 노드 반환
}

/*힙에 노드 삽입(최소힙)*/
void insertHeap(HeapType *h, int item){
    int i;
    i = ++(h->heap_size); //새로 추가될 노드는 맨 마지막에 위치

    while((i != 1) && (item < h->heap[i/2])){ //맨마지막의 부모노드와 추가될 노드 비교
        h->heap[i] = h->heap[i/2]; //추가 될 노드가 더 작으면 부모노드의 값을 노드가 추가될 위치에 복사
        i /= 2; //추가될 위치를 부모노드의 값으로 변경
    }
    h->heap[i] = item;
}

int main(void){
    HeapType* H = (HeapType*)malloc(sizeof(HeapType));
    insertHeap(H, 1);
    insertHeap(H, 2);
    insertHeap(H, 3);
    insertHeap(H, 9);
    insertHeap(H, 10);
    insertHeap(H, 12);

    //프로그래머스 고득점kit > heap > 더맵게 begin
    int count = 0;
    int K = 7;
    int deletedItem1;
    
    while (deletedItem1 = deleteHeap(H) < K){
        int deletedItem2 = deleteHeap(H);
        int calculatedItem = deletedItem1 + deletedItem2 * 2;
        insertHeap(H, calculatedItem);
        count++;
    }

    for(int i = 0; i < MAX_DATA; i++){
        printf("%d, ", H->heap[i]);
    }
    printf("\n");

    printf("count: %d", count);
    //프로그래머스 고득점kit > heap > 더맵게 end

}