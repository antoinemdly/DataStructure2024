#include <stdlib.h>

#include "tree.h"
#include "./../list/list.h"
#include "./../queue/queue.h"
#include "./../stack/stack.h"

Tree *tree_create(){
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;

    return tree;
}

TreeNode *tree_search(Tree *tree, void *data, int (*cmp)(void *, void *)){
    if (tree->root == NULL){
        return NULL;
    }
    TreeNode *current = tree->root;

    while (current != NULL){
        switch(cmp(data, current->data)){
            case -1:
            {
                current = current->left;
                break;
            }
            case 0:
            {
                return current->data;
            }
            case 1:
            {
                current = current->right;
                break;
            }
        }
    }
    return NULL;
}

void tree_destroy(Tree *tree){
    Stack *stack = stack_create();
    while(tree->root->left != NULL && tree->root->right == NULL){
        
    }
}

void tree_insert(Tree *tree, void *data, int (*cmp)(void *, void *));
List *tree_bfs(Tree *tree);
List *tree_dfs(Tree *tree);