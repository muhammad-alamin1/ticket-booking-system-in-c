#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// check password & confirm password is same
void is_pass_and_confirm_pass_is_valid(char *pass, char *c_pass)
{
    printf("\nEnter Your Password. ");
    scanf(" %[^\n]", pass);

    printf("Enter Confirm Password. ");
    scanf(" %[^\n]", c_pass);

    if(strcmp(pass, c_pass) != 0)
    {
        printf("Password Doesn't Match.!");
        exit(EXIT_FAILURE);
    }
}

// the password as '*' character
void change_pass(char *pass)
{
    char ch;
    unsigned int i;

    for(i = 0; i < strlen(pass); i++)
    {
        ch = pass[i];
        pass[i] = ch;
        ch = '*';

        printf("%c", ch);
    }
}

// pass encrypt
char* encrypt_pass(char *pass, int key)
{
    unsigned int i;
    for(i = 0; i < strlen(pass); ++i)
        pass[i] -= key;

    return pass;
}

// pass decrypt
char* decrypt_pass(char *pass, int key)
{
    unsigned int i;
    for(i = 0; i <strlen(pass); ++i)
        pass[i] += key;

    return pass;
}
