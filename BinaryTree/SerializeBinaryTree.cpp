#include<iostream>
#include<string>

struct Node {
	int value;
	Node* left;
	Node* right;
};

std::string serialize(Node* root) {
	std::string result;
	if (root == nullptr) {
		result.append("] ");
		return result;
	}
	result.append(std::to_string(root->value));
	result.append(" ");
	result.append(serialize(root->left));
	result.append(serialize(root->right));
	return result;
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
	std::string serializedTree = serialize(root);
	std::cout << serializedTree << std::endl;
	root = createNode(100);
	root->left = createNode(50);
	root->right = createNode(200);
	root->left->left = createNode(25);
	root->left->right = createNode(75);
	root->left->left->right = createNode(35);
	root->right->right = createNode(400);
	root->right->right->left = createNode(350);
	root->right->right->left->right = createNode(375);
	serializedTree = serialize(root);
	std::cout << serializedTree << std::endl;
}