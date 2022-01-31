#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool checkPassword(char *userpass, char *encryptedPass)
{
    if(strncmp(encryptedPass, userpass, sizeof(encryptedPass)-1) == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

char *rot13(char *message)
{
    int i = 0;
    int rotKey = 13;
    while(message[i] != '\0')
    {
        if(isalpha(message[i]))
        {
            // Check for capital letters
            if(message[i] >= 'A' && message[i] <= 'Z')
            {
                if((message[i] + rotKey) <= 'Z')
                {
                    message[i] = message[i] + rotKey;
                }
                else
                {
                    message[i] = message[i] - rotKey;
                }
                // Check for lowercase letters
            } else if(message[i] >= 'a' && message[i] <= 'z')
            {
                if((message[i] + rotKey) <= 'z')
                {
                    message[i] = message[i] + rotKey;
                }
                else
                {
                    message[i] = message[i] - rotKey;
                }
            }
        }
        i++;
    }
    return message;

}
int main(void)
{
    char rottedMessage[40] = "SYNT{711389441n47p19n244p8473rr5nprss}";
    char password[17] = "CnffjbeqfNerUneq";
    char userInput[50];

    printf("Enter a password: ");

    // TODO: parse the user input.
    if(fgets(userInput, 50, stdin))
    {
        userInput[strcspn(userInput, "\n")] = 0; // removes the newline
    }

    // compare passwords
    if(checkPassword(userInput, rot13(password)))
    {
       printf("Correct! Take this: %s\n", rot13(rottedMessage));
    }
    else
    {
         printf("Incorrect password!\nExiting...\n");
     }
    return 0;
}
