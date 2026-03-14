/*
在我们给你的C代码中，队列是一个类型为queue_t 的指针。
我们区分两种特殊情况：
一个*NULL队列是指针设置为NULL的队列。
而一个空（empty）队列是一个指向一个有效的queue_t结构的队列，该queue_t结构的head字段被设置为NULL。
除了能正确处理包含一个或多个元素的队列，你的代码还要能正确处理这两种情况。

编程任务
你的任务是修改queue.h和queue.c中的代码以实现以下功能：

q_new：创建一个新的空队列
q_free: 释放队列使用的所有存储空间
q_insert_head：在队列的头部插入新元素（LIFO）
q_insert_tail：在队列的尾部插入新元素（FIFO）
q_remove_head：从队列的头部删除一个元素
q_size: 计算队列中元素的个数
q_reverse：对列表重新排列，使得队列中元素的顺序都反转过来

更多细节可以在这两个文件的注释中找到，包括如何处理无效操作（例如，从空队列或NULL队列中移除元素），以及函数应该具有哪些副作用和返回值。
以下是关于如何实现这些功能的一些重要注意事项：
当q_new和q_insert_head需要动态分配内存时，使用malloc或calloc来实现（如果不熟悉这两个函数，可以在命令行中输入man malloc或man calloc来查阅手册；或者搜索引擎之）；
其中q_insert_tail 和 q_size需要满足时间复杂度为O(1)，即所需的时间与队列大小无关。你可以通过在queue_t数据结构中添加其他字段来实现此功能；
q_reverse的实现不需要分配额外的内存。你的代码应该修改现有链表中的指针。 在实现反向操作时，直接或间接调用malloc、calloc或free都视为错误；
测试代码会在超过1,000,000个元素的队列上对你的程序进行测试，所以不能使用递归函数来遍历这样的长列表，因为这需要太多的栈空间。（后续课程中，我们将深入学习这背后的原理，cool吧？）
*/
#include <stdio.h>
#include <stdbool.h>
/* Linked list element */
typedef struct ELE
{
	int value;
	struct ELE *next, *prev;
} list_ele_t;

/* Queue structure */
typedef struct
{
	list_ele_t *head, *tail; /* Linked list of elements */
	int size;
} queue_t;

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