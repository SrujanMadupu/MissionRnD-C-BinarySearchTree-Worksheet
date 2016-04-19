/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void insert(struct node **q, int num){
	if (*q == NULL){
		(*q) =(struct node*)malloc(sizeof(struct node));
		(*q)->left = NULL;
		(*q)->data = num ;
		(*q)->right = NULL;
		return;
	}
	else{
		if (num<(*q)->data){
			insert(&((*q)->left), num);
		}
		else
			insert(&((*q)->right), num);
	}
	return;
}
void swap_nodes(struct node *a, struct node *b){
	int temp = (a)->data;
	(a)->data = (b)->data;
	(b)->data = temp;
}
int main(){

	//Use it for testing ,Creating BST etc
	
	struct node *root = NULL;
	int arr[] = { 2,1,3,4,5,6 },i;
	for ( i = 0; i < 20; i++){
	insert(&root, arr[i]);
	}
	/*
	struct node *swaplist[2];
	swaplist[0] = root->left->left->right->right;
	swaplist[1] = root;
	swap_nodes(swaplist[0], swaplist[1]);
	int *result=(int*)malloc(sizeof(int)*16);
	inorder(root, result);
	printf("Before Fixing");
	for (i = 0; i < 20; i++){
	printf("%d ", result[i]);
	}
	printf("\n");
	fix_bst(root);
	inorder(root, result);
	printf("After Fixing");
	for (i = 0; i < 20; i++){
	printf("%d ", result[i]);
	}
	*/
	//Testing closest leaf
	struct node *temp = root->left;
	
	return 0;
}
