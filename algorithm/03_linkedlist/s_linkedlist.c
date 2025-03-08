#include <stdio.h>
#include <stdlib.h>
typedef struct linked_node linked_node;
struct linked_node {
	int data;
	linked_node* next;
};
linked_node* init(int data)
{
	linked_node* node = (linked_node*)malloc(sizeof(linked_node));
	if (node == NULL) {
		printf("allocate mem failed !\n");
		exit(1);
	}
	node->next = NULL;
	node->data = data;
	return node;
}
//insert to tail
void add(linked_node* list, int data)
{

	linked_node* new_node = init(data);
	linked_node* current = list;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;
	printf("add a node\n");
}

//insert with index
void insert(linked_node* list, int index, int data)
{
	linked_node* current = list;
	for (int i = 0; i < index; i++) {
		if (current->next == NULL) {
			printf("out of index !\n");
			exit(1);
		}
		current = current->next;
	}
	linked_node* new_node = init(data);
	linked_node* next = current->next;
	new_node->next = next;
	current->next = new_node;
	printf("insert a node index=%d,data=%d\n", index, data);
}

void delete(linked_node* list, int index)
{
	//delete at head
	if (index == 0) {
		if (list->next == NULL) {
			printf("there is only one node !\n");
			exit(1);
		}
		linked_node* origin = list;
		list = list->next;
		free(origin);
		return;
	}
	linked_node* current = list;
	for (int i = 0; i < index; i++) {
		if (current->next == NULL) {
			printf("out of range !\n");
			exit(1);
		}
		current = current->next;
	}
	linked_node* next = current->next;
	if (next == NULL) {
		printf("out of range !\n");
		exit(1);
	}
	current->next = next->next;
	printf("delete success !\n");
}

int find(linked_node* list, int data)
{
	linked_node* current = list;
	int index = 0;
	while (current != NULL) {
		if (current->data == data) {
			printf("find data index=%d\n", index);
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;
}
void destroy(linked_node* list)
{

	linked_node* prev = list;
	linked_node* next = list->next;
	while (next != NULL) {
		free(prev);
		prev = next;
		next = next->next;
	}
	free(prev);
}
void print_list(linked_node* node)
{
	int index = 0;
	while (node != NULL) {
		printf("index=%d,data=%d\n", index, node->data);
		node = node->next;
		index++;
	}
}
void main()
{
	linked_node* list = init(1);
	add(list, 100);
	insert(list, 1, 200);
	insert(list, 0, 300);
	insert(list, 2, 400);
	print_list(list);
	delete (list, 1);
	print_list(list);
	find(list, 400);
}
