#include <iostream>

struct node {
    struct node *left;
    struct node *right;
    int info;
};

struct node *nodeptr;

/*전위순회*/
void preorder(struct node *tree_ptr){
    if (tree_ptr){
        printf("%d", tree_ptr->info);
        preorder(tree_ptr->left);
        preorder(tree_ptr->right);
    }
}

/*중위순회*/
void inorder(struct node *tree_ptr){
    if (tree_ptr){
        preorder(tree_ptr->left);
        printf("%d", tree_ptr->info);
        preorder(tree_ptr->right);
    }
}

/*후위순회*/
void preorder(struct node *tree_ptr){
    if (tree_ptr){
        preorder(tree_ptr->left);
        preorder(tree_ptr->right);
        printf("%d", tree_ptr->info);
    }
}

/*노드 개수 계산*/
int get_node_counter(node *root){
    if (root == NULL) return 0;
    int result = 1;
    result += get_node_counter(root->left)
            +
            get_node_counter(root->right);

    return result;

}