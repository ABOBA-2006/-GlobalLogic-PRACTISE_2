#pragma once

#define MAX_STRING_LENGTH 22 // 30 for string length + \n + \0
#define MAX_RESTART_STRING_LENGTH 3 // cause 1 + \n + \0
#define STRING_END_CHARACTER '\n'
#define EXIT 0
#define RESTART 1
#define START_ASCII 32
#define END_ASCII 255

void clearConsole();        // clear the console screen
int userExitProccess();     // asks user to restart the program
void clearInputBuffer();    // clear the buffer