#include <stdio.h>
#include <stdlib.h>
typedef struct s_stack {
	int size;
	int capacity;
	int* data;
} s_stack;

s_stack init(int capacity)
{
	s_stack stack;
	stack.data = (int*)malloc(sizeof(int) * capacity);
	stack.size = 0;
	return stack;
}
int pop(s_stack* stack)
{
	if (stack->size == 0) {
		printf("stack is empty !\n");
		exit(0);
	}
	return stack->data[--stack->size];
}
void push(s_stack* stack, int data)
{
	//resize logic ,not implement yet
	//if(size==capacity){
	//resize();
	//}
	stack->data[stack->size++] = data;
}
void print_stack(s_stack* stack)
{
	for (int i = 0; i < stack->size; i++) {
		printf("index=%d,data=%d\n", i, stack->data[i]);
	}
}
void main()
{
	s_stack stack = init(5);
	push(&stack,rand());
	push(&stack,rand());
	push(&stack,rand());
	push(&stack,rand());
	push(&stack,rand());
	print_stack(&stack);
	int data = pop(&stack);
	printf("poped data = %d\n", data);
	print_stack(&stack);
}
