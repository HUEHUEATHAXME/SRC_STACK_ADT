#ifndef STACK_H
#define STACK_H

typedef struct stack_t stack_t;

stack_t *stack_create(int size);
void stack_destroy(stack_t *s);
int stack_push(stack_t *s, void *item);
int stack_pop(void **item, stack_t *s);

#endif  /* STACK_H */

