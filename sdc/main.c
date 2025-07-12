// main file for the Sand Compiler (sdc)

#include<stdio.h>
#include<string.h>

#include<commands.h>

// some code for handling string matching
void argumentsToCommand(char* argument[], int argc) {
    // string switch 2.0
    if (strcmp(argument[1], "build") == 0) {
        buildCommand(argument, argc);
    } else if (strcmp(argument[1], "help") == 0) {
        helpCommand(argument, argc);
    } else if (strcmp(argument[1], "info") == 0) {
        infoCommand(argument, argc);
    }
    
    // default case
    else {
        notFoundCommand();
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Sand Compiler %s \n", globalLangVersion);
        return 0;
    }

    argumentsToCommand(argv, argc);

    return 0;
}