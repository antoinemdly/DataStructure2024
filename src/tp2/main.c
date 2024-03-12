#include <stdio.h>

#include "../../lib/list/list.h"
#include "../../lib/queue/queue.h"
#include "../../lib/stack/stack.h"

void list_fn()
{
    List *list = list_create();

    list_append(list, (void*)1);
    list_append(list, (void*)2);
    list_append(list, (void*)3);

    
}

void queue_fn()
{
    // TODO: Implement
}

void stack_fn()
{
    // TODO: Implement
}

int main()
{
    // List
    list_fn();

    // Queue
    queue_fn();

    // Stack
    stack_fn();

    return 0;
}
