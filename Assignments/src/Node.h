#ifndef _NODE_H_
#define _NODE_H_

#include <malloc.h>
#include <memory.h>

struct node_t
{
    void* ptr_data;
    struct node_t* prev;
    struct node_t* next;
} node_t;
typedef struct node_t Node;

Node* node_t_create(void* data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->prev = 0;
    node->next = 0;
    node->ptr_data = data;
    return node;
}

void node_t_free(Node* node)
{
    if (node != NULL)
    {
        free(node->ptr_data);
        free(node);
    }
}

#endif