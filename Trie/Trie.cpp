#include <iostream>
#include <string>

struct Node {
	char value;
	Node* children[72];
};

Node* createNode(char value) {
	Node* node = new Node();
	node->value = value;
	for (int i = 0; i < 72; i++) {
		node->children[i] = nullptr;
	}
	return node;
}

void appendValue(Node* &node, std::string value, std::string::size_type position) {
	if (value.length() <= position) {
		return;
	}
	int index = int(value[position]) - int('a');
	if (node->children[index] == nullptr) {
		node->children[index] = createNode(value[position]);
	}
	appendValue(node->children[index], value, position + 1);
}

void addValue(Node* &root, std::string value) {
	if (root == nullptr) {
		root = createNode('.');
	}
	int position = int(value[0]) - int('a');
	if (root->children[position] == nullptr) {
		root->children[position] = createNode(value[0]);
	}
	appendValue(root->children[position], value, 1);
}

bool isPresent(Node* node, std::string value, std::string::size_type position) {
	if (value.length() <= position) {
		return true;
	}
	int index = int(value[position]) - int('a');
	if (node->children[index] == nullptr) {
		return false;
	}
	return isPresent(node->children[index], value, position + 1);
}

bool isPresent(Node* root, std::string value) {
	return isPresent(root, value, 0);
}

void checkPresence(Node* root, const std::string value, bool expectedResult) {
	bool actualResult = isPresent(root, value);
	if (expectedResult != actualResult) {
		std::cout << "ERROR: Expected: " << expectedResult << " Actual: " << actualResult << std::endl;
	}
	else {
		std::cout << "SUCCESS" << std::endl;
	}
}

int main() {
	Node* root = nullptr;
	addValue(root, "dog");
	addValue(root, "deer");
	addValue(root, "deal");
	checkPresence(root, "deal", true);
	checkPresence(root, "dummy", false);
	checkPresence(root, "dea", true);
	checkPresence(root, "deer", true);
	checkPresence(root, "cat", false);
	checkPresence(root, "dog", true);
}