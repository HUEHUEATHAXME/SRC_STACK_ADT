#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAXNUM_STACK_ITEMS   16

struct stack_t
{
    int size;
    int maxitems;
    int numitems;
    void **items;
};

stack_t *stack_create(int size)
{
    stack_t *s;

    s = calloc(1, sizeof(stack_t));
    if (s == NULL)
        goto error;
    s->size = size;
    s->items = malloc(sizeof(void*)*MAXNUM_STACK_ITEMS);
    if (s->items == NULL)
        goto error;
    s->numitems = 0;
    s->maxitems = MAXNUM_STACK_ITEMS;

    return s;
 error:
    if (s != NULL)
        free(s);
    return NULL;
}


void stack_destroy(stack_t *s)
{
    free(s->items);
    free(s);
}


int stack_push(stack_t *s, void *i)
{
    void *newitems;

    // Max capacity reached?
    if (s->numitems >= s->size)
        goto error;

    // Resisze if needed
    if (s->numitems >= s->maxitems) {
        newitems = realloc(s->items, sizeof(void*)*(s->maxitems*2));
        if (newitems == NULL)
            goto error;
        s->maxitems *= 2;
        s->items = newitems;
    }
    // Push
    s->items[s->numitems] = i;
    s->numitems++;
    return 0;
error:
    return -1;
}

int stack_pop(void **item, stack_t *s)
{
    // Empty?
    if (s->numitems == 0)
        goto error;
    // Pop
    s->numitems--;
    *item =  s->items[s->numitems];
    return 0;
error:
    return -1;
}
