#include <stdio.h>

int compare(int x, two_three_ptr t);
void new_root(two_three_ptr lt, int y, two_three_ptr mt);
two_three find_node(two_three_ptr t, int y);
void put_in(two_three_ptr p, int y, two_three_ptr q);
void split(two_three_ptr p, int *y, two_three_ptr q);

typedef struct two_three *two_three_ptr;
struct two_three {
    int lkey, rkey; // 진출차수의 개수가 2개 에서 3개 이므로 key의 개수는 최대 2개 따라서
    two_three_ptr lchild, mchild, rchild; //진출차수의 최대 개수는 3개
};

int compare(int x, two_three_ptr t){
    if(t->lkey > x){
        return 1;
    } else if(t->lkey < x && t->rkey > x){
        return 2;
    } else if(t->rkey < x){
        return 3;
    } else {
        return 4;
    }
}

two_three_ptr serach23(two_three_ptr t, int x){
    while(t){
        switch(compare(x,t)){
            case 1: t = t->lchild; // t->lkey > x
                break;
            case 2: t = t->mchild; // t->lkey < x and t->rkey > x
                break;
            case 3: t = t->rchild; // t->rkey < x
                break;
            case 4: return (t);
        }
    }
    return (NULL);
}

void insert23(two_three_ptr t, int y){
    two_three_ptr q, p, r;
    if (!t){ //트리가 비어있는 경우
        new_root(t, y, NULL); // 2-3트리의 첫노드를 생성할 떄 호출하는 함수로 매개변수로 lchild, 자신의키값, mchild를 받고 새루트의 포인터는 첫번쨰 매개변수로 반환
    } else {
        p = find_node(t, y); //키값 y가 트리t에 있다면 NULL반환 y를 찾을때까지 방문한 부모노드들을 전역 스택에 담아 저장하고 있음, p는 잎노드를 반환(스택의 top)
        if(!p){ // 키값 y가 트리 t에 존재
            fprintf(stderr, "The key is currently in the tree \n");
            exit(1);
        }
        q = NULL; //새로운 노드가 들어갈 포인터 변수
        for(;;){
            if(p->rkey == INT_MAX){ // INT_MAX는 NULL값으로 보자 즉 해당 조건문은 p의 rkey값이 비어있우면
                put_in(p, y, q); //노드 p에 y를 삽입하는 함수. 우선 y의 오른쪽에 서브트리 q를 놓고 y가 lkey이면 q는 mchild
                break;
            } else { //p의 오른쪽 키값이 NULL이 아님
                split(p, &y, q); //p가 가리키는 노드를 분리후 y값의 교체가 일어남 즉 기존 y값은 삽입이 된 상태고 트리의 형태를 고치는 과정 수행
                if(p == t){ //p가 루트노드라면 
                    new_root(t, y, q); //새로운 부모 노드를 만들어 루트로 둠
                    break;
                } else {
                    p = stack.pop(); // 전역 스택에서 pop하여 p가 부모노드를 가리키게 함
                }

            }
        }
    }
}