#include "Node.h"
#include <stdio.h>

#ifndef _LIST_H_
#define _LIST_H_

struct list_t
{
    struct node_t* root_object;
    int count;
} list_t;
typedef struct list_t List;

typedef void(*LIST_ENUM_FUNC)(void* data);

List* list_t_create()
{
    List* list = (List*)malloc(sizeof(List));
    list->root_object = NULL;
    list->count = 0;
}

void list_push(List* list, void* data)
{
    Node* obj = list->root_object;
    Node* new_node = node_t_create(data);
    if (obj == NULL)
    {
        list->root_object = new_node;
        list->count++;
        return;
    }
    else
    {
        while (obj != NULL)
        {
            if (obj->next != NULL)
                obj = obj->next;
            else
                break;
        }

        obj->next = new_node;
        new_node->prev = obj;
    }
    list->count++;
}

void list_remove(List* list, void* where_data)
{
    Node* node = list->root_object;
    while (node != NULL)
    {
        if (node->ptr_data == where_data)
        {
            Node* prev = node->prev;
            Node* next = node->next;

            if (next != NULL)
                next->prev = prev;

            if (prev != NULL)
                prev->next = next;

            if (prev == NULL)
            {
                list->root_object = next;
            }

            list->count--;
            node_t_free(node);
        }

        node = node->next;
    }
}

size_t list_count(List* list)
{
    return list->count;
}

int list_exists(List* list, void* data)
{
    Node* node = list->root_object;
    int count = 0;
    while (node != NULL)
    {
        if (node->ptr_data == data)
        {
            count++;
        }

        node = node->next;   
    }
}

void list_t_free(List* list)
{
    Node* node = list->root_object;
    while (node != NULL)
    {
        Node* next = node->next;
        node_t_free(node);
        node = next;
        list->count--;
    }
    free(list);
}

void* list_by_index(List* list, int index)
{
    int current_index = 0;
    Node* node = list->root_object;
    while (node != NULL)
    {
        if (current_index == index)
            return node->ptr_data;
        else
        {
            node = node->next;
            current_index++;
        }
    }
    return NULL;
}

List* list_deep_copy(List* list, size_t data_size)
{
    List* new_list = list_t_create();
    Node* node = list->root_object;
    while(node != NULL)
    {
        void* data = (void*)(node->ptr_data);
        void* data_copy = (void*)malloc(data_size);
        memcpy(data_copy, data, data_size);
        list_push(new_list, data_copy);
        node = node->next;
    }
    return new_list;
}

void list_iterate(List* list, LIST_ENUM_FUNC print_function)
{
    for (size_t i = 0; i < list->count; i++)
    {
        (*print_function)(list_by_index(list, i));
    }
}

#endif