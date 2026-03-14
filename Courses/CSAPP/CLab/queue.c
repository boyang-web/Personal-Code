/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
	queue_t *newq = malloc(sizeof(queue_t));
	if (newq != NULL)
	{
		newq->head = NULL;
		newq->tail = NULL;
		newq->size = 0;
		return newq;
	}
	return NULL;
}

void q_free(queue_t *q)
{
	/* Remember to free the queue structue and list elements */
	if (q != NULL)
	{
		list_ele_t *temp = q->head;
		while (temp != NULL)
		{
			list_ele_t *temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
		free(q);
	}
}

bool q_insert_head(queue_t *q, int v)
{
	/* What should you do if the q is NULL? */
	/* What if malloc returned NULL? */
	if (q == NULL)
		return false;
	list_ele_t *temp = malloc(sizeof(list_ele_t));
	if (temp == NULL)
		return false;
	temp->value = v;
	temp->next = q->head;
	temp->prev = NULL;
	if (q->head != NULL)
		q->head->prev = temp;
	else
		q->tail = temp;

	q->head = temp;
	q->size++;

	return true;
}

/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
	if (q == NULL)
		return false;
	/* Remember: It should operate in O(1) time */
	list_ele_t *temp = malloc(sizeof(list_ele_t));
	if (temp == NULL)
		return false;
	temp->value = v;
	temp->next = NULL;
	if (q->head == NULL)
	{
		q->head = temp;
		q->tail = temp;
		temp->prev = NULL;
	}
	else
	{
		temp->prev = q->tail;
		q->tail->next = temp;
		q->tail = temp;
	}

	q->size++;
	return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
	if (q == NULL || q->head == NULL)
		return false;
	list_ele_t *old_head = q->head;
	if (vp != NULL)
		*vp = q->head->value;
	if (q->size == 1)
	{
		q->head = NULL;
		q->tail = NULL;
	}
	else
	{
		q->head->next->prev = NULL;
		q->head = q->head->next;
	}
	free(old_head);
	q->size--;
	return true;
}

int q_size(queue_t *q)
{
	if (q != NULL)
		return q->size;
	/* Remember: It should operate in O(1) time */
	return 0;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL || q->head == NULL)
        return;

    list_ele_t *cur = q->head;
    q->tail = q->head;  

    while (cur != NULL)
    {
        list_ele_t *next = cur->next;
        cur->next = cur->prev;
        cur->prev = next;

        if (next == NULL)
            q->head = cur;  

        cur = next;
    }
}

