#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int initList(linkedlist *l) {
    if (!l) return NULL_LIST_LL;
    l->head = NULL;
    l->tail = NULL;
    l->count = 0;
    return SUCCESS_LL;
}

int insertFront(linkedlist *l, void *data) {

    if (!l) return NULL_LIST_LL;
    if (!data) return NULL_DATA_LL;

    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->next = l->head;
    newnode->data = data;

    // DO NOT DO THIS
    // node newnode;
    // newnode.next = l->head;
    // newnode.data = data;

    l->head = newnode;
    (l->count)++;

    // if the list was empty
    if (!(l->tail)) l->tail = l->head;

    return SUCCESS_LL;
}

int removeFront(linkedlist *l, void **data_ptr)
{
    if (!l) return NULL_LIST_LL;
    if (!l->count) return EMPTY_LIST_LL;

    node *zombie;
    zombie = l->head;

    l->head = zombie->next;
    (l->count)--;

    *data_ptr = zombie->data;

    free(zombie);

    if (!l->count) l->tail = NULL;

    return SUCCESS_LL;

}

int destroyList(linkedlist *l)
{
    void *notused;

    if (!l) return NULL_LIST_LL;

    while (l->count) {
        removeFront(l, &notused);
    }

    return SUCCESS_LL;
}

int main() {
    linkedlist L;
    int one = 1;
    int two = 2;
    int *x;

    if (initList(&L) != SUCCESS_LL) {
        printf("Fail to initialize the linked list");
    }

    insertFront(&L, (void *)&one);
    insertFront(&L, (void *)&two);
    removeFront(&L, (void **)&x);
    printf("data = %d\n", *x);



}
