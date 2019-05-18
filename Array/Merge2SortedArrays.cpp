#include <iostream>
#include <vector>

std::vector<int> Merge2SortedArrays(const std::vector<int> &first, const std::vector<int> &second) {
	std::vector<int> result;
	std::vector<int>::size_type i = 0;
	std::vector<int>::size_type j = 0;
	for (; i < first.size() && j < second.size();) {
		if (first[i] > second[j]) {
			result.push_back(second[j++]);
		}
		else {
			result.push_back(first[i++]);
		}
	}
	while (i < first.size()) {
		result.push_back(first[i++]);
	}
	while (j < second.size()) {
		result.push_back(second[j++]);
	}
	return result;
}

void print(const std::vector<int> &data) {
	for (std::vector<int>::size_type i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void MergeAndPrint2SortedArrays(const std::vector<int>& first, const std::vector<int>& second) {
	std::cout << "First array:" << std::endl;
	print(first);
	std::cout << "Second array" << std::endl;
	print(second);
	std::cout << "Merged array:" << std::endl;
	print(Merge2SortedArrays(first, second));
}

int main() {
	std::vector<int> a = { 1, 10, 13, 17, 18, 19, 30 };
	std::vector<int> b = { 2, 7, 8, 15, 20, 21, 22, 35, 46 };
	MergeAndPrint2SortedArrays(a, b);
	std::vector<int> c;
	MergeAndPrint2SortedArrays(a, c);
	MergeAndPrint2SortedArrays(c, b);
	MergeAndPrint2SortedArrays(c, c);
}