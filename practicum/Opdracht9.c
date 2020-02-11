#include <string.h>
//Prototypes
void telKlinkers(char [], int []);
void main()
{
char str [30];
int aantKl[] = {0, 0, 0, 0, 0};
strcpy(str, "Het paard is groot");
telKlinkers(str, aantKl);
printf("a = %d, e = %d, i = %d, o = %d, u = %d\n", aantKl[0], aantKl[1],
aantKl[2], aantKl[3], aantKl[4]);
}
void telKlinkers(char s[], int a[])
{
unsigned int t=0;
for (t=0; t<strlen(s); t++){
switch (s[t]){
case 'a' : a[0]++; break;
case 'e' : a[1]++; break;
case 'i' : a[2]++; break;
case 'o' : a[3]++; break;
case 'u' : a[4]++; break;
}
}
}
