#include "../headers/main.h"

int main(void)
{
    struct Node *head = create_node_list(10);

    head = push_list(head, 1);
    head = push_list(head, 2);
    head = push_list(head, 99);
    head = push_list(head, 8);

    print_list(head);
    printf("---\n");

    int *arr = listToArray(head, 5);
    printf("---\n");

    merge_sort_array(&arr, 0, 4);
    // print_array(arr, 5);

    printf("---\n");

    struct Node *temp = arrayToList(arr, 5);
    print_list(temp);
    
    // free all the allocated mem
    destroy_list(head);
    destroy_list(temp);
    free(arr);

    return 0;
}
