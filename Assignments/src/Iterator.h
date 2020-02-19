#ifndef _ITERATOR_H
#define _ITERATOR_H

#include "list.h"

typedef struct
{
    struct list_t* list_object;
    int current_index;
} iterator_t, Iterator;

Iterator* iterator_t_create(List* list)
{
    Iterator* iter = (Iterator*)malloc(sizeof(Iterator));
    iter->current_index = 0;
    iter->list_object = list;
    return iter;
}

void iterator_t_free(Iterator* iterator)
{
    if (iterator != NULL)
    {
        iterator->current_index = NULL;
        iterator->list_object = NULL;
        free(iterator);
    }
}

int iterator_end_reached(Iterator* iterator)
{
    return (iterator->current_index == iterator->list_object->count - 1);
}

int iterator_out_of_bounds(Iterator* iterator)
{
    return iterator->current_index == iterator->list_object->count;
}

void iterator_step(Iterator* iterator, int step)
{
    iterator->current_index += step;
}

void* iterator_current(Iterator* iterator)
{
    return iterator_out_of_bounds(iterator) ? NULL : list_by_index(iterator->list_object, iterator->current_index);
}

void* iterator_next(Iterator* iterator)
{
    iterator_step(iterator, 1);
    return iterator_current(iterator);
}

void* iterator_prev(Iterator* iterator)
{
    iterator_step(iterator, -1);
    return iterator_current(iterator);
}

#endif