#include "../headers/main.h"

int main(void)
{
    struct Node *head = createNode(10);

    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 99);
    head = push(head, 8);
    head = push(head, 7);

    printList(head);
    printf("---\n");
    bubble_sort(head,6);
    printList(head);


    return 0;
}
