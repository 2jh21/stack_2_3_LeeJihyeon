#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct {
	element* data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == s->capacity - 1);
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty!\n");
		return;
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty!\n");
		return;
	}
	else return s->data[s->top];
}

int main() {
	StackType s;
	init_stack(&s);
	for (int i = 0; i < 30; i++) {
		int rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 0) {
			push(&s, rand_num);
			printf("[%d] Push %d\n", i + 1, rand_num);
		}
		else
			printf("[%d] Pop %d\n", i + 1, pop(&s));
	}
	free(s.data);
	system("pause");
	return 0;
}