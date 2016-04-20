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

struct node * new_node(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node(struct node *root, int data){
	if (root == NULL) return new_node(data);

	if (data < root->data)
		root->left = add_node(root->left, data);
	else if (data > root->data)
		root->right = add_node(root->right, data);

	return root;
}
void inorder(struct node *root){
	if (!root){
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}
void swap_nodes(struct node *a, struct node *b){
	int temp = (a)->data;
	(a)->data = (b)->data;
	(b)->data = temp;
}
int main(){

	//Use it for testing ,Creating BST etc
	
	struct node *root = NULL;
	int arr[] = { 50, 25, 75, 15, 35,
		90, 5, 17, 45, 120,
		1, 7, 19, 39, 49,
		100, 20, 21, 22, 23 };
	int l = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < l; i++){
		root = add_node(root, arr[i]);
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
	struct node *temp = root->left->left->right;
	//printf("%d",get_closest_leaf_distance(root, temp));
	//inorder(root);
	printf("%d ",get_distance_temp(root, temp));
	getchar();
	return 0;
}
