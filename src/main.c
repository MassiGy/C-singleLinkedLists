#include "../headers/main.h"

int main(void)
{
    struct Node *head = create_node_list(10);

    head = push_list(head, 1);
    head = push_list(head, 2);
    head = push_list(head, 99);
    head = push_list(head, 8);
    head = push_list(head, 7);

    print_list(head);
    printf("---\n");

    int *arr = listToArray(head, 6);
    q_insertion_sort_array(arr,6);
    print_array(arr, 6);



    printf("---\n");

    struct Node* temp = arrayToList(arr,6);
    print_list(temp);

    return 0;
}
