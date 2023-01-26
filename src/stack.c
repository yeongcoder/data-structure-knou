#include <stdio.h>

#define STACK_SIZE 10

/*스택 생성*/
typedef char element;
element stack[STACK_SIZE];
int top = -1;

/*스택 비어있는지 확인*/
int IsEmpty(){
    if(top == -1){
        return 1;
    } else {
        return 0;
    }
}

/*스택 삭제 연산*/
element pop(){
    if (top == -1){
        printf("Stack is Empty!!\n");
        return 0;
    } else {
        return stack[top--];
    }
};

/*스택 삽입 연산*/
void push(element *stack, char item){
    if (top >= STACK_SIZE - 1){
        printf("Stack is full!!\n");
        return;
    } else {
        stack[++top] = item;
    }

}

/*스택 탑요소 확인 연산*/
element peek(){
    if (top == -1){
        printf("Stack is Empty!!\n");
        return 0;
    } else {
        return stack[top];
    }
}



/*모든 스택 출력*/
void retrive(element *stack, int *top){
    for(int i = *top; i < sizeof(stack); i--){
        printf("%d >", stack[i]);
    }
    printf("\n");
}


/*중위표기식을 후위표기식으로 변환하는 알고리즘*/
const char* infixTopostfix(char *infix){
    
    char output[10] = {};
    char token[2] = {};

    token[0] = infix[0];

    for(int i = 0; i < strlen(infix); i++){
        token[0] = infix[i];
        printf("token: %c\n", token[0]);

        if( //토큰이 연산자가 아닌경우
            token[0] != '+' &&
            token[0] != '-' &&
            token[0] != '*' &&
            token[0] != '/'
        ){
            token[1] = '\0';
            strcat(output, token);

        } else { //토큰이 연산자인경우

            if(IsEmpty()){

                push(stack, token[0]);

            } else {
                if( //현재 토큰이 스택의 탑값보다 우선순위가 높은경우
                    (token[0] == '*' || token[0] == '/') &&
                    (peek() == '+' || peek() == '-')
                ){

                    push(stack, token[0]);

                } else {
                    while( //현재 토큰이 스택의 탑값보다 우선순위가 낮은경우
                        (token[0] == '+' || token[0] == '-') &&
                        (peek() == '*' || peek() == '/')
                    ){
                        element popedChar[2] = {};
                        popedChar[0] = pop();
                        popedChar[1] = '\0';
                        strcat(output, popedChar);
                    }

                    if(
                        (token[0] == '*' || token[0] == '/') &&
                        (peek() == '+' || peek() == '-')
                    ){

                        push(stack, token[0]);

                    } else {
                        strcat(output, token);
                    }

                }
            }

        }

        printf("stack: %s\n", stack);
        printf("output: %s\n", output);
        printf("=================================\n");

    }


    printf("before output: %s\n", output);

    if(!IsEmpty()){ //스택에 연산자가 남아있으면 모두 문자열 뒤에 붙여줌
        while(top != -1){
            element popedChar[2] = {};
            popedChar[0] = pop();
            popedChar[1] = '\0';
            strcat(output, popedChar);
            printf("final output!!!!: %s\n", output);
        }
    }

    return (const char*)output;

}

element evalPostfix(char* exp){
    int oper1, oper2, value, i=0;
    int length = strlen(exp);
    char symbol;
    top = -1;
    for(i = 0; i < length; i++){
        symbol = exp[i];
        if(symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/'){
            value = symbol - '0';
            push(stack, value);
        } else {
            oper2 = pop();
            oper1 = pop();
            switch(symbol){
                case '+': push(stack, oper1 + oper2); break;
                case '-': push(stack, oper1 - oper2); break;
                case '*': push(stack, oper1 * oper2); break;
                case '/': push(stack, oper1 / oper2); break;
            }

        }
    }

    return pop();
}

int main(void){
    // push(stack, 1);
    // push(stack, 2);
    // printf("peek: %d\n", peek());
    // push(stack, 3);
    // push(stack, 4);
    // retrive(stack, &top);
    // pop();
    // retrive(stack, &top);
    // pop();
    // printf("peek: %d\n", peek());
    //retrive(stack, &top);

    // printf("%d",evalPostfix("842/-54*-"));

    // printf("%d", infixTopostfix("8-4/2-5*4"));

    // ABC/-DE*-
}