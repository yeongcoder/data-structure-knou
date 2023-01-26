#include <stdio.h>  

/*m원탐색트리의 노드*/
struct mnode {
    int n;                      // 키값의 개수 (m원 탐색트리일때 항상 n-1 <= m가 성립)
    struct rectype {
        struct mnode *ptr;      // 후속노드를 가리키는 포인터
        int key;                // 키값
        struct Rectype *addr;   // 키값에 대응되는 내용을 가리키는 포인터
    } keyptrs[n - 1];           // 해당 구조체를 가지고 있는 배열
    struct mnode *keyptrn;      // 마지막 포인터 값 (왜냐면 m원 탐색트리는 n개의 포인터와 n-1개의 키값이 존재 이들은 쌍으로 묶으면 1개의 포인터가 남음)
};

struct mnode *nodeptr;
struct rectype *recptr;

/* m원탐색트리의 검색 알고리즘 */
struct rectype *Search(int skey, struct mnode *r){
    int i;
    extern struct mnode node;
    if(r==NULL){                                      // 루트가 존재하지 않으면 종료
        return (NULL);                                // 널값 리턴
    } else {                                          // 루트가 존재하면
        i = 0;                                        // 노드의 있는 키값과의 순차비교를 위한 인덱스 i값 선언
        while(i < r->n && skey > r->keyptrs[i].key)   // 키값의 개수n-1만큼만 반복을 돌면서 찾고자하는 키값보다 크거나 같은 키값을 찾을때까지 반복
            i++;                                      // 순차비교를 위한 인덱스 값증가
        if(i < r->n && skey == r->keyptrs[i].key)     // 반복이 끝났다면 해당 키값은 찾고자 하는 키값보다 크거나 같은 값이니깐 같은 경우 키를 찾은 것이니 해당 키값의 자료형의 주소 반환
            return (r->keyptrs[i].addr);              // 찾은 키값의 자료형의 주소 반환
        else if(i < r->n)                             // 반복을 다 돌기전에 찾고자 하는 키값보다 큰값을 만났다면
            return (Search(skey, r->keyptrs[i].ptr)); // 그 키값 보다 큰 값을 노드로 갖는 서브트리의 포인터값을 형식매개변수 r로 넣어 재귀호출
        else                                          // 반복을 다 돌았는데도 못찾으면 경우
            return (Search(skey, r->keyptrn));        // 가장 마지막 마지막 포인터 값을 형식매개변수 r로 넣어 재귀호출
    }
}