#include "stdafx.h"
#include "FooHeader.h"


Node* newNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(Node* node) {
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(Node* node) {
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	printf("%d ", node->data);

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(Node* node) {
	if (node == NULL)
		return;

	/* first print data of node */
	printf("%d ", node->data);

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}


// 2
void doubleTree(Node* node) {
	Node* oldLeft;

	if (node == NULL) return;

	/* do the subtrees */
	doubleTree(node->left);
	doubleTree(node->right);

	/* duplicate this node to its left */
	oldLeft = node->left;
	node->left = newNode(node->data);
	node->left->left = oldLeft;
}


int size(Node* node) {
	if (node == NULL)
		return 0;
	else
		return(size(node->left) + 1 + size(node->right));
}


/*  This function traverses tree in post order to
to delete each and every node of the tree */
void deleteTree(Node* node) {
	if (node == NULL) return;

	/* first delete both subtrees */
	deleteTree(node->left);
	deleteTree(node->right);

	/* then delete the node */
	printf("\n Deleting node: %d", node->data);
	delete node;
}


// Returns true if given tree is BST.
bool isBST(Node* root, Node* l = NULL, Node* r = NULL) {
	// Base condition
	if (root == NULL)
		return true;

	// if left node exist then check it has
	// correct data or not i.e. left node's data
	// should be less than root's data
	if (l != NULL and root->data < l->data)
		return false;

	// if right node exist then check it has
	// correct data or not i.e. right node's data
	// should be greater than root's data
	if (r != NULL and root->data > r->data)
		return false;

	// check recursively for every node.
	return isBST(root->left, l, root) and
		isBST(root->right, root, r);
}

int sum(Node *root) {
	if (root == NULL)
		return 0;
	return sum(root->left) + root->data + sum(root->right);
}

/* returns 1 if sum property holds for the given
node and both of its children */
bool isSumTree(Node* node) {
	int ls, rs;

	/* If node is NULL or it's a leaf node then
	return true */
	if (node == NULL ||
		(node->left == NULL && node->right == NULL))
		return 1;

	/* Get sum of nodes in left and right subtrees */
	ls = sum(node->left);
	rs = sum(node->right);

	/* if the node and both of its children satisfy the
	property return 1 else 0*/
	if ((node->data == ls + rs) &&
		isSumTree(node->left) &&
		isSumTree(node->right))
		return 1;

	return 0;
}