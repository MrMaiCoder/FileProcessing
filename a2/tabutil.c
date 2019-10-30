#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(FILE* fp, size_t size);
void tabToSpace(char* input, int inputlen, int numspace);
void printSpace(int numspace);
void spaceToTab(char* input, int inputlen, int numspace);

int main(int argc, char *argv[ ] ){
char prefixD[]="-d";
char prefixE[]="-e";
char* input = inputString(stdin, 10);
char inputlen = strlen(input);
int numspace = atoi(argv[2]);

    if(strcmp(prefixD,argv[1]) == 0){
        tabToSpace(input, inputlen, numspace);
    }else if (strcmp(prefixE, argv[1]) == 0){
        spaceToTab(input, inputlen, numspace);
}

printf("\n");
return 0;
}

void tabToSpace(char* input, int inputlen, int numspace){
	for(int i = 0; i < inputlen; i++){
		if(input[i] == '\t'){
            printSpace(numspace);
        }else{ 
            printf("%c", input[i]);
        }
    }
}

void printSpace(int numspace){
    for(int i = 0; i < numspace;i++){
		printf(" ");}
}

void spaceToTab(char* input, int inputlen, int numspace){
    int numspaceCount = 0;
    for(int i = 0; i < inputlen; i++){
	    if(input[i] == ' '){
            numspaceCount++;
		    if(numspaceCount==numspace){
			    printf("%c",'\t');
			    numspaceCount=0;
            }
        }else{
                printSpace(numspaceCount);
                printf("%c",input[i]);
                numspaceCount = 0;
	    } 
    }
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