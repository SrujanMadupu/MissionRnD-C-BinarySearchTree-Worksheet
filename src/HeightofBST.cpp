/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int heightrecursion(struct node *node){
	if (node->left==NULL&&node->right==NULL){
		return 1;
	}
	else{
		int leftH = heightrecursion(node ->left);
		int rightH = heightrecursion(node->right);
		if (leftH >= rightH){
			return 1 + leftH;
		}
		else{
			return 1 + rightH;
		}
	}

}
int left_sum(struct node *node){
	if (node== NULL){
		return 0;
	}
	else{
		int lsum = left_sum(node->left);
		int rsum = left_sum(node->right);
		return node->data+lsum + rsum;
	}
}
int right_sum(struct node *node){
	if (node == NULL){
		return 0;
	}
	else{
		int lsum = right_sum(node->left);
		int rsum = right_sum(node->right);
		return node->data + lsum + rsum;
	}
}

int get_height(struct node *root){
	if (!root){
		return -1;
	}
	return heightrecursion(root);
}

int get_left_subtree_sum(struct node *root){
	if (!root){
		return -1;
	}
	return left_sum(root->left);
}

int get_right_subtree_sum(struct node *root){
	if (!root){
		return -1;
	}
	return right_sum(root->right);
}

