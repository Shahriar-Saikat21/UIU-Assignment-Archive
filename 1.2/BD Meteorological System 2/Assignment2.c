#include <stdio.h>
#include <string.h>
#include <conio.h>

#define N 100

int arrayIndex = 0;

typedef struct City
{
    char name[20];
    int population;
    float avgTemp;
} city;

city takeCitiesInfoFromKeyboard(city a[], int size);

void displayAllCitiesInfoReverse(city a[], int size);

void searchACity(city a[], int populationForSearch, int size);

int main()
{
    char option;

    int n, populationSearch;

    city cityTempInfo[N];

    while (option != 'q')
    {
        system("cls");
        printf("\n======= BD Meteorological System =========\n\n");
        printf("Enter 'r' to store temperature of the cities\n");
        printf("Enter 's' to search a temperature\n");
        printf("Enter 't' to display all the temperatures in reverse index order\n");
        printf("Enter 'q' to quit the program\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch (option)
        {

        case 'r':
            system("cls");
            printf("\n======= BD Meteorological System =========\n\n");
            printf("\nEnter number of cities you want to store : ");
            scanf("%d", &n);

            takeCitiesInfoFromKeyboard(cityTempInfo, n);
            printf("\nPress any key to continue.......");
            getch();
            break;

        case 's':
            system("cls");
            printf("\n======= BD Meteorological System =========\n\n");
            if (arrayIndex == 0)
            {
                printf("\nNo information is found.\nPlease populate your temperature information first.\n");
            }
            else
            {
                printf("\nEnter city population for search : ");
                scanf("%d", &populationSearch);
                searchACity(cityTempInfo, populationSearch, arrayIndex);
            }
            printf("\nPress any key to continue.......");
            getch();
            break;

        case 't':
            system("cls");
            printf("\n======= BD Meteorological System =========\n\n");
            if (arrayIndex == 0)
            {
                printf("\nNo information is found.\nPlease populate your temperature information first.\n");
            }
            else
            {
                displayAllCitiesInfoReverse(cityTempInfo, arrayIndex);
            }
            printf("\nPress any key to continue.......");
            getch();
            break;

        case 'q':
            break;

        default:
            printf("\nInvalid Input\n");
            printf("\nPress any key to continue.......");
            getch();
        }
    }
    return 0;
}

city takeCitiesInfoFromKeyboard(city a[], int size)
{
    if (arrayIndex == 0)
    {
        for (int i = 0; i < size; i++)
        {
            printf("\nEnter City %d Name: ", i + 1);
            getchar();
            scanf("%[^\n]s", a[i].name);
            printf("Enter City %d Population: ", i + 1);
            scanf("%d", &a[i].population);
            printf("Enter City %d Temperature: ", i + 1);
            scanf("%f", &a[i].avgTemp);
        }
        arrayIndex += size;
    }
    else
    {
        int cityCount = 1;
        for (int i = arrayIndex; i < arrayIndex + size; i++)
        {
            printf("\nEnter City %d Name: ", cityCount);
            getchar();
            scanf("%[^\n]s", a[i].name);
            printf("Enter City %d Population: ", cityCount);
            scanf("%d", &a[i].population);
            printf("Enter City %d Temperature: ", cityCount);
            scanf("%f", &a[i].avgTemp);
            cityCount++;
        }
        arrayIndex += size;
    }
}

void searchACity(city a[], int populationForSearch, int size)
{
    int i, flag = 0;
    for (i = 0; i < size; i++)
    {
        if (a[i].population == populationForSearch)
        {
            printf("\nCity Name : %s\nCity Population : %d\nCity Temperature : %.2f\n", a[i].name, a[i].population, a[i].avgTemp);
            flag++;
        }
    }
    if (flag == 0)
    {
        printf("\nInformation not found\n");
    }
    flag = 0;
}

void displayAllCitiesInfoReverse(city a[], int size)
{
    printf("\n%-20s %-20s %-10s\n", "City Name", "City Population", "City Temperature");
    printf("----------------------------------------------------------\n");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%-20s %-20d %-10.2f\n", a[i].name, a[i].population, a[i].avgTemp);
    }
}
