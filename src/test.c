#include <stdio.h>

#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

// int 배열의 사이즈를 구하는 함수
int len(int *arr){
    return SIZEOF(arr);
}

// char배열의 사이즈를 구하는 함수
int len(char *arr){
    return SIZEOF(arr);
}

int main(void){
    int arr[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    int * list = &arr[0];

    printf("%p\n",arr);
    printf("%p\n",list);

    printf("%d", arr[0]);
    printf("%d", list[0]);

    printf("%d", arr[1]);
    printf("%d", *arr+1);

    printf("%d", len(arr));

    return 0;
}