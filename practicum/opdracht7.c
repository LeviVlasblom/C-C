#include <stdio.h>
    //functie schrijven
void largest(int arr[], int arrSize, int* ref)
    {
    int i;
    int max = arr[0];
        for (i = 1; i < arrSize; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        (*ref) = max;
    }
int main()
{
    int ref = 0;
    int arr[5] = {10, 40, 50, 1340, 0};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    largest(arr, arrSize, &ref);
    printf("Grootste nummer uit de array is %d", ref);
    return 0;
}
