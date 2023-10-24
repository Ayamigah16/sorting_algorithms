#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - swap values before the node in a doubly-linked
 * @list: the head pointer of the linked list
 * @tail: the tail pointer of the linked list
 * @shaker: the current pointer of the swapping node.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *temp = (*shaker)->next;

if ((*shaker)->prev != NULL)
(*shaker)->prev->next = temp;
else
*list = temp;
temp->prev = (*shaker)->prev;
(*shaker)->next = temp->next;
if (temp->next != NULL)
temp->next->prev = *shaker;
else
*tail = *shaker;
(*shaker)->prev = temp;
temp->next = *shaker;
*shaker = temp;
}

/**
 * swap_node_behind - swap values behind the node in a doubly-linked
 * @list: the head pointer of the linked list
 * @tail: the tail pointer of the linked list
 * @shaker: the current pointer of the swapping node.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *temp = (*shaker)->prev;

if ((*shaker)->next != NULL)
(*shaker)->next->prev = temp;
else
*tail = temp;
temp->next = (*shaker)->next;
(*shaker)->prev = temp->prev;
if (temp->prev != NULL)
temp->prev->next = *shaker;
else
*list = *shaker;
(*shaker)->next = temp;
temp->prev = *shaker;
*shaker = temp;
}

/**
 * cocktail_sort_list - sorts a doubly-linked
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
bool shaken_not_stirred = false;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (tail = *list; tail->next != NULL;)
tail = tail->next;

while (shaken_not_stirred == false)
{
shaken_not_stirred = true;
for (shaker = *list; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n)
{
swap_node_ahead(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
for (shaker = shaker->prev; shaker != *list;
shaker = shaker->prev)
{
if (shaker->n < shaker->prev->n)
{
swap_node_behind(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
}
}
