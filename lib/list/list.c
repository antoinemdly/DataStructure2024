#include "list.h"
#include <stdlib.h>

List *list_create(){
    List *list = malloc(sizeof(List));
    list->first = NULL;
    return list;
}

int list_size(List *list){
    int n = 0;
    if (list->first == NULL){
        return n;
    }
    else{
        ListNode *tmp = list->first;
        while(tmp != NULL){
            n++;
            tmp = tmp->next;
        }

        return n;
    }
}

void *list_get(List *list, int index){
    if(index > list_size(list) - 1 || index < 0){
        return NULL;
    }

    ListNode *tmp = list->first;
    for (int i = 0; i < index; i++){
        tmp = tmp->next;
    }

    return tmp->data;
}

int list_contains(List *list, void *data){
    ListNode *tmp = list->first;
    while(tmp != NULL){
        if(tmp->data == data){
            return 1;
        }
        tmp = tmp->next;
    }
    
    return 0;
}

void list_append(List *list, void *data){
    ListNode *node = malloc(sizeof(ListNode));
    node->next = NULL;
    node->data = data;

    ListNode *lastNode = list->first;
    if(lastNode != NULL) {
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = node;
    } else {
        list->first = node;
    }
}

void list_insert(List *list, int index, void *data){
    if(index > list_size(list) - 1 || index < 0){
        return;
    }

    ListNode *prevNode = NULL;
    ListNode *targetNode = list->first;
    for (int i = 0; i < index; i++){
        prevNode = targetNode;
        targetNode = targetNode->next;
    }

    ListNode *node = malloc(sizeof(ListNode));
    node->data = data;
    node->next = targetNode;

    if(prevNode == NULL) {
        list->first = node;
    } else {
        prevNode->next = node;
    }
}

int list_indexOf(List *list, void *data){
    ListNode *tmp = list->first;
    int n = 0;

    while(tmp != NULL){
        if(tmp->data == data){
            return n;
        }
        tmp = tmp->next;
        n++;
    }
    
    return -1;
}

void list_delete(List *list, int index){
    if(index > list_size(list) - 1 || index < 0){
        return;
    }

    ListNode *prevNode = NULL;
    ListNode *targetNode = list->first;

    for (int i = 0; i < index; i++){
        prevNode = targetNode;
        targetNode = targetNode->next;
    }

    ListNode *nextNode = targetNode->next;

    if(prevNode == NULL) {
        list->first = nextNode;
    } else {
        prevNode->next = nextNode;
    }

    free(targetNode);
}

void list_destroy(List *list){
    ListNode *current = list->first;
    ListNode *next;

    while(current != NULL){
        next = current->next;

        free(current);

        current = next;
    }

    free(list);
}