#include<iostream>
#include<string>

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

void deserialize(Node* &root, std::string serializedData, std::string::size_type &position) {
	if (position >= serializedData.size()) {
		return;
	}
	auto index = serializedData.find(" ", position);
	std::string token = serializedData.substr(position, index-position);
	position += token.size() + 1;
	if (token.compare("]") == 0) {
		return;
	}
	else {
		root = createNode(std::stoi(token));
		deserialize(root->left, serializedData, position);
		deserialize(root->right, serializedData, position);
	}
}

void runTest(Node* root) {
	Node* retrieved = nullptr; 
	std::string::size_type position = 0;
	std::string serializedTree = serialize(root);
	std::cout << serializedTree << std::endl;
	deserialize(retrieved, serializedTree, position);
	std::cout << serialize(retrieved) << std::endl;
}

int main() {
	Node* root = nullptr;
	runTest(root);
	
	root = createNode(100);
	root->left = createNode(50);
	root->right = createNode(200);
	root->left->left = createNode(25);
	root->left->right = createNode(75);
	root->left->left->right = createNode(35);
	root->right->right = createNode(400);
	root->right->right->left = createNode(350);
	root->right->right->left->right = createNode(375);
	runTest(root);
}