#include <stdio.h>
#include <stdlib.h>
typedef struct s_list {
	int* data;
	int size;
	int capacity;
} s_list;

s_list init(int capacity)
{
	s_list list;
	list.data = (int*)malloc(sizeof(int) * capacity);
	if (list.data == NULL) {
		perror("Memory allocate failed !");
		exit(EXIT_FAILURE);
	}
	list.size = 0;
	list.capacity = capacity;
	return list;
}

void resize(s_list* list)
{
	int new_capacity = list->capacity * 2;
	int* new_data = (int*)realloc(list->data, sizeof(int) * new_capacity);
	if (new_data == NULL) {
		perror("Memory allocate failed !");
		exit(EXIT_FAILURE);
	}
	list->capacity = new_capacity;
	list->data = new_data;
	printf("resize from %d to %d\n", list->capacity / 2, list->capacity);
}

void add(s_list* list, int data)
{
	if (list->size == list->capacity) {
		resize(list);
	}
	list->data[list->size++] = data;
	printf("add index=%d,data=%d,list.size=%d\n", list->size - 1, data,list->size);
}

void insert(s_list* list, int index, int data)
{
    if(list->size == list->capacity){
	    resize(list);
    }
    for(int i =list->size;i>=index;i--){
	    list->data[i] = list->data[i-1];
    
    }
    list->data[index] = data;
    list->size +=1;
    printf("insert index=%d,data=%d,list.size=%d\n", index, data,list->size);
}

void delete (s_list* list, int index)
{
	//ignore corner case like :-1/1000000/...
	if (index < list->size) {
		for (int i = index; i < list->size - 1; i++) {
			list->data[i] = list->data[i + 1];
		}
	}
	list->size -= 1;
	printf("deleted index=%d,list.size=%d\n", index, list->size);
}

int find(s_list* list, int data)
{
	for (int i = 0; i < list->size; i++) {
		if (list->data[i] == data) {
			return i;
		}
	}
	return -1;
}

void destroy(s_list* list)
{
	free(list->data);
	printf("data released\n");
}

int main()
{
	s_list list = init(10);
	printf("list init capacity=%d\n", list.capacity);
	for (int i = 0; i < 11; i++) {
		add(&list, rand());
	}
	delete (&list, 3);
	insert(&list,4,66666);
	for (int i = 0; i < list.size; i++) {
		printf("index=%d,data=%d \n", i, list.data[i]);
	}
	int val = find(&list, list.data[5]);
	printf("found data = %d,index = %d\n", list.data[5], val);
	destroy(&list);
	return 0;
}
