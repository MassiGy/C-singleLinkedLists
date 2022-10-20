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
    bubble_sort(head, 6);
    printList(head);

    printf("---\n");

    int *arr = listToArray(head, 6);

    for (int i = 0; i < 6; ++i)
    {
        printf("%i\n", *(arr + i));
    }

    printf("---\n");

    struct Node* temp = arrayToList(arr,6);
    printList(temp);

    return 0;
}
