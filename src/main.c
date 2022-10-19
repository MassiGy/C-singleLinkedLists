#include "../headers/main.h"

int main(void)
{
    struct Node *head = createNode(1);

    head = push(head, 10);
    head = push(head, 2);
    head = push(head, 99);
    head = push(head, 8);
    head = push(head, 7);

    printList(head);
    printf("---\n");

    head = binary_sort_proc(head, 3, head + 3, 3);
    printList(head);

    return 0;
}
