#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/authentication_screen.h"
#include "../include/user_authentication.h"
#include "../include/person_struct.h"

#define MAX_LENGTH 255

void user_dashboard(void)
{
    unsigned int choice;

    // get current time
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);

    // Determine AM or PM
    const char *am_pm = (local_time->tm_hour < 12) ? "AM" : "PM";

    printf("\n\n\t\t\t--------------------------- \n");
    printf("\t\t\t   >>> USER DASHBOARD <<< \n");
    printf("\t\t\t--------------------------- \n\n");

    printf("\t\t\t\t\t\t\t\t\t Time: %02d:%02d:%02d %s\n", (local_time->tm_hour % 12 == 0) ? 12 : local_time->tm_hour % 12, local_time->tm_min, local_time->tm_sec, am_pm);

    printf("----------------------------------- \n");
    printf("[1] Buy Ticket.\n");
    printf("[2] See Booking Ticket.\n");
    printf("[3] Sitting.\n");
    printf("[4] Exit.\n");
    printf("----------------------------------- \n\n");

    printf("Enter Your Choice & Hit enter. ");
    scanf("%u", &choice);

    switch(choice)
    {
        case 1:
            buy_ticket();
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

            exit(0);
    }
}

// buy ticket
void buy_ticket()
{
    system("cls");

    unsigned int choice;

    printf("\n\n\t\t\t--------------------------------- \n");
    printf("\t\t\t   >>> ENJOY YOUR TRAVELING <<< \n");
    printf("\t\t\t--------------------------------- \n\n");

    printf("----------------------------------- \n");
    printf("[1] Dhaka to Chittagong. [600 bucks] \n");
    printf("[2] Barishal to Chittagong. [900 bucks] \n");
    printf("[3] Barishal to Dhaka. [550 bucks]\n");
    printf("[4] Chittagong to Dhaka. [600 bucks] \n");
    printf("[5] Chittagong to Rajshahi. [700 bucks]\n");
    printf("[6] Back To Dashboard.\n");
    printf("[7] Exit.\n");
    printf("----------------------------------- \n\n");

    printf("Enter Your Choice & Hit enter. ");
    scanf("%u", &choice);

    switch(choice)
    {
        case 1:
            save_ticket_data(600);
            break;
        case 2:
            //
            break;
        case 3:
            //
            break;
        case 4:
            //
            break;
        case 5:
            //
            break;
        case 6:
            system("cls");
            user_dashboard();
            break;
        case 7:
            exit_screen();
            break;
        default:
            printf("\n\n--------------------------------------- \n");
            fprintf(stderr, "ERROR: Invalid input please try again.  \n");
            printf("--------------------------------------- \n\n");

    }
}

void save_ticket_data(int a)
{
    struct Person p;
    FILE *fp, *ft;
    unsigned int qty, total_amount;
    char file_folder[MAX_LENGTH] = "./data/";
    char file_folder1[MAX_LENGTH] = "./data/";
    char file_formate[10] = ".txt";
    char buy_ticket_file_format[20] = "/ticket.txt";
    char file_formate1[10] = ".txt";
    char usr_name[MAX_LENGTH];
    char travel_name[MAX_LENGTH];

    printf("Enter Your domain: ");
    scanf(" %[^\n]", usr_name);

    strcat(file_folder, usr_name);
    strcat(file_folder, file_formate);

    // file open
    fp = fopen(file_folder, "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Error! User Name Invalid.!\n");
        exit(EXIT_FAILURE);
    }

    int item_read = fscanf(fp, "%s \n", p.name);
    if(item_read >= 1)
    {
        if(strcmp(usr_name, p.name) == 0)
        {
            fclose(fp);

            printf("Enter Ticket Qty: (Only Allow Unsigned int number) ");
            scanf("%u", &qty);

            printf("Enter Travel Name: (Like Dhaka TO Chittagong) ");
            scanf(" %[^\n]", travel_name);

            strcat(file_folder1, p.name);
            strcat(file_folder1, buy_ticket_file_format);
            strcat(file_folder1, file_formate1);

            // buy ticket file open
            ft = fopen(file_folder, "ab+");
            if(ft == NULL)
            {
                fprintf(stderr, "Error! FILE Opening Failed.!\n");
                exit(EXIT_FAILURE);
            }

            // total fee
            total_amount = (int) a * qty;

            int res = fprintf(ft, "\n\n%s %s %u %u\n", p.name, travel_name, qty, total_amount);
            if(res >= 0)
            {
                Sleep(1000);
                printf("\n------------------------------------------------- \n");
                printf("   >>> Ticket Buy Successfully.! Happy Traveling. <<< \n");
                printf("--------------------------------------------------- \n");
            }

            fclose(ft);
        }
        else
        {
            fprintf(stderr, "Error! User Name Invalid.!\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Error! User Name Invalid.!\n");
        exit(EXIT_FAILURE);
    }
}
