#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED

void is_pass_and_confirm_pass_is_valid(char *pass, char *c_pass);
void change_pass(char *pass);
char* encrypt_pass(char *pass, int key);
char* decrypt_pass(char *pass, int key);

#endif // VALIDATION_H_INCLUDED
