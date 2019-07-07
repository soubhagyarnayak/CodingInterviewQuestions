/**
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

	*
   / \
  +    +
 / \  / \
3  2  4  5

You should return 45, as it is (3 + 2) * (4 + 5).
**/

#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
};

Node* createNode(int value) {
	Node* node = new Node();
	node->value = value;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

int evaluate(const Node* node) {
	if (node->left != nullptr) { //assume the tree is proper
		int left = evaluate(node->left);
		int right = evaluate(node->right);
		int result = 0;
		if (node->value == int('+')) {
			result = left + right;
		}
		else if (node->value == int('-')) {
			result = left - right;
		} 
		else if (node->value == int('*')) {
			result = left * right;
		}
		else {//assume the rest is '/'
			result = left / right;
		}
		return result;
	}
	else {
		return node->value;
	}
}

int evaluateExpression(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return evaluate(root);
}

int main() {
	Node* root = createNode(int('*'));
	root->left = createNode(int('+'));
	root->right = createNode(int('+'));
	root->left->left = createNode(3);
	root->left->right = createNode(2);
	root->right->left = createNode(4);
	root->right->right = createNode(5);
	std::cout << evaluateExpression(root) << std::endl;
}