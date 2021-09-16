#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    int minSum = 9999, startIndex = 0, endIndex = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = i; j < n; j++)
        {
            temp = temp + arr[j];
            if (temp < minSum)
            {
                minSum = temp;
                startIndex = i;
                endIndex = j;
            }
        }
    }

    printf("%d\n", minSum);
    printf("[%d : %d]\n", startIndex, endIndex);

    return 0;
}
