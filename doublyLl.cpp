#include<stdio.h>
typedef struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node nodePool[500];

int nodePointer;
Node* front;
Node* last;

/* function to create a node */
Node* createNode(int data) {
	Node* newNode = &nodePool[nodePointer++];
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void init() {
	nodePointer = 0;
	front = createNode(0);
	last = front;
}

/* function to add at the front*/
void addAtFront(int data) {
	Node* newNode = createNode(data);
	newNode->next = front;
	// check if front is empty
	if (front == NULL) {
		last = newNode;
	}
	else {
		front->prev = newNode;
	}
	front = newNode;
}

/* function to insert a data after a node*/
void insertAfter(Node* node, int data) {
	Node* newNode = createNode(data);
	// if the node is inserted after last
	if (!node->next) last = newNode;
	newNode->next = node->next;
	node->next = newNode;
	newNode->prev = node;
}

/* function to add a data before a node*/
void insertBefore(Node* node, int data) {
	Node* newNode = createNode(data);
	newNode->next = node;
	if (!node->prev) {
		node->prev = newNode;
		newNode->prev = NULL;
		front = newNode;
		return;
	}
	node->prev->next = newNode;
	newNode->prev = node->prev;
	node->prev = newNode;
	return;
}

/* function to add data in the end */
void insertInEnd(int data) {
	Node* newNode = createNode(data);
	newNode->next = NULL;
	newNode->prev = last;
	if (!last) { // list empty
		front = newNode;
	}
	else {
		last->next = newNode;
	}
	last = newNode;
}

int main() {
	printf("Initializing Doubly Linked List..\n");
	init();
	insertAfter(front, 1);
	insertAfter(front, 4);
	insertAfter(last, 7);
	addAtFront(100);
	insertAfter(front, 9);
	insertAfter(last, 10);
	insertAfter(front, 20);
	addAtFront(80);
	insertInEnd(78);
	insertBefore(front, 99);
	Node* trav = front;
	printf("\nPrinting the doubly linked list..\n");
	while (trav) {
		printf("%d ", trav->data);
		trav = trav->next;
	}

	return 0;
}
