#include "../headers/singleLinkedLists.h"

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

void insertion_sort(struct Node *head, int length)
{
    assert(head != NULL);
    assert(length >= 2);

    struct Node *sorted_sub_list_lastEl = head;

    int counter = 1;
    struct Node *traversal = head;

    while (counter < length)
    {
        if (traversal->next->val < sorted_sub_list_lastEl->val)
        {
           // insert the traversal node before the sorted_sub_list_lastEl
           struct Node* sub_sorted_list_traversal = head;

           while (sub_sorted_list_traversal->val < traversal->next->val
                 && sub_sorted_list_traversal != sorted_sub_list_lastEl)
         
           {
                sub_sorted_list_traversal = sub_sorted_list_traversal->next;
           }

           // sub_sorted_list_traversal now points to the element right before 
           // the element that contains the first val > traversal->val

           // insert a node with the traversal value as the next element on the 
           // sub_sorted_list_traversal element
            struct Node* element_to_insert = createNode(traversal->next->val);
            
            element_to_insert->next = sub_sorted_list_traversal;

            struct Node* rest = traversal->next->next;

            traversal->next->next = NULL;
            free(traversal->next);

            sub_sorted_list_traversal->next = rest;

            if(counter == 1) 
                head = element_to_insert;

        }

        traversal = traversal->next;        
        counter++;
    }
}

void bubble_sort(struct Node *head, int length)
{
    assert(head != NULL);
    assert(length >= 2);

    int i = 0;
    int j = 0;
    bool swaps = true;
    struct Node *current = head;

    while (i < length - 1 && swaps)
    {
        j = 0;
        current = head;
        swaps = false;

        while (j < length - i - 1)
        {
            if (current->next->val < current->val)
            {
                // swap
                int temp = current->val;
                current->val = current->next->val;
                current->next->val = temp;

                swaps = true;
            }

            current = current->next;
            j++;
        }
        i++;
    }
}
