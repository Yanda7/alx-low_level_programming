#include "lists.h"
#include <stdio.h>
/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of elements in the list.
 */
size_t listint_len(const listint_t *head)
{
    size_t count = 0; // Initialize a count to keep track of the number of elements

    // Traverse the linked list
    while (head != NULL)
    {
        count++;       // Increment the count for each node visited
        head = head->next; // Move to the next node
    }

    return count; // Return the total count of elements in the list
}
