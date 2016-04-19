/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
int inorderrecursion(struct node *root, int *arr, int i);
int preorderrecursion(struct node *root, int *arr, int i);
int postorderrecursion(struct node *root, int *arr, int i);
struct node{
	struct node *left;
	int data;
	struct node *right;
};

void inorder(struct node *root, int *arr){
	if (root != NULL && arr!=NULL){
		int i = 0;
		i=inorderrecursion(root, arr, i);
	}
}
int inorderrecursion(struct node *root, int *arr, int i){
	if (root != NULL){
		i = inorderrecursion(root->left,arr,i);
		arr[i++] = root->data;
		i = inorderrecursion(root->right, arr, i);
		return i;
	}
	else{
		return i;
	}
}


void preorder(struct node *root, int *arr){
	if (root != NULL && arr!=NULL){
	    int i = 0;
		i=preorderrecursion(root, arr, i);
	}
}
int preorderrecursion(struct node *root, int *arr, int i){
	if (root != NULL){
		arr[i++] = root->data;
		i = preorderrecursion(root->left, arr,i);
		i = preorderrecursion(root->right, arr,i);
		return i;
	}
	else{
		return i;
	}
}

void postorder(struct node *root, int *arr){
	if (root != NULL && arr!=NULL){
	    int i = 0;
		i=postorderrecursion(root, arr, i);
	}
}
int  postorderrecursion(struct node *root, int *arr, int i){
	if (root != NULL){
		i = postorderrecursion(root->left, arr,i);
		i = postorderrecursion(root->right, arr,i);
		arr[i++] = root->data;
		return i;
	}
	else{
		return i;
	}
}
