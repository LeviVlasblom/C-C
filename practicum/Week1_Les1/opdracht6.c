#include <stdio.h>
    //functie schrijven
int largest(int arr[], int arrSize)
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
        return max;
    }
int main()
{
    int arr[] = {10, 40, 50, 1340, 0};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("Grootste nummer uit de array is %d", largest(arr, arrSize));
    return 0;
}
