#include <stdio.h>
#include <stdlib.h>
typedef struct s_queue_node {
	int data;
	struct s_queue_node* next;
} s_queue_node;

typedef struct s_queue {
	int size;
	struct s_queue_node* head;
	struct s_queue_node* tail;
} s_queue;

s_queue* s_queue_create()
{
	s_queue* queue = malloc(sizeof(*queue));
	if (queue == NULL) {
		fprintf(stderr, "allocate mem error !\n");
		exit(EXIT_FAILURE);
	}
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
	printf("queue create success !\n");
	return queue;
}

s_queue_node* pop(s_queue* queue)
{
	if (queue->size == 0) {
		printf("queue is empty !\n");
		exit(0);
	}
	s_queue_node* head = queue->head;
	queue->head = head->next;
	queue->size--;
	return head;
}
s_queue_node* s_queue_node_create(int data)
{
	s_queue_node* node = malloc(sizeof(*node));
	node->data = data;
	node->next = NULL;
	printf("create a node\n");
	return node;
}
void add(s_queue* queue, s_queue_node* node)
{
	if (queue->size == 0) {
		queue->head = node;
		queue->tail = node;
		queue->size++;
		printf("add a node,data=%d\n", node->data);
		return;
	}
	queue->tail->next = node;
	queue->tail = node;
	queue->size++;
	printf("add a node,cursize=%d,data=%d\n", queue->size,node->data);
}

void print_queue(s_queue* queue)
{
	s_queue_node* current = queue->head;
	int index = 0;
	while (current != NULL) {
		printf("index=%d,node=%d\n", index++, current->data);
		current = current->next;
	}
}
void s_queue_destroy(s_queue* queue)
{
	s_queue_node* current = queue->head;
	while (current != NULL) {
		s_queue_node* next = current->next;
		free(current);
		current = next;
	}
	free(queue);
}

void main()
{
	s_queue* queue = s_queue_create();
	add(queue, s_queue_node_create(rand()));
	add(queue, s_queue_node_create(rand()));
	add(queue, s_queue_node_create(rand()));
	add(queue, s_queue_node_create(rand()));
	add(queue, s_queue_node_create(rand()));
	printf("==========head=%d==========\n", queue->head->data);
	print_queue(queue);
	s_queue_node* head = pop(queue);
	printf("==========poped data = %d=========\n", head->data);
	print_queue(queue);
	s_queue_destroy(queue);
}
