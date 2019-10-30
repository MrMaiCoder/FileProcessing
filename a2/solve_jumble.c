#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getDictionary(FILE *dictionary);
int checkWords(int index);
int cmpFn (const void * char1, const void * char2);

char jumbleString[50];
char sortedDict[50];
char dictString[500000][50];


int main(int argc, char **argv){
    FILE *dictionary, *jumbles;
    dictionary =fopen(argv[1],"r");
    jumbles = fopen(argv[2],"r");

    int foundMatch = 0;
    int index = getDictionary(dictionary);

    while (fgets(jumbleString, 50, jumbles) != NULL){
        int lastIndex = strlen(jumbleString) - 1;
        if (jumbleString[lastIndex] == '\n')
            jumbleString[lastIndex] = '\0';

        printf("%s: ", jumbleString);

        qsort(jumbleString, strlen(jumbleString), sizeof(char), cmpFn);

        foundMatch = checkWords(index);

        if (foundMatch == 0){
            printf("NO MATCHES");
        }
        foundMatch = 0;
        printf("\n");
    }

    fclose(dictionary);
    fclose(jumbles);
}

int getDictionary(FILE *dictionary){
    int dictIndex = 0;
    while (fgets(dictString[dictIndex], 50, dictionary) != NULL){
        int last = strlen(dictString[dictIndex]) - 1;
        if (dictString[dictIndex][last] == '\n'){
            dictString[dictIndex][last] = '\0';
        }
        dictIndex++;
    }
    return dictIndex;
}

int checkWords(int globalIndex){
    int checkFoundMatch;
    for(int i = 0; i < globalIndex; i++){
        strcpy(sortedDict, dictString[i]);  
        qsort(sortedDict, strlen(dictString[i]), sizeof(char), cmpFn);
        if (strcmp(jumbleString, sortedDict) == 0 ){
            printf("%s ", dictString[i]);
            checkFoundMatch = 1;
        }
    }
    return checkFoundMatch;
}

int cmpFn (const void * char1, const void * char2){
    return (strcmp((char*)char1, (char*)char2));
}