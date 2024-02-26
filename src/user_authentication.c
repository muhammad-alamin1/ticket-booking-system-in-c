#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/person_struct.h"

#define SECRET_KEY 0xFACADBF
#define MAX_LENGTH 255

void user_sign_up(void)
{
    system("cls");
    system("title User Sign Up");

    printf("\n\t\t\t\t-------------------------- \n");
    printf("\t\t\t\t   >>> USER SIGN UP <<< \n");
    printf("\t\t\t\t-------------------------- \n\n");

    // initialize struct
    struct Person p;
    FILE *fp;
    // char data_base_name[51]; // = "./data/database.txt";
    char file_folder[MAX_LENGTH] = "./data/";
    char file_formate[10] = ".txt";

    printf("Enter Your Name (Space Not Allow.! Only Small letter & number combine.!) : ");
    scanf(" %[^\n]", p.name);

    // create database name
    strcat(file_folder, p.name);
    strcat(file_folder, file_formate);

     // file open
    fp = fopen(file_folder, "ab+");
    if(fp == NULL)
    {
        fprintf(stderr, "Error! File Opening Failed.!");
        exit(EXIT_FAILURE);
    }

    printf("Enter Your Phone Number: (Only BD Phone number valid.!)(+88): ");
    scanf(" %[^\n]", p.phone);

    printf("Enter Gender: ");
    scanf(" %[^\n]", p.gender);

    printf("Enter City: ");
    scanf(" %[^\n]", p.city);

    printf("Enter Your Password. ");
    scanf(" %[^\n]", p.password);

    printf("Enter Confirm Password. ");
    scanf(" %[^\n]", p.confirm_password);

    // check password & confirm password is matched
    if(strcmp(p.password, p.confirm_password) != 0)
    {
        printf("\nPassword Doesn't Match.! Try Again.! (MAX TWO TIMES).!");

        // second time check pass is valid
        is_pass_and_confirm_pass_is_valid(&p.password, &p.confirm_password);
    }

    // write data to file
    int result = fprintf(fp, "%s %s %s %s %s %s\n", p.name, p.phone, p.gender, p.city, p.password, p.confirm_password);
    if(result >= 0)
    {
        Sleep(1000);
        printf("\n------------------------------------- \n");
        printf("   >>> Data Write Successfully.! <<< \n");
        printf("------------------------------------- \n");
    }
    else
    {
        fprintf(stderr, "Your Data is wrong. Data doesn't Save to file.!");
        exit(EXIT_FAILURE);
    }

    // close file
    fclose(fp);
}

// user login
void user_sign_in(void)
{
    system("cls");
    system("title User Sign In");

    struct Person p;
    unsigned int counter = 1;
    // char data_file[] = "./data/database.txt";
    char file_folder[MAX_LENGTH] = "./data/";
    char file_formate[10] = ".txt";
    char usr_name[MAX_LENGTH];
    char usr_password[MAX_LENGTH];
    FILE *fp;

    printf("\t\t\t------------------------ \n");
    printf("\t\t\t   >>> User Log In <<< \n");
    printf("\t\t\t------------------------ \n\n");

    printf("Enter Your Domain: ");
    scanf(" %[^\n]", usr_name);

    // create database name
    strcat(file_folder, usr_name);
    strcat(file_folder, file_formate);

    // file open
    fp = fopen(file_folder, "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Error! User Name Invalid.!");
        exit(EXIT_FAILURE);
    }

    // read file
    while(fscanf(fp, "%s %s %s %s %s %s\n", p.name, p.phone, p.gender, p.city, p.password, p.confirm_password))
    {
        if(strcmp(usr_name, p.name) == 0)
        {
            printf("\n\t\tALERT: We found another contact with the same name.\n\t\t\tPlease review it too.\n\n");

            printf("Enter Your Password: ");
            scanf(" %[^\n]", usr_password);

            if(strcmp(usr_password, p.password) == 0)
            {
                system("cls");

                printf("\t\t\t-------------------------- \n");
                printf("\t\t\t   >>> WELCOME %s <<< \n", p.name);
                printf("\t\t\t-------------------------- \n\n");

                printf("\t\t|===================================================================================| \n");
                printf("\t\t|ID| \tName\t\t| Phone Number\t | Gender| City Name\t\t| Password  | \n");
                printf("\t\t|===================================================================================| \n");
                printf("\t\t| %u| %s \t\t| %s    | %s  | %s \t\t| %s\t|\n", counter, p.name, p.phone, p.gender, p.city, p.password);

                break;
            }
            else
            {
                // when password is invalid
                fprintf(stderr, "\nError.! Password is Invalid.!");
                Sleep(1000);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // when user name is invalid
            fprintf(stderr, "\nError! User Name is INVALID.!\n\n");
            Sleep(1000);
            exit(EXIT_FAILURE);
        }
    }

    // file close
    fclose(fp);
}
