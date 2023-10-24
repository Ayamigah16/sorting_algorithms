#include "deck.h"

int _strcmp(const char *s1, const char *str_2);
char get_val(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - compares two strings.
 * @str_1: the first string to compare.
 * @str_2: the second string to compare.
 *
 * Return: Positive byte difference if str_1 > str_2
 *         0 if str_1 == str_2
 *         Negative byte difference if str_1 < str_2
 */
int _strcmp(const char *str_1, const char *str_2)
{
while (*str_1 && *str_2 && *str_1 == *str_2)
{
str_1++;
str_2++;
}

if (*str_1 != *str_2)
return (*str_1 - *str_2);
return (0);
}

/**
 * get_val - gets the numerical value of a card.
 * @card: the pointer to a deck_node_t card.
 *
 * Return: the numerical value of the card.
 */
char get_val(deck_node_t *card)
{
if (_strcmp(card->card->value, "Ace") == 0)
return (0);
if (_strcmp(card->card->value, "1") == 0)
return (1);
if (_strcmp(card->card->value, "2") == 0)
return (2);
if (_strcmp(card->card->value, "3") == 0)
return (3);
if (_strcmp(card->card->value, "4") == 0)
return (4);
if (_strcmp(card->card->value, "5") == 0)
return (5);
if (_strcmp(card->card->value, "6") == 0)
return (6);
if (_strcmp(card->card->value, "7") == 0)
return (7);
if (_strcmp(card->card->value, "8") == 0)
return (8);
if (_strcmp(card->card->value, "9") == 0)
return (9);
if (_strcmp(card->card->value, "10") == 0)
return (10);
if (_strcmp(card->card->value, "Jack") == 0)
return (11);
if (_strcmp(card->card->value, "Queen") == 0)
return (12);
return (13);
}

/**
 * insertion_sort_deck_kind - sorts a deck of cards from spades to diamonds.
 * @deck: the pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
deck_node_t *iter, *insert, *tmp;

for (iter = (*deck)->next; iter != NULL; iter = tmp)
{
tmp = iter->next;
insert = iter->prev;
while (insert != NULL && insert->card->kind > iter->card->kind)
{
insert->next = iter->next;
if (iter->next != NULL)
iter->next->prev = insert;
iter->prev = insert->prev;
iter->next = insert;
if (insert->prev != NULL)
insert->prev->next = iter;
else
*deck = iter;
insert->prev = iter;
insert = iter->prev;
}
}
}

/**
 * insertion_sort_deck_value - sorts a deck of cards sorted from
 * spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
deck_node_t *iter, *insert, *tmp;

for (iter = (*deck)->next; iter != NULL; iter = tmp)
{
tmp = iter->next;
insert = iter->prev;
while (insert != NULL &&
insert->card->kind == iter->card->kind &&
get_val(insert) > get_val(iter))
{
insert->next = iter->next;
if (iter->next != NULL)
iter->next->prev = insert;
iter->prev = insert->prev;
iter->next = insert;
if (insert->prev != NULL)
insert->prev->next = iter;
else
*deck = iter;
insert->prev = iter;
insert = iter->prev;
}
}
}

/**
 * sort_deck - sorts a deck of cards from ace to king and
 * from spades to diamonds.
 * @deck: the pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
return;

insertion_sort_deck_kind(deck);
insertion_sort_deck_value(deck);
}
