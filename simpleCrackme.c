#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* 
 
This is a simple crackme so the password is hard-coded into the program.
*/ 
bool checkPassword(char *userPass);

bool checkPassword(char *userPass)
{
    char superSecretPassword[34] = "YouWiLlN3verGue5sTh1sPassw0rd123!";

    // Compare userPass with superSecretPass and return result
    if(strncmp(superSecretPassword, userPass, sizeof(superSecretPassword)-1) == 0)
    {
        return true;
    } else 
    {
        return false;
    }
    
}

int main(void)
{   
    char userInput[50];
    printf("Enter a password: ");

     // Ask for the user input
    if(fgets(userInput, 50, stdin))
    {
        userInput[strcspn(userInput, "\n")] = 0; // removes the newline
    }

    // Compare the user input for the password
    if(checkPassword(userInput))
    {
        printf("Correct!!\nThe flag is d077f244def8a70e5ea758bd8352fcd8\n");
    } 
    else 
    {
        printf("Incorrect password!\nExiting...\n");
    }
    
    return 0;
}