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
                return current;
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
    if (tree->root == NULL){
        free(tree);
    }
    else{
        Queue *queue = queue_create();
        queue_enqueue(queue, tree->root);
        TreeNode *current;

        while (queue_size(queue) > 0){
            current = queue_dequeue(queue);
            if(current->left != NULL){
                queue_enqueue(queue, current->left);
            }
            if(current->right != NULL){
                queue_enqueue(queue, current->right);
            }
            free(current);
        }

    queue_destroy(queue);
    
    }

    free(tree);
    
}

void tree_insert(Tree *tree, void *data, int (*cmp)(void *, void *)){
    TreeNode *newnode = malloc(sizeof(TreeNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if (tree->root == NULL){
        tree->root = newnode;
        return;
    }
    else{
        TreeNode *current = tree->root;
        TreeNode *parent = NULL;

        while (current != NULL){
            parent = current;
            switch(cmp(data, current->data)){
                case -1:
                {
                    current = current->left;
                    break;
                }
                case 0:
                {
                    free(newnode);
                    return;
                }
                case 1:
                {
                    current = current->right;
                    break;
                }
            }
        }
        if (cmp(data, parent->data) < 0) {
            parent->left = newnode;
        } else {
            parent->right = newnode;
        }
    }
}

List *tree_bfs(Tree *tree){
    List *list = list_create();
    Queue *queue = queue_create();
    TreeNode *current;

    if(tree->root == NULL){
        return NULL;
    }

    queue_enqueue(queue, tree->root);

    while (queue_size(queue) > 0){
        current = queue_dequeue(queue);
        if(current->left != NULL){
            queue_enqueue(queue, current->left);
        }
        if(current->right != NULL){
            queue_enqueue(queue, current->right);
        }
        list_append(list, current->data);
    }

    queue_destroy(queue);

    return list;
}

List *tree_dfs(Tree *tree){
    if(tree->root == NULL){
        return NULL;
    }

    List *list = list_create();
    Stack *stack = stack_create();
    TreeNode *current;

    stack_push(stack, tree->root);

    while(stack_size(stack) > 0){
        current = stack_pop(stack);
        list_append(list, current->data);

        if(current->right != NULL){
            stack_push(stack, current->right);
        }
        
        if(current->left != NULL){
            stack_push(stack, current->left);
        }
    }

    stack_destroy(stack);

    return list;
}