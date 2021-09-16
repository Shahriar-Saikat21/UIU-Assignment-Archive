#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    int highestProfit = -99999;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int currentProfit = arr[j] - arr[i];
            if (currentProfit > highestProfit)
            {
                highestProfit = currentProfit;
            }
        }
    }

    if(highestProfit>0)
    {
        printf("Maximum Profit: %d\n", highestProfit);
    }
    else if(highestProfit == 0)
    {
        printf("No profit or loss\n");
    }
    else
    {
        printf("Loss\n");
    }



    return 0;
}
