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

Node* findLca(Node* root, int value1, int value2) {
	if (root == nullptr) {
		return nullptr;
	}
	if (value1 == root->value || value2 == root->value) {
		return root;
	}
	Node* left = findLca(root->left, value1, value2);
	Node* right = findLca(root->right, value1, value2);
	if (left && right) {
		return root;
	}
	if (left == nullptr) {
		return right;
	}
	else {
		return left;
	}
}

void printLca(Node* root, int value1, int value2) {
	Node* lca = findLca(root, value1, value2);
	if (lca == nullptr) {
		std::cout << "There is no LCA for nodes " << value1 << " "<< value2 << std::endl;
	}
	else {
		std::cout << "The LCA of nodes " << value1 << " " << value2 << " is " << lca->value << std::endl;
	}
}

int main() {
	Node* root = createNode(5);
	root->left = createNode(4);
	root->right = createNode(6);
	root->left->left = createNode(3);
	root->right->right = createNode(7);
	root->right->right->right = createNode(8);
	printLca(root, 7, 8);
	printLca(root, 4, 6); 
	printLca(root, 3, 7);
	printLca(root, 3, 4);
}