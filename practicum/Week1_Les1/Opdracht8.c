#include <stdio.h>
void klinker_KUT(char inp[], int* a, int* e, int* i, int* o, int* u){
    for (int j = 0; inp[j] != '\0'; j++)
    {
        if (inp[j] == 'a'){
            (*a)++;
        } else if (inp[j] == 'e')
        {
            (*e)++;
        } else if (inp[j] == 'i')
        {
            (*i)++;
        } else if (inp[j] == 'o')
        {
            (*o)++;
        } else if (inp[j] == 'u')
        {
            (*u)++;
        }
    }
    
}
int main()
{
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
klinker_KUT("Stijn zag mijn porno", &a,&e,&i,&o,&u);
    printf("uitvoer is a = %d, e = %d, i = %d, o = %d, u = %d ", a,e,i,o,u);
    return 0;
}
