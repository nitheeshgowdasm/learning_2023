#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void convertToUpper(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

void convertToLower(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

void convertToSentence(FILE *source, FILE *destination) {
    int ch;
    int startOfSentence = 1;
    while ((ch = fgetc(source)) != EOF) {
        if (startOfSentence) {
            fputc(toupper(ch), destination);
            startOfSentence = 0;
        } else {
            fputc(tolower(ch), destination);
        }
        if (ch == '.' || ch == '!' || ch == '?') {
            startOfSentence = 1;
        }
    }
}

void performCopy(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source file> <destination file>\n");
        return 1;
    }

    FILE *sourceFile, *destinationFile;
    sourceFile = fopen(argv[2], "r");
    if (sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    destinationFile = fopen(argv[3], "w");
    if (destinationFile == NULL) {
        printf("Unable to create destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(argv[1], "-u") == 0) {
        convertToUpper(sourceFile, destinationFile);
    } else if (strcmp(argv[1], "-l") == 0) {
        convertToLower(sourceFile, destinationFile);
    } else if (strcmp(argv[1], "-s") == 0) {
        convertToSentence(sourceFile, destinationFile);
    } else {
        performCopy(sourceFile, destinationFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
