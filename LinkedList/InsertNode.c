/*
Author		: Gautam Kumar
Date		: 24-06-2014
Description	: C program to insert nodes in a linked list
Arguments	: ./InsertNode [pos] item-value
*/

#include <stdio.h>
#include <stdlib.h>

//Global declarations
#define llLen 10

//Prototype declaration
void GenerateLinkedList(void);
void InsertNode(int insertLoc, int insertVal);

struct linkedList {
	int item;
	struct linkedList *next;
};

struct linkedList *head;

int main(int argc, char **argv) {
	struct linkedList *node = NULL;
	int insertLoc = 1;
	int insertVal = 0;
	
	head = (struct linkedList *) malloc(sizeof(struct linkedList));
	node = (struct linkedList *) malloc(sizeof(struct linkedList));
	
	// parsing the command line arguments
	if (argc == 3) {
		insertLoc = atoi(argv[1]) - 1;
		insertVal = atoi(argv[2]);
		printf("Inserting %d at location %d\n", 
			insertVal, insertLoc);
	} else if (argc == 2) {
		//insertLoc = atoi(argv[1]);
		insertVal = atoi(argv[1]);
		printf("Inserting %d at location %d\n", 
			insertVal, insertLoc);
	} else {
		printf("Invalid arguments. Usage: ./InsertNode <pos(1-%d)> <value>\n\
Exiting program...\n", llLen);
		exit(EXIT_SUCCESS);
	}
	
	//calling function to generate a linked list of size llLen
	GenerateLinkedList();
	
	//printing the list before insertion
	printf("=================Before==========================\n");
	node = head;
	int ctr = 0;
	for (ctr = 0; node->next != NULL; ctr++) {
		
		printf("%d\n", node->item);
		
		node = node->next;
		//printf("testing\n");fflush(stdout);
	}
	printf("%d\n", node->item);
	printf("=============================================================\n");
	
	//Calling function to insert new item at the desired location
	InsertNode(insertLoc, insertVal);
	
	//printing the list
	printf("=======================After========================\n");
	node = head;
	//int ctr = 0;
	for (ctr = 0; node->next != NULL; ctr++) {
		
		printf("%d\n", node->item);
		
		node = node->next;
		//printf("testing\n");fflush(stdout);
	}
	printf("%d\n", node->item);
	printf("=============================================================\n");
	return EXIT_SUCCESS;
}


void GenerateLinkedList() {
	time_t t;
	struct linkedList *tail = NULL, *node = NULL;
   
   	/* Intializes random number generator */
	srand((unsigned) time(&t));
	
	tail = (struct linkedList *) malloc(sizeof(struct linkedList));
	
	int ctr = 0;
	for (ctr = 0; ctr < llLen; ctr++) {
		
		node = (struct linkedList *) malloc(sizeof(struct linkedList));
		node->item = rand();
		node->next = NlULL;		
		tail->next = node;		
		tail = node;
		
		if (ctr == 0) {
			head = node;
		}
	}
	printf("headnode: %d\n", head->item);
	printf("Link list generated\n");
}
	   
void InsertNode(int insertLoc, int insertVal) {
	int ctr = 0;
	struct linkedList *node = NULL, *newNode;
	
	node = (struct linkedList *) malloc(sizeof(struct linkedList));
	newNode = (struct linkedList *) malloc(sizeof(struct linkedList));
	newNode->item = insertVal;
	newNode->next = NULL;
	if (insertLoc != 0) {
		node = head;
		for (ctr = 0; ctr < insertLoc-1; ctr++) {
			node = node->next;
		}

		newNode->next = node->next;	
		node->next = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
	printf("Node added\n");
}
	
		


