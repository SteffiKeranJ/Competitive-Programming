#include<stdio.h>
#include<stdlib.h>
#define MAX 200
int max(int a, int b) {
	return a >= b ? a : b;
}
struct Node
{
	int value;
	struct Node* next;
};
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data  */
	new_node->value = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

int count(Node* node, int key) {
	if (node == NULL) return 0;
	int freq = count(node->next, key);
	if (node->value == key) {
		return 1 + freq;
	}
	return freq;
}
int main() {
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);
	printf("The number of occurences of %d is %d", 1, count(head, 1));
	getchar();
	return 0;
}