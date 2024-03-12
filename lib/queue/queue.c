#include "queue.h"
#include <stdlib.h>

Queue *queue_create(){
    Queue *queue = malloc(sizeof(queue));
    queue->first = NULL;
    return queue;
}

void queue_destroy(Queue *queue){
    
    if (queue->first == NULL){
        free(queue);
    }
    else{
        QueueNode *current = queue->first;

        while(current != NULL){
            QueueNode *tmp = current->next;

            free(current);

            current = tmp;
        }

    free(queue);

    }

}

void queue_enqueue(Queue *queue, void *data){

    QueueNode *node = malloc(sizeof(QueueNode));
        node->next = NULL;
        node->data = data;

    if (queue->first == NULL){
    
        queue->first = node;

    }
    else{
        
        QueueNode *tmp = queue->first;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        tmp->next = node;

    }

}

void *queue_dequeue(Queue *queue){

    if (queue->first == NULL){
        return NULL;
    }
    else{

        QueueNode *tmp = queue->first;
        queue->first = queue->first->next; // check if next is NULL <--- might be an error here
        return tmp->data;

    }
}

int queue_size(Queue *queue){

    int n = 0;
    QueueNode *tmp = queue->first;

    while (tmp != NULL){
        n++;
        tmp = tmp->next;
    }

    return n;

}