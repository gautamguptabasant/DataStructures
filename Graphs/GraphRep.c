/*
Author		: Gautam Kumar
Date		: 28-06-2014
Description	: C program to parse the description of a graph from a file
Arguments	: ./GraphRep <file containing the graph details>
*/

#include <stdio.h>
#include <stdlib.h>

//Global declarations
#define dllLen 10

//Prototype declaration


struct graph {
	int no_of_edges;
	int no_of_vertices;
	int **Adj;
};

struct nodeList {
	int vertexNumber;
	struct nodeList *next;
};

int main(int argc, char **argv) {
	
	
	
	if (argc < 2) 
