// a header file containing preprocessor, lexer and parser prototypes

#define MAX 8192

typedef struct {
    char *directory;
    char *contents;
} File;

typedef struct {
    int tokenl;
    char *tokenv;
} Token;

typedef enum {
    false = 0,
    true = 1
} bool;

File openFile(char *directory);
char* readFileStruct(File file);

int readDirectory(char *directory, File *fileArray);
int sortFileArray(File *fileArray, File *unsortedFileArray);

int getFileArrayLength(File fileArray);

bool isFile(char *directory);