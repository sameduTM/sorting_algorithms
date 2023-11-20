#include <stdio.h>
#include "sort.h"
/**
 * nodes_swp - swaps the nodes in a d-linked list.
 * @head: pointer to the head of the d-linked list
 * @node1: pointer to first node to swap
 * @node2: pointer to second node in swap
 *
 * Return: nothing
 */
void nodes_swp(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
/**
 * insertion_sort_list - sorts a doubly-linked list of integers in
 * ascending order using the Insertion sort algorithm
 * integers in ascending order
 * @list: pointer to the doubly-linked list to be sorted
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *temp, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			nodes_swp(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
