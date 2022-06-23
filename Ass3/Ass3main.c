#include"Ass3header.h"

int main()
{
	struct node* root = newNode(1,"Abhishek");
	root->left = newNode(2,"Harshal");
	root->right = newNode(3,"Sahil");
	root->left->left = newNode(4,"Mittali");
	root->left->right = newNode(5,"Sushmita");

	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);

	return 0;
}