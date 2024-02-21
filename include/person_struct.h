#ifndef PERSON_STRUCT_H_INCLUDED
#define PERSON_STRUCT_H_INCLUDED

#define MAX_LENGTH 255
#define BD_PHONE_NUM_LENGTH 11

struct Person
{
    char gender;
    char phone[BD_PHONE_NUM_LENGTH];
    char name[MAX_LENGTH];
    char city[MAX_LENGTH];
    char password[MAX_LENGTH];
    char confirm_password[MAX_LENGTH];
};

// function declaration related to the struct
void initialize_struct(struct Person *p);

#endif // PERSON_STRUCT_H_INCLUDED
