#include <stdio.h>
#include <string.h>

#define FAIL_VAL -99999
#define SUCCESS_VAL 99999
#define MAX_USER 20
#define MAX_LEN 200

char emailArr[MAX_USER][MAX_LEN];
char passArr[MAX_USER][MAX_LEN];

char nameArr[MAX_USER][MAX_LEN];
char addressArr[MAX_USER][MAX_LEN];

int user_count = 0;

int signupUser(char email[], char pass[])
{
    int i;
    int emailSize = strlen(email);
    int passSize = strlen(pass);
    int at = -1, atCount = 0, dot = -1;
    int flagUpper = 0, flagLower = 0, specialChar = 0, digit = 0;

    //user number check
    if (user_count > MAX_USER)
    {
        printf("\nSorry !! No Space for New User\n");
        return FAIL_VAL;
    }
    else
    {
        // Duplication email check
        for (i = 0; i < user_count; i++)
        {
            if (strcmp(emailArr[i], email) == 0)
            {
                printf("\nThis mail has been used already\n");
                return FAIL_VAL;
            }
        }
        // email address validation check
        if (email[0] >= 'a' && email[0] <= 'z' || email[0] >= 'A' && email[0] <= 'Z')
        {
            for (i = 0; i < emailSize; i++)
            {
                if (email[i] == '@')
                {
                    at = i;
                    atCount++;
                }
                else if (email[i] == '.')
                {
                    dot = i;
                }
            }
            if (email[emailSize - 1] == '.')
            {
                // check mail address finish with dot
                printf("\nMail ID can not be finished with (.), Invalid ID\n");
                return FAIL_VAL;
            }
            else if (atCount > 1)
            {
                // check mail address contain more than one @
                printf("\nMail ID has more than one (@), Invalid ID\n");
                return FAIL_VAL;
            }
            else if (at > dot)
            {
                // check mail address position of @ and dot
                printf("\nInvalid Mail ID Format\n");
                return FAIL_VAL;
            }
        }
        else
        {
            printf("\nMail ID does not start with letter, Invalid Mail ID\n");
            return FAIL_VAL;
        }
    }
    // Password validation check
    for (i = 0; i < passSize; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            // check password contain at least one lower case
            flagLower++;
        }
        else if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            // check password contain at least one Upper case
            flagUpper++;
        }
        else if (pass[i] == '$' || pass[i] == '*' || pass[i] == '#' || pass[i] == '@')
        {
            // check password contain at least one $ or * or # or @
            specialChar++;
        }
        else
        {
            // check password contain at least one digit
            digit++;
        }
    }
    if (flagUpper < 1 || flagLower < 1 || specialChar < 1 || digit < 1 || passSize < 8)
    {
        printf("\nPassword has to contain at least one Uppercase,lowercase,digit,special character (@,#,$,*) and 8 character length\nInvalid Password Format\n");
        return FAIL_VAL;
    }
    return user_count;
}

int loginUser(char email[], char pass[])
{
    // check mail and password
    int i;
    for (i = 0; i < user_count; i++)
    {
        if (strcmp(emailArr[i], email) == 0 && strcmp(passArr[i], pass) == 0)
        {
            return i;
        }
    }
    return FAIL_VAL;
}

int buildUserProfile(char email[], char firstName[], char lastName[], char address[])
{
    int i;
    for (i = 0; i < user_count; i++)
    {
        // mail check
        if (strcmp(emailArr[i], email) == 0)
        {
            char fullName[MAX_LEN];
            // full name buildup with space
            strcpy(fullName, strcat(strcat(firstName, " "), lastName));
            // store name and address at proper index and array
            strcpy(nameArr[i], fullName);
            strcpy(addressArr[i], address);
            return SUCCESS_VAL;
        }
    }
    return FAIL_VAL;
}

void searchByName(char name[])
{
    int i, found = 0;
    // search name in nameArr
    for (int i = 0; i < user_count; i++)
    {
        if (strstr(strupr(nameArr[i]), strupr(name)) != NULL)
        {
            printf("\nName : %s\nEmail : %s\nAddress: %s\n", nameArr[i], emailArr[i], strupr(addressArr[i]));
            found += 1;
        }
    }
    if (found == 0)
    {
        printf("\nInformation not found\n");
    }
}

void searchByAddress(char address[])
{
    int i, found = 0;
    // search address in addressArr
    for (int i = 0; i < user_count; i++)
    {
        if (strstr(strupr(addressArr[i]), strupr(address)) != NULL)
        {
            printf("\nName : %s\nEmail : %s\nAddress: %s\n", strupr(nameArr[i]), emailArr[i], addressArr[i]);
            found += 1;
        }
    }
    if (found == 0)
    {
        printf("\nInformation not found\n");
    }
}

int main()
{
    while (1)
    {
        printf("\n*******************************************************************\n");
        printf("1. signup User. 2. login User. 3. build User Profile. 4.Search By Name. 5. Search By Address. 6.exit \n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {

            char mail[MAX_LEN], pass[MAX_LEN];
            printf("give User Email : ");
            scanf("\n%[^\n]s", mail);
            printf("give User Password : ");
            scanf("\n%[^\n]s", pass);

            int result = signupUser(mail, pass);

            if (result >= 0)
            {
                strcpy(emailArr[result], mail);
                strcpy(passArr[result], pass);
                printf("\nSignup Successful\n");
                user_count++;
            }
            else
            {
                printf("\nSignup Unsuccessful\n");
            }
        }

        if (choice == 2)
        {

            char mail[MAX_LEN], pass[MAX_LEN];
            printf("give User Email : ");
            scanf("\n%[^\n]s", mail);

            printf("give User Password : ");
            scanf("\n%[^\n]s", pass);

            int result = loginUser(mail, pass);

            if (result >= 0)
            {
                printf("\nLogin Successful\n");
            }
            else
            {
                printf("\nEmail or Password does not match\nLogin Unsuccessful\n");
            }
        }

        if (choice == 3)
        {

            char mail[MAX_LEN], fname[MAX_LEN], lname[MAX_LEN], address[MAX_LEN];
            printf("give User Email : ");
            scanf("\n%[^\n]s", mail);
            printf("%s\n", mail);
            printf("give First Name : ");
            scanf("\n%[^\n]s", fname);
            printf("%s\n", fname);
            printf("give Last Name : ");
            scanf("\n%[^\n]s", lname);
            printf("%s\n", lname);
            printf("give Address : ");
            scanf("\n%[^\n]s", address);
            printf("%s\n", address);

            int result = buildUserProfile(mail, fname, lname, address);

            if (result >= 0)
            {
                printf("\nProfile has been built successfully\n");
            }
            else
            {
                printf("\nThis mail is not been signup yet, Profile build unsuccessful\n");
            }
        }

        if (choice == 4)
        {

            char name[MAX_LEN];
            printf("give User Name : ");
            scanf("\n%[^\n]s", name);

            searchByName(name);
        }

        if (choice == 5)
        {

            char address[MAX_LEN];
            printf("give User Address : ");
            scanf("\n%[^\n]s", address);

            searchByAddress(address);
        }
        if (choice == 6)
        {
            break;
        }
    }

    return 0;
}
