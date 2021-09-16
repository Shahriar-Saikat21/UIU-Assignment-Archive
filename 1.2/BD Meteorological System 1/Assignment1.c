#include <stdio.h>

int main()
{
    char option;
    int i, n, search, index, flag, arraySize = 0;
    int temperature[100];

    while (option != 'q')
    {
        printf("\n======= BD Meteorological System =========\n\n");
        printf("Enter 'r' to store temperature of the cities\n");
        printf("Enter 's' to search a temperature\n");
        printf("Enter 't' to display all the temperatures in reverse index order\n");
        printf("Enter 'q' to quit the program\n\n");

        printf("Enter your choice: ");
        scanf_s(" %c", &option);

        switch (option)
        {

        case 'r':

            if (arraySize == 0)
            {
                printf("\nEnter your number of entries: ");
                scanf_s("%d", &n);

                for (i = 0; i < n; i++)
                {
                    scanf_s("%d", &temperature[i]);
                }

                arraySize = n;
            }
            else
            {
                printf("\nEnter your number of entries: ");
                scanf_s("%d", &n);

                for (i = arraySize; i < arraySize + n; i++)
                {
                    scanf_s("%d", &temperature[i]);
                }

                arraySize += n;
            }

            break;

        case 's':

            if (arraySize == 0)
            {
                printf("\nNo temperature information is found.\nPlease populate your temperature information first.\n");
            }
            else
            {
                printf("\nEnter your searching temperature: ");
                scanf_s("%d", &search);

                int searchIndex[arraySize];

                for (i = 0; i < arraySize; i++)
                {
                    if (temperature[i] == search)
                    {
                        searchIndex[i] = i;
                        flag++;
                    }
                }

                if (flag > 0)
                {
                    printf("Found at index: ");

                    for (i = 0; i < arraySize; i++)
                    {
                        if (searchIndex[i] == i)
                        {
                            printf("%d ", searchIndex[i]);
                        }
                    }

                    flag = 0;
                    printf("\n");
                }
                else
                {
                    printf("Not found\n");
                }
            }
            break;

        case 't':

            if (arraySize == 0)
            {
                printf("\nNo temperature information is found.\nPlease populate your temperature information first.\n");
            }
            else
            {
                for (i = arraySize - 1; i >= 0; i--)
                {
                    printf("%d ", temperature[i]);
                }
                printf("\n");
            }
            break;

        case 'q':

            break;

        default:
            printf("\nInvalid Input\n");
        }
    }

    return 0;
}
