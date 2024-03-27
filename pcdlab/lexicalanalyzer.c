#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int keywordsLength = 3;
const int operatorsLength = 2;
const int symbolsLength = 5;

char *keywords[3] = {"void", "int", "main"};
char *operator[2] = {"+", "="};
char *symbols[5] = {"(", ")", "{", "}", ";"};

void clearToken(char token[], int size) {
    for (int i = 0; i < size; i++) {
        token[i] = '\0';
    }
}

void processToken(char token[], int size) {
    if (size == 0) {
        return;
    }
    for (int i = 0; i < keywordsLength; ++i) {
        if (strcmp(token, keywords[i]) == 0) {
            printf("%s |(keyword)\n", keywords[i]);
            return;
        }
    }
    for (int i = 0; i < operatorsLength; ++i) {
        if (strcmp(token, operator[i]) == 0) {
            printf("%s |(operator)\n", operator[i]);
            return;
        }
    }
    for (int i = 0; i < symbolsLength; ++i) {
        if (strcmp(token, symbols[i]) == 0) {
            printf("%s |(symbol)\n", symbols[i]);
            return;
        }
    }
}

void logic(char buffer[], int size) {
    char *temp = (char *)malloc((size + 1) * sizeof(char));
    int tempIndex = 0;
    for (int i = 0; i < size; i++) {
        if (buffer[i] == ' ' || buffer[i] == '\n') {
            temp[tempIndex] = '\0';
            processToken(temp, tempIndex);
            clearToken(temp, tempIndex);
            tempIndex = 0;
            continue;
        }
        temp[tempIndex] = buffer[i];
        tempIndex++;
    }
    free(temp);
}

int main() {
    FILE *file;
    file = fopen("add.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    int lSize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc((lSize + 1) * sizeof(char));
    fread(buffer, lSize, 1, file);
    buffer[lSize] = '\0';

    logic(buffer, lSize);

    fclose(file);
    free(buffer);

    printf("________________\n");

    return 0;
}