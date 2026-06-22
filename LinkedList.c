#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

Node* createNode(int value){
	Node *node = malloc(sizeof(Node));
	if (node == NULL) return NULL;
	node->value = value;
	node->next = NULL;
	return node;
}

int main(void){
	Node *first = createNode(10);
	Node *second = createNode(20);
	Node *third = createNode(30);

	first->next = second;
	second->next = third;
	third->next = NULL;

	Node *current = first;
	while(current != NULL){
		printf("%d\n", current->value);
		Node *next = current->next;
		free(current);
		current = next;
	}
	
	return 0;
}
