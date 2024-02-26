#include <stdio.h>
#include <stdlib.h>
#include "../include/authentication_screen.h"
#include "../include/admin.h"
#include "../include/user_authentication.h"

// all function
void main_authentication_screen(void);
void registration_screen(void);
void exit_screen(void);

void main_authentication_screen(void)
{
    system("title Ticket Booking Authentication");

    printf("\n\t\t\t\t------------------------------------- \n");
    printf("\t\t\t\t   >>> TICKET BOOKING SYSTEM <<< \n");
    printf("\t\t\t\t------------------------------------- \n");

    system("pause");
    system("cls");

    registration_screen();
}

// Registration screen
void registration_screen(void)
{
    unsigned int choice;

    printf("\n----------------------------------- \n");
    printf("   >>> Login into system as <<< \n");
    printf("----------------------------------- \n");

    printf("[1] Administrator Login.\n");
    printf("[2] User Login.\n");
    printf("[3] User Sign Up.\n");
    printf("[4] Exit.\n");
    printf("----------------------------------- \n\n");

    printf("Enter Your Choice & Hit enter. ");
    scanf("%u", &choice);

    switch(choice)
    {
        case 1:
            admin_login();
            break;
        case 2:
            user_sign_in();
            break;
        case 3:
            user_sign_up();
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

// exit page
void exit_screen(void)
{
    system("cls");

    printf("\t\t\t\t------------------------------------------ \n");
    printf("\t\t\t\t\t\t>>> Thank You. <<<\n");
    printf("\t\t\t\t------------------------------------------ \n\n");

    Sleep(1000);
    exit(EXIT_FAILURE);
}
