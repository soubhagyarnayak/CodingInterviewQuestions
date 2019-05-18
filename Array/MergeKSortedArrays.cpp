#include <iostream>
#include <vector>
#include <queue>

struct ArrayPosition {
	std::vector<int>::size_type position;
	int indexOfArray;
	int value;
	ArrayPosition(int position, int indexOfArray, int value) {
		this->position = position;
		this->indexOfArray = indexOfArray;
		this->value = value;
	}
};

struct ArrayPositionComparator {
	bool operator() (const ArrayPosition& p1, const ArrayPosition& p2) {
		return p1.value > p2.value;
	}
};

std::vector<int> MergeKSortedArrays(const std::vector<std::vector<int>> &arrays) {
	std::priority_queue <ArrayPosition, std::vector<ArrayPosition>, ArrayPositionComparator> positionHeap;
	std::vector<int> result;
	for (std::vector<int>::size_type i = 0; i < arrays.size(); i++) {
		if (!arrays[i].empty()) {
			positionHeap.push(ArrayPosition(0, i, arrays[i][0]));
		}
	}
	while (!positionHeap.empty()) {
		ArrayPosition position = positionHeap.top();
		result.push_back(position.value);
		if (position.position < arrays[position.indexOfArray].size() - 1) {
			positionHeap.push(ArrayPosition(position.position + 1, position.indexOfArray, arrays[position.indexOfArray][position.position + 1]));
		}
		positionHeap.pop();
	}
	return result;
}

void print(const std::vector<int>& data) {
	for (std::vector<int>::size_type i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void MergeAndPrintKSortedArrays(const std::vector<std::vector<int>>& arrays) {
	for (std::vector<int>::size_type i = 0; i < arrays.size(); i++) {
		std::cout << "Printing input array " << i << ":" << std::endl;
		print(arrays[i]);
	}
	std::cout << "Printing the result array:" << std::endl;
	print(MergeKSortedArrays(arrays));
}

int main() {
	std::vector<std::vector<int>> inputs;
	inputs.push_back({ 5, 15, 24, 29, 35, 45});
	inputs.push_back({ 1, 2, 23, 32, 40, 42 });
	inputs.push_back({ 4, 12, 22, 34 });
	inputs.push_back({ 40, 42 });
	inputs.push_back({ 3, 8, 9, 10, 31, 45, 47 });
	MergeAndPrintKSortedArrays(inputs);
}