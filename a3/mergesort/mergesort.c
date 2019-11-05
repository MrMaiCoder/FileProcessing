#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

int checkValid(int index, int num, int data, Entry *E);
void makeArray(Entry* sourceArray, Entry* splitArray, int from, int to);

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    int i = 0, j = 0, k = 0, left = 0, right = 0;
    while (k < (nL+nR))
    {
        left = checkValid(i, nL, left, L);
        right = checkValid(j, nR, right, R);

        if (((left != -1) && (left < right)) || (j >= nR)){
            output[k] = L[i];
            i++;
        }else{
            output[k] = R[j];
            j++;
        }
        k++;
    }
}

int checkValid(int index, int num, int data, Entry * E){
    if (index >= num){
        data = -1;
    }else{
        data = E[index].data;
    }

    return data;
}

void merge_sort(Entry *entries, int n) {
    if(n > 1){
        int mid = n / 2;
        int index = 0;
        int nL = mid;
        int nR = n - mid;

        Entry* tmp = (Entry*) malloc(sizeof(Entry) * n);
        Entry* L = (Entry*) malloc(sizeof(Entry) * nL);
        Entry* R = (Entry*) malloc(sizeof(Entry) * nR);

        makeArray(entries, L, 0, mid);
        makeArray(entries, R, mid, n);
        
        merge_sort(L,nL);
        merge_sort(R,nR);
        merge(tmp,L,nL,R,nR);
        
        makeArray(tmp, entries, 0, n);
        free(tmp);
        free(R);
        free(L);
    }
}

void makeArray(Entry* sourceArray, Entry* destArray, int start, int end){
    int index = 0;
    for (int i = start; i < end; i++){
        destArray[index] = sourceArray[i];
        index++;
    }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    int num = 0;
    scanf("%d", &num);
    Entry* items = (Entry*) malloc(sizeof(Entry)*num);
    for (int i = 0; i < num; i++){
        items[i].name = (char*) malloc(sizeof(char)*MAX_NAME_LENGTH);
        scanf("%d %s", &items[i].data, items[i].name);
    }
    merge_sort(items, num);

    printf("OUTPUT:\n");
    for (int i = 0; i < num; i++){
        printf("%d %s\n", items[i].data, items[i].name);
        free(items[i].name);
    }

    free(items);
}