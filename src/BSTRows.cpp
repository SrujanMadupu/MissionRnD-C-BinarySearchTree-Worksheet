/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int TNodes(struct node *root){
	if (root != NULL){
		return 1 + TNodes(root->left) + TNodes(root->right);
	}
	else{
		return 0;
	}
}
int enqueue(struct node **Queue, int rear, struct node *root){
	Queue[rear] = (struct node*)malloc(sizeof(struct node));
	Queue[rear] = root;
 	return rear + 1;
}
int dequeue(struct node **Queue, int front, int *result,int i){
	result[i] = Queue[front]->data;
	return front + 1;
}
int* RighttoLeft(struct node **Queue, int front, int rear, int *result, int i){
	while (front != rear){
		if ((Queue[front])->right != NULL){
			rear = enqueue(Queue, rear, Queue[front]->right);
		}
		if ((Queue[front])->left != NULL){
			rear = enqueue(Queue, rear, Queue[front]->left);
		}
		front = dequeue(Queue, front, result, i);
		i = i + 1 ; 
	}
	return result;
}
int* BSTRighttoLeftRows(struct node* root)
{   
	if (!root){
		return NULL;
	}
	struct node *Queue[100];
	int numberofnodes = TNodes(root);
	int *result = (int*)malloc(sizeof(int)*numberofnodes);
	int front = 0;
	Queue[0] = (struct node*)malloc(sizeof(struct node));
	int rear = enqueue(Queue, front , root);
	int i = 0;
	return RighttoLeft(Queue, front, rear, result,i);
}

