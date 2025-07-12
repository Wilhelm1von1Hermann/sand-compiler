// .c file containing implementations of preprocessor, parser, lexer, file reader, etc

#include<stdio.h>
#include<string.h>
#include<dirent.h>

#include<parser.h>

// opens file in the specified directory, returning File struct
// the directory has to be something like "~/Desktop/test.sd"
File openFile(char *directory) {
    File file;
    FILE *fileptr;

    fileptr = fopen(directory, "r");
    char fileContents[MAX];
    char fileContentsLine[MAX];

    if (fileptr != NULL) {
        while (fgets(fileContentsLine, MAX, fileptr)) {
            strcat(fileContents, fileContentsLine);
        }
        fclose(fileptr);
    } else {
        printf("Sorry! couldn't read %s \n", directory);
    }

    file.contents = fileContents;
    file.directory = directory;

    return file;
}

// opens specified directory, and writes them into file array
// the directory has to be something like "~/Desktop"
int readDirectory(char *directory, File *fileArray) {
    DIR *dirPointer;
    struct dirent *dirDirent;

    dirPointer = opendir(directory);
    if (dirPointer == NULL) {
        printf("Couldn't open directory %s \n", directory);
        return 1;
    }

    int i = 0;
    while ((dirDirent = readdir(dirPointer)) != NULL) {
        File entry;

        entry.directory = strcat(directory, dirDirent->d_name);

        FILE *fileptr;
        fileptr = fopen(entry.directory, "r");
        char fileContents[MAX];

        if (fileptr != NULL) {
            while (fgets(fileContents, MAX, fileptr)) {}
            fclose(fileptr);
        } else {
            printf("Couldn't read file %s \n", entry.directory);
            return 1;
        }

        entry.contents = fileContents;

        fileArray[i] = entry;
        i++;
    }

    closedir(dirPointer);
    return 0;
}

// sorts file array by extension ".sd"
int sortFileArray(File *fileArray, File *unsortedFileArray) {
    int arrayLength = getFileArrayLength(*unsortedFileArray);

    for (int i = 0; i < arrayLength; i++) {
        char *directory = unsortedFileArray[i].directory;
        printf("%s", directory);

        char *result = strstr(directory, ".sd");

        if (result) {
            fileArray[i] = unsortedFileArray[i];
        } else {
            continue;
        }
    }

    return 0;
}

// returns file array length
int getFileArrayLength(File fileArray) {
    return sizeof(fileArray) / sizeof(File);
}

char* readFileStruct(File file) {
    return file.contents;
}

bool isFile(char *directory) {
    DIR *openDirectory = opendir(directory);

    if (openDirectory != NULL) {
        closedir(openDirectory);
        return false;
    } else {
        return true;
    }
}