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
        int new_capacity = list->capacity*2;
	int* new_data = (int*)realloc(list->data,sizeof(int) * new_capacity);
	if(new_data==NULL){
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
	printf("add index=%d,data=%d\n", list->size - 1, data);
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
}

int find(s_list* list,int data){
    for(int i=0;i<list->size;i++){
        if(list->data[i]==data){
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
	for (int i = 0; i < list.size; i++) {
		printf("index=%d,data=%d \n", i, list.data[i]);
	}
	int val = find(&list,list.data[4]);
	printf("found data = %d,index = %d\n",list.data[4],val);
	destroy(&list);
	return 0;
}
