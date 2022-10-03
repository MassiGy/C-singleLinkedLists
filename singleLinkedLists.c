#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

/* SORT OPERATION */

struct Node *merge_sort(struct Node *head, int length);
struct Node *merge_sort_proc(struct Node *left, int left_length, struct Node *right, int right_length);

int main(void)
{
    struct Node *head = createNode(1);

    head = push(head, 10);
    head = push(head, 2);
    head = push(head, 8);
    printList(head);
    printf("---\n");
    struct Node *left = head;
    struct Node *right = split(head, 2, right);

    left = merge_sort_proc(left, 2, right, 2);

    printList(left);
    printList(right);

    return 0;
}

struct Node *createNode(int number)
{
    struct Node *item = malloc(sizeof(struct Node));

    assert(item != NULL);

    item->val = number;
    item->next = NULL;
    return item;
}

void printList(struct Node *head)
{
    struct Node *walker = head;

    assert(walker != NULL);

    while (walker != NULL)
    {
        printf("%p -> %i\n", walker, walker->val);
        walker = walker->next;
    }
}

struct Node *push(struct Node *head, int number)
{
    assert(head != NULL);

    struct Node *walker = head;

    while (walker->next != NULL)
    {
        walker = walker->next;
    }

    walker->next = createNode(number);
    return head;
}

struct Node *pop(struct Node *head)
{

    assert(head != NULL);

    struct Node *walker = head;

    while (walker->next != NULL)
    {
        walker = walker->next;
    }

    return walker;
}

struct Node *unshift(struct Node *head, int number)
{
    assert(head != NULL);

    struct Node *item = createNode(number);

    assert(item != NULL);

    item->next = head;
    head = item;
    return head;
}

struct Node *shift(struct Node *head)
{
    assert(head != NULL);

    head = head->next;
    return head;
}

struct Node *destroy(struct Node *head)
{
    assert(head != NULL);

    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}

struct Node *insertAt(struct Node *head, int pos, int number)
{
    assert(head != NULL);

    if (pos <= 0)
    {
        head = unshift(head, number);
        return head;
    }

    struct Node *walker = head;
    int counter = 0;

    while (walker->next != NULL && counter < pos)
    {
        walker = walker->next;
        counter++;
    }

    assert(walker != NULL);

    struct Node *temp = createNode(number);

    temp->next = walker->next;

    walker->next = temp;

    return head;
}

struct Node *splice(struct Node *head, int pos, int deleteCount)
{
    assert(head != NULL);
    int counter;

    if (pos <= 0)
    {
        counter = 0;
        while (counter < deleteCount)
        {
            head = shift(head);
            counter++;
        }

        return head;
    }

    struct Node *walker = head;

    counter = 0;
    while (walker != NULL && counter < pos)
    {
        walker = walker->next;
        counter++;
    }

    assert(walker != NULL);

    struct Node *temp = walker;
    counter = 0;

    while (temp != NULL && counter <= deleteCount)
    {
        temp = temp->next;
        counter++;
    }

    assert(temp != NULL);

    // we need to to free the elementsToRemove

    struct Node *elementToFree;

    while (walker->next != temp)
    {
        elementToFree = walker->next;
        walker->next = walker->next->next;
        free(elementToFree);
    }
    return head;
}

struct Node *updateAt(struct Node *head, int pos, int newVal)
{
    assert(head != NULL);

    if (pos <= 0)
    {
        head->val = newVal;
        return head;
    }

    struct Node *walker = head;
    int counter = 0;

    while (walker != NULL && counter < pos)
    {
        walker = walker->next;
        counter++;
    }

    assert(walker != NULL);

    walker->val = newVal;

    return head;
}

struct Node *split(struct Node *head, int pos, struct Node *rest)
{
    assert(head != NULL);

    struct Node *walker = head;

    int counter = 1;

    while (walker != NULL && counter < pos)
    {
        walker = walker->next;
        counter++;
    }

    assert(walker != NULL);

    rest = walker->next;
    walker->next = NULL;
    return rest;
}

struct Node *merge_sort(struct Node *head, int length)
{
    assert(head != NULL);

    assert(length > 0);

    if (length < 2)
    {
        return head;
    }

    int half = length / 2;

    struct Node *left = head;
    struct Node *right = split(head, half, right);

    return merge_sort_proc(merge_sort(left, half), half, merge_sort(right, length - half), length - half);
}

struct Node *merge_sort_proc(struct Node *left, int left_length, struct Node *right, int right_length)
{
    assert(left != NULL);
    assert(right != NULL);
    assert(left_length >= 1);
    assert(right_length >= 1);

    // int counter = 0;

    int left_walker = 0;
    int right_walker = 0;

    while (right_walker < right_length && left_walker < left_length)
    {
        if ((left + left_walker)->val <= (right + right_walker)->val)
        {
            left_walker++;
        }
        else
        {
            // swap them;
            int temp = (left + left_walker)->val;
            (left + left_walker)->val = (right + right_walker)->val;
            (right + right_walker)->val = temp;

            // increment the right walker;
            right_walker++;
        }
    }

    return left;
}