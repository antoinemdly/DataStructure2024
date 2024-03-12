#include "stack.h"
#include <stdlib.h>

Stack *stack_create(){
    Stack *stack = malloc(sizeof(Stack));

    stack->first = NULL;
    return stack;
}

int stack_size(Stack *stack){

    int n = 0;
    if (stack->first == NULL){
        return n;
    }
    else{
        StackNode *tmp = stack->first;
        while(tmp != NULL){
            n++;
            tmp = tmp->next;
        }

        return n;
    }
}

void stack_push(Stack *stack, void *data){

    StackNode *node = malloc(sizeof(StackNode));
    node->data = data;

    if (stack->first == NULL){
        stack->first = node;
    }
    else{
        StackNode *tmp = stack->first;

        stack->first = node;
        node->next = tmp;
    }
}

void *stack_pop(Stack *stack){
    if (stack->first == NULL){
        return NULL;
    }
    else{
        StackNode *tmp = stack->first;
        stack->first = stack->first->next;
        return tmp->data;
    }
}

void stack_destroy(Stack *stack){
    StackNode *current = stack->first;
    StackNode *next;

    while(current != NULL){
        next = current->next;

        free(current);

        current = next;
    }

    free(stack);
}