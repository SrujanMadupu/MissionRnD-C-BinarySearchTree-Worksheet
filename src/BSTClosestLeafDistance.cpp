/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
struct node* find_parent(struct node *root, struct node *temp){
	if (!root || !temp){
		return NULL;
	}
	if (root->left==temp || root->right==temp){
		return root;
	}
	if (root->data < temp->data){
		root = find_parent(root->right,temp);
	}
	else{
		root = find_parent(root->left, temp);
	}
	return root;
}

int IsLeaf(struct node *node){
	if (node->left == NULL && node->right == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int get_distance_temp(struct node *root, struct node *temp){
	if (!root || !temp){
		return 0;
	}
	if (root == temp){
		return 0;
	}
	if (root->data < temp->data){
	  return 1+get_distance_temp(root->right,temp);
	}
	else{
		return 1 + get_distance_temp(root->left,temp);
	}
}
void get_closer_leaf(struct node *temp, int leaf, int *min){
	if (!temp){
		return;
	}
	if (IsLeaf(temp) == 1){
		if (leaf < *min){
			*min = leaf;
		}
		return;
	}
	get_closer_leaf(temp->left, leaf + 1, min);
	get_closer_leaf(temp->right, leaf + 1, min);
}


int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (!root || !temp){
		return -1;
	}
	if (temp->left==NULL && temp->right==NULL){
		return 0;
	}
	int temptoleaf = 9999,leaf = 0;
	get_closer_leaf(temp, leaf, &temptoleaf);
	//printf("Temp to Leaf distance %d\n", temptoleaf);

	int roottoleaf = 9999;
	get_closer_leaf(root, leaf, &roottoleaf);
	//printf("root to Leaf distance %d\n", roottoleaf);

	struct node *parent = find_parent(root, temp);
    printf("%d ", parent->data);
	int parenttoleaf = 9999;
	get_closer_leaf(parent, leaf, &parenttoleaf);
	//printf("parent to Leaf distance %d\n", parenttoleaf);
	
	int roottotemp=get_distance_temp(root, temp);

	int temprootleaf = roottotemp + roottoleaf;
	int tempparentleaf = parenttoleaf + 1;
	//printf("%d %d", temprootleaf, tempparentleaf);
	if (temptoleaf < tempparentleaf && temptoleaf < temprootleaf){
		return temptoleaf;
	}
	else if (tempparentleaf < temptoleaf && tempparentleaf < temprootleaf){
		return tempparentleaf;
	}
	else{
		return temprootleaf;
	}

	return 0;
}