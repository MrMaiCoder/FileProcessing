/* Name:
 * ID:
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void printHelper(Node *tree,int frontier);

void insert(Node **tree, int val) {
    if (*tree == NULL)
    {
        *tree = (Node*) malloc(sizeof(Node));
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->data = val;
    }else{
        Node* root = *tree;
        Node** left = &(root->left);
        Node** right = &(root->right);
        if (root->data > val){
            insert(left, val);
        }else{
            insert(right, val);
        }
    }
}

void print(Node *tree) {
    if (tree != NULL)
    {
        printHelper(tree,0);
    }   
}

void printHelper(Node *tree,int frontier){
    Node *currentNode = tree;
    if (currentNode != NULL){
        for (int i = 0; i < frontier - 1; i++){
            printf(" ");
        }
        if (frontier > 0){
            printf("|-");
        }

        printf("%d\n", currentNode->data);

        if (currentNode->left){
            printHelper(currentNode->left,frontier+1);
        }
        if (currentNode->right){
            printHelper(currentNode->right,frontier+1);
        }
    }
}

void delete(Node *tree) {
    if (tree->left == NULL && tree->right == NULL){
            free(tree);
            return;
    }else if (tree->left == NULL && tree->right != NULL){
            delete(tree->right);
    }else{
        delete(tree->left);
        if (tree->right != NULL){
            delete(tree->right);
        }
    }
    free(tree);
}

Node *lookup(Node ** tree, int val){
    Node *looking = NULL;
    if (*tree != NULL){
        if ((*tree)->data == val){
            looking = (*tree);
        }
        if ((*tree)->left != NULL){
            looking = lookup(&((*tree)->left), val);
            if (looking != NULL){
                return looking;
            }
        }
        if ((*tree)->right != NULL){
            looking = lookup(&((*tree)->right), val);
            if (looking != NULL){
                return looking;
            }
        }
    }
    return looking;
}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}
