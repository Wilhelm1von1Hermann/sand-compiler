#include<stdio.h>
#include<parser.h>

int buildCommand(char* argument[], int argc) {
    File sortedFileArray[MAX];

    printf("Compiling... \n");

    if (argc != 3) {
        printf("Todo: automatic compiling like 'cargo build' \n");
        return 0;
    }

    if (isFile(argument[2])) {
        File file;
        file = openFile(argument[2]);

        char *contents = readFileStruct(file);
        printf("\n%s\n", contents);
        return 0;
    } else {
        File fileArray[MAX];
        if (readDirectory(argument[2], fileArray) == 0) {
            sortFileArray(sortedFileArray, fileArray);
        } else {
            return 0;
        }
    }

    return 0;
}

const char helpString[] = "Help: \n build *filename* to compile specific .sd file \n";
int helpCommand(char* argument[], int argc) {
    printf("%s", helpString);
    return 0;
}

const char globalLangVersion[] = "0.1.0";
int infoCommand(char* argument[], int argc) {
    printf("%s\nSand Compiler %s", helpString, globalLangVersion);
    return 0;
}

void notFoundCommand() {
    printf("Command not found. \n");
}