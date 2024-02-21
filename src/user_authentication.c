#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/person_struct.h"

#define SECRET_KEY 0xFACADBF

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
    char data_base_name[] = "./data/database.txt";

    // file open
    fp = fopen(data_base_name, "ab+");
    if(fp == NULL)
    {
        fprintf(stderr, "Error! File Opening Failed.!");
        exit(EXIT_FAILURE);
    }

    printf("Enter Your Name (Space Not Allow.! Only Small letter & number combine.!) : ");
    scanf(" %[^\n]", p.name);

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
