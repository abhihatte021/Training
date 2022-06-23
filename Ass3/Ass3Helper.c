#include"Ass3header.h"

void printLevelOrder(struct node* root)
{
	int rear, front;
	struct node** queue = createQueue(&front, &rear);
	struct node* temp_node = root;

	while (temp_node) {
		printf("%d ", temp_node->rno);
        printf("%s ", temp_node->name);
        printf("\n");

		/*Enqueue left child */
		if (temp_node->left)
			enQueue(queue, &rear, temp_node->left);

		/*Enqueue right child */
		if (temp_node->right)
			enQueue(queue, &rear, temp_node->right);

		/*Dequeue node and copy its value in temp_node*/
		temp_node = deQueue(queue, &front);
	}
}

struct node** createQueue(int* front, int* rear)
{
	struct node** queue = (struct node**)malloc(sizeof(struct node*) * MAX_Q_SIZE);

	*front = *rear = 0;
	return queue;
}

void enQueue(struct node** queue, int* rear,struct node* new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

struct node* deQueue(struct node** queue, int* front)
{
	(*front)++;
	return queue[*front - 1];
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int rno,char name[])
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->rno = rno;
    strcpy(node->name,name);
	node->left = NULL;
	node->right = NULL;

	return (node);
}
