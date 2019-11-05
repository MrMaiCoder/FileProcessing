#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"


void push(Queue **q, char *word) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    char* copy = (char*) malloc(strlen(word)+1);
    strcpy(copy,word);
    newNode->data = copy;
    newNode->next = NULL;
    if (*q == NULL)
    {
        *q = (Queue*) malloc(sizeof(Queue));
        (*q)->head = NULL;
        (*q)->tail = NULL;
    }
    if(((*q)->head != NULL) && ((*q)->tail != NULL)){
        (*q)->tail->next = newNode;
        (*q)->tail = newNode;
    }else if (((*q)->head !=  NULL) && ((*q)->tail == NULL))
    {
        (*q)->head->next = newNode;
        (*q)->tail = newNode;
    }else{
        (*q)->head = newNode;
    }
}

char *pop(Queue *q) {
    Node* headNode;
    char* headData;
    if (isEmpty(q))
    {
        return NULL;

    }else
    {
        headNode = q->head;
        headData = headNode->data;
        q->head = q->head->next;
        if (q->tail != NULL)
        {
            q->tail = q->tail->next;
        }
        free(headNode);
        return headData;
    }
}

void print(Queue *q) {
    if(isEmpty(q)){
        printf("No items\n");

    }else{
        Node *headNode = q->head;
        while (headNode != NULL)
        {
            char* headData = headNode->data;
            printf("%s\n", headData);
            headNode = headNode->next;
        }
    }
    
}

int isEmpty(Queue *q) {
    if (q == NULL){
        return 1;
    }else{
        if (q->head == NULL && q->tail == NULL){
            return 1;
        }else{
            return 0;
        }
    }
}

void delete(Queue *q) {
    while (!isEmpty(q))
    {
        Node* remove = q->head;
        q->head = q->head->next;
        if (q->tail != NULL)
        {
            q->tail = q->tail->next;
        }
        free(remove->data);
        free(remove);
    }
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Queue *q = NULL;

    // print the queue
    print(q);

    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    print(q);

    // pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        printf("%s\n", item);
        free(item);
    }

    char *item = pop(q);
    assert(item == NULL);

    // push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the queue
    delete(q);

    // print again
    print(q);

    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);
}
