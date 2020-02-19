#include <stdio.h>
#include <string.h>
 typedef struct
{
    char naam[30];
    int leeftijd;
}vriend;


//prototypes
void vulVrienden(vriend *, int *);
void vulVriendenAanMet1Vriend(vriend *, int *);
void drukAlleVriendenAf(vriend *, int);

void main(void)
{
    vriend vrienden[100];
    int aantalVrienden = 0;
    vulVrienden(&vrienden, &aantalVrienden);
    vulVriendenAanMet1Vriend(&vrienden, &aantalVrienden);
    drukAlleVriendenAf(&vrienden, aantalVrienden);
    getchar();
}
/*
Vult het "vrienden"-array met minimaal 2 vrienden (meer mag)
- De vrienden staan "hard coded" in de code.
- Het aantal vrienden dat zit moet meegegeven worden als
 invoer- en uitvoerparameter
*/
void vulVrienden(vriend *v, int *n)
{
    strcpy(v[0].naam, "Levi");
    v[0].leeftijd = 21;
    (*n)++;
    strcpy(v[1].naam, "Stijn");
    v[1].leeftijd = 21;
    (*n)++;
    strcpy(v[2].naam, "ARNO");
    v[2].leeftijd = 18;
    (*n)++;
    strcpy(v[3].naam, "Frans");
    v[3].leeftijd = 18;
    (*n)++;
}
/*
Vult het "vrienden"-array aan met 1 extra vriend.
- Invoer komt van de commandoregel.
- Het aantal vrienden dat al in het array zit moet meegegeven worden
 als invoer- en uitvoerparameter
- Gebruik voor het inlezen van de naam de functie gets.
- Gebruik voor het inlezen van de leeftijd de functie scanf.
*/
void vulVriendenAanMet1Vriend(vriend *vp, int *n)
{
    vriend v;
    strcpy(v.naam, "Gerrit-Jan");
    v.leeftijd = 30;
    printf("Naam:");
    gets(vp[*n].naam);
    fflush(stdin);
    printf("Leeftijd:");
    scanf("%d", &vp[*n].leeftijd);
    fflush(stdin);
    (*n)++;
    fflush(stdin);
}
/*
Drukt alle vrienden af in vorm:
<naam>, <leeftijd>
telkens op een nieuwe regel.
*/
void drukAlleVriendenAf(vriend *vr, int n)
{
    int counter =0;
    printf("Vrienden administratie\n");
    printf("=======================\n");

    for(counter = 0; counter < n; counter++){
    printf("%d %s (%d) \n", counter + 1, vr[counter].naam, vr[counter].leeftijd);
    }
}
