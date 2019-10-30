#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv){
    FILE *reader;
    int read, copy;
    char readChar;
    int wcount = 0;
    int lcount = 0;
    int i;

    if(argc > 2){
     fprintf(stderr, "Instruction: wlc_count input\n");
     exit(1);   
    }
    if(argc == 2){
        if((reader = fopen(argv[1], "r")) == NULL){
            fprintf(stderr, "Error opening read file,\n");
            exit(1);
        }

        while ((readChar = getc(reader)) != EOF){
            if (readChar == ' ' || readChar == '\n' || readChar == '\t') {
                wcount++;
            }
            if (readChar == '\n') {
                lcount++;
            }
        }
        fprint(stderr, "%d words and %d lines", wcount, lcount);
        fclose(reader);
        return 0;

    }

    char str[1000];
    gets(str);

    wcount = 1;
    lcount = 1;
    if(str[0] == '\0') {
        wcount = 0;
        lcount = 0;
    }
    for(i = 0; str[1] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            if (str[i+1] == '\0') break;
            if (str[i+1] == '\n') continue;
            if (str[i+1] != ' ') wcount++;
        }
        if (str[i] == '\n') {
            lcount++;
        }
    }

    fprintf(stderr, "%d words and %d lines", wcount, lcount);

    return 0;

}