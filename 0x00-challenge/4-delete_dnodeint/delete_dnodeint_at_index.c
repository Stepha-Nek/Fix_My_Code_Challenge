#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL) // Check if the list is empty
    {
        return (-1); // Return -1 to indicate failure (empty list)
    }

    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int p;

    saved_head = *head;
    p = 0;
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }
    if (p != index)
    {
        *head = saved_head;
        return (-1);
    }
    if (0 == index)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        if (tmp != NULL)
        {
            tmp->prev = NULL;
        }
    }
    else
    {
        (*head)->prev->prev = (*head)->prev;
        free(*head);
        if ((*head)->next)
            (*head)->next->prev = (*head)->prev;
        *head = saved_head;
    }
    return (1);
}

