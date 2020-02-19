#include <stdio.h>
// Om dit programma goed te laten compileren: set de preprocessor definitie
// _CRT_SECURE_NO_WARNINGS via de Debug properties
void main(void)
    {
        char c = 'a';
        int getal = 3;
        char regel[5];
        // Toestand 1
        printf("Geef een getal: ");
        scanf("%i", &getal);
        printf("Address van het getal: %p\n", &getal);
        fflush(stdin);
        // Toestand 2
        printf("Geef een karakter: ");
        scanf(" %c", &c);
        printf("Address van het karakter: %p\n", &c);
        fflush(stdin);
        // Toestand 3
        printf("Geef nogmaals een karakter: ");
        scanf(" %c", &regel[2]);
        printf("Address van het 2de karakter: %p\n", &regel[2]);
        fflush(stdin);
        // Toestand 4
        printf("Geef een string: ");
        //fgets(regel, sizeof(regel), stdin);
        //fflush(stdin);
        scanf("%s", regel);
        printf("Address van het regel: %p\n", &regel);
        fflush(stdin);
        // Toestand 5
        printf("getal = %i\n", getal);
        printf("c = %c\n", c);
        printf("regel = %s\n", regel);
        // Toestand 6
        getchar();
    }
