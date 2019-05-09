#include<iostream>
#include<queue>

struct Node {
	int value;
	Node* left;
	Node* right;
};

void printInLevelOrder(Node* root) {
	std::cout << std::endl;
	if (root == nullptr) {
		return;
	}
	std::queue<Node*> nodes;
	nodes.push(root);
	while (!nodes.empty()) {
		Node* node = nodes.front();
		std::cout << node->value << " ";
		if (node->left != NULL) {
			nodes.push(node->left);
		}
		if (node->right != NULL) {
			nodes.push(node->right);
		}
		nodes.pop();
	}
}

Node* createNode(int value) {
	Node* node = new Node();
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main() {
	Node* root = NULL;
	printInLevelOrder(root);
	root = createNode(100);
	root->left = createNode(50);
	root->right = createNode(200);
	root->left->left = createNode(25);
	root->left->right = createNode(75);
	root->left->left->right = createNode(35);
	root->right->right = createNode(400);
	root->right->right->left = createNode(350);
	root->right->right->left->right = createNode(375);
	printInLevelOrder(root);
}