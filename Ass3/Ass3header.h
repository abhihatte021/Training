#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_Q_SIZE 100

struct node {
	int rno;
    char name[20];
	struct node* left;
	struct node* right;
};


struct node** createQueue(int*, int*);
void enQueue(struct node**, int*, struct node*);
struct node* deQueue(struct node**, int*);
struct node* newNode(int ,char []);
void printLevelOrder(struct node* );

