#include <iostream>

/*큐 생성*/
#define QUEUE_SIZE 5
typedef int element;
element queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

/*원형큐 삽입*/
void Add_q(element item){
    if(rear == QUEUE_SIZE -1){
        printf("Queue is full!!");
        return;
    }
    queue[(++rear)%QUEUE_SIZE] = item;
    return;
}

/*원형큐 삭제*/
element Delete_q(){
    if(front == rear){
        printf("Queue is empty!!");
        return 0;
    }
    return (queue[(++front)%QUEUE_SIZE]);
}

/*큐출력*/
void retrieve(){
    printf("queue: ");
    for(int i = 0; i < QUEUE_SIZE; i++){
        printf("%d", queue[i]);
    }
    printf("\n");
    
}


int main(void){
    Add_q(1);
    Add_q(2);
    Add_q(3);
    Add_q(4);
    Delete_q();
    Delete_q();
}