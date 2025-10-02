#include "main.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


static volatile bool running = true;


// MAIN START #################################################################################

int main(){
    while(running){
        clearConsole();

        printf("Hi user! This program will print all symbols from 32 to 255 (ASCII codes)...\n"
            "But at first enter sth for me <3\n\n");

        char input_string[MAX_STRING_LENGTH] = "";
        
        printf("Enter up to %d symbols: ", MAX_STRING_LENGTH - 2);
        fgets(input_string, MAX_STRING_LENGTH, stdin);

        int len = strlen(input_string) - 1; // dec 1 in case of reading \n

        if (len == 0){
            printf("\nYou entered empty string...\n");
            running = userExitProccess();
            continue;
        }

        if (input_string[len] != STRING_END_CHARACTER){
            printf("\nYou entered too many symbols...\n");
            clearInputBuffer();
            running = userExitProccess();
            continue;
        }

        printf("\nTHE MOST INTERESTED PART..... printing symbols )))\n\n");
        for(unsigned char c = START_ASCII; c < END_ASCII; c++){
            printf("ASCII %d = %c\n", (int)c, c);
        }

        running = userExitProccess();

    };

    return 0;
}

// MAIN END ###################################################################################

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int userExitProccess(){
    printf("\nEnter 1 to restart and anything else to exit: ");
    char userChoice[MAX_RESTART_STRING_LENGTH] = "";

    if (fgets(userChoice, sizeof(userChoice), stdin) == NULL) {
        return EXIT; // EOF or error
    }

    if (strchr(userChoice, STRING_END_CHARACTER) == NULL){
        clearInputBuffer();
        return EXIT;
    }

    // check for empty input
    if (userChoice[0] == '\0'){
        return EXIT;
    }

    if (strcmp(userChoice, "1\n") != 0) {
        return EXIT;
    }
   
    return RESTART;
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}