#include <stdio.h>
typedef struct linked_node linked_node;
struct linked_node {
	int size;
	int data;
	linked_node* prev;
	linked_node* next;
};
linked_node init()
{
}
void add(linked_node* list, int data) { }
void insert(linked_node* list, int index, int data) { }
void delete (linked_node* list, int data) { }
int find(linked_node* list, int data) { }
void destroy(linked_node* list) { }
void main()
{
	printf("hello linklist\n");
}
