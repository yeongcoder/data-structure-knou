#include <iostream>

struct KNode {
    struct KNode *left;
    char key[10];
    int info;
    struct KNode *right;
};

/*중위순회연산 LPR*/
void Inorder(struct KNode *rootptr){
    if(rootptr != NULL){
        Inorder(rootptr->left);
        printf("%d", rootptr->info);
        Inorder(rootptr->right);
    }
}

/*이진탐색트리 탐색*/
struct KNode *Search (char k[], struct KNode *r){
    if(r == NULL){
        return(NULL);
    } else {
        if(strcmp(k, r->key) == 0){
            return (r);
        } else if(strcmp(k, r->key) < 0){
            return Search(k, r->left);
        } else {
            return Search(k, r->right);
        }
    }
}


/*삽입연산*/
struct KNode *Insert(struct KNode *newptr, struct KNode *r){
    if(r == NULL){
        return (newptr);
    } else {
        if(newptr->key == r->key){              // newptr->key == r->key
            //DUPLICATE_ENTRY();
        } if(newptr->key > r->key) {            // newptr->key < r->key
            r->left = Insert(newptr, r->left);
        } else {                                // newptr->key > r->key
            r->right = Insert(newptr, r->right);
        }
    }
    return(r);
}