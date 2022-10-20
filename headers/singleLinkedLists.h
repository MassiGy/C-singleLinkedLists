#include "./sys_headers.h"

struct Node
{
    /* data */
    int val;
    struct Node *next;
};

/*CRUD OPERATIONS*/

void printList(struct Node *head);
struct Node *createNode(int number);
struct Node *push(struct Node *head, int number);
struct Node *pop(struct Node *head);
struct Node *unshift(struct Node *head, int number);
struct Node *shift(struct Node *head);
struct Node *insertAt(struct Node *head, int pos, int number);
struct Node *updateAt(struct Node *head, int pos, int newVal);
struct Node *splice(struct Node *head, int pos, int deleteCount);
struct Node *split(struct Node *head, int pos, struct Node *rest);
struct Node *destroy(struct Node *head);

// array to list
struct Node *arrayToList(int *arr, int length);
int *listToArray(struct Node *head,int length);

/* SORTING OPERATIONS */
void bubble_sort(struct Node *head, int length);


