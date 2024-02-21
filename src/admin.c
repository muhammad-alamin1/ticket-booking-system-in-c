#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/authentication_screen.h"

#define ADMIN_NAME "muhammad"
#define ADMIN_PASSWORD "123"

// all function
void admin_login(void);
void admin_dashboard(void);

// admin login
void admin_login(void)
{
    system("cls");
    system("title Administrator Login");

    char input_name[30];
    char input_password[20];

    printf("Enter Administrator name: ");
    scanf(" %[^\n]", input_name);

    // check admin domain name is valid
    if(strcmp(ADMIN_NAME, input_name) == 0)
    {
        printf("Enter Administrator Password: ");
        scanf(" %[^\n]", input_password);

        // check admin password is valid
        if(strcmp(ADMIN_PASSWORD, input_password) == 0)
        {
            printf("\n-------------------------------------------------------------- \n");
            printf("   >>> Administrator Login Successfully. WELCOME %s <<< \n", ADMIN_NAME);
            printf("-------------------------------------------------------------- \n");

            Sleep(3000);

            // admin dashboard
            admin_dashboard();
        }
        else
        {
            fprintf(stderr, "\nError! Administrator Password is INVALID.!\n\n");
            system("pause");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "\nError! Administrator name is INVALID.!\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
}

// dashboard
void admin_dashboard(void)
{
    unsigned int choice;

    system("cls");
    system("title Admin Dashboard");

    printf("\n\t\t\t\t------------------------------------- \n");
    printf("\t%s\t\t\t   >>> ADMIN DASHBOARD <<< \n", ADMIN_NAME);
    printf("\t\t\t\t------------------------------------- \n\n");

    printf("[1] View Registration User Data.\n");
    printf("[2] Ticket Sell .\n");
    printf("[3] Ticket Available .\n");
    printf("[4] Exit.\n");
    printf("----------------------------------- \n\n");

    printf("Enter Your Choice & Hit enter. ");
    scanf("%u", &choice);

    switch(choice)
    {
        case 1:
            // admin_login();
            break;
        case 2:
            //
            break;
        case 3:
            //
            break;
        case 4:
            exit_screen();
            break;
        default:
            printf("\n\n--------------------------------------- \n");
            fprintf(stderr, "ERROR: Invalid input please try again.  \n");
            printf("--------------------------------------- \n\n");

            system("pause");
            system("cls");
    }
}
