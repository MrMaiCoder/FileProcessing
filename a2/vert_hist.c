#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void fillZeroes(int counter[]);
int checkAlpha(char* input, int inputlen,char alphabets[], int counter[], int currentmax);
int checkAlphaHelper(int input, char alphabets[], int counter[]);
void printHist(int counter[], int max);
void printHistHelper(int counter[], int max);
char *inputString(FILE* fp, size_t size);

int main(){
    char* input = inputString(stdin, 10);
    int inputlen = strlen(input);
    int counter[26];
    int currentmax = 0;
    char alphabets[26] = "abcdefghijklmnopqrstuvwxyz";

    fillZeroes(counter);
    currentmax = checkAlpha(input, inputlen, alphabets, counter, currentmax);
    printHist(counter, currentmax);
    printf("abcdefghijklmnopqrstuvwxyz\n");

    return 0;
}

void fillZeroes(int counter[]){
    for (int i=0; i < 26; i++){
        counter[i] = 0;
    }
}

int checkAlpha(char* input, int inputlen,char alphabets[], int counter[], int currentmax){
    for (int i = 0; i < inputlen; i++){
        if (isalpha(input[i])){
            int max = checkAlphaHelper(input[i], alphabets, counter);
            if (max > currentmax) currentmax = max;
        }
    }
    return currentmax;
}

int checkAlphaHelper(int input, char alphabets[], int counter[]){
    int max;
    for (int i = 0; i < 26; i++){
        if (input == alphabets[i]){
            counter[i]++;
            max = counter[i];
        }
    }
    return max;
}

void printHist(int counter[], int max){
    int maxline = max;
    for (int i = 0; i < maxline; i++){
        printHistHelper(counter, max);
        max--;
    }
}

void printHistHelper(int counter[], int max){
    for (int i = 0; i < 26; i++){
        if (counter[i] >= max){
            printf("*");
        }else{
            printf(" ");
        }
    }
    printf("\n");
}

char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);
    if (!str) return str;
    while (EOF != (ch = fgetc(fp)) && ch != '\n'){
        str[len++] = ch;
        if (len == size){
            str = realloc(str, sizeof(char)*(size += 16));
            if (!str) return str;
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char)*len);
}