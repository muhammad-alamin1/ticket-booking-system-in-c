#ifndef PERSON_STRUCT_H_INCLUDED
#define PERSON_STRUCT_H_INCLUDED

#define BD_PHONE_NUM_LENGTH 11
#define MAX_LENGTH 255

struct Person
{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char gender[MAX_LENGTH];
    char city[MAX_LENGTH];
    char password[MAX_LENGTH];
    char confirm_password[MAX_LENGTH];
};

#endif // PERSON_STRUCT_H_INCLUDED
