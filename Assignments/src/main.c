#include "list.h"
#include "Iterator.h"
#include <string.h>

#define MAX_NAME 64

struct person_t
{
    char name[MAX_NAME];
    int date_of_birth;
} person_t;
typedef struct person_t Person;

void person_t_print(Person* data)
{
    printf("ptr: %p | Name: %s | DOB: %d | DS: %d\n", data, data->name, data->date_of_birth, sizeof(data));
}

int main()
{
    List* list = list_t_create();
    for (size_t i = 0; i < 5; i++)
    {
        Person* p = (Person*)malloc(sizeof(Person));
        char* name = "Stijn Jajajaja";
        strcpy(p->name, name);
        p->date_of_birth = 19981010;
        list_push(list, p);
    }

    Iterator* iter = iterator_t_create(list);

    for (
        Person* data = iterator_current(iter); 
        !iterator_out_of_bounds(iter); 
        iterator_next(iter)
    )
    {
        person_t_print(data);
    }    
    
    return 0;
}