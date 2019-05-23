/*
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <iostream>
#include <vector>

int findLargestSumOfNonAdjacent(const std::vector<int> &list, std::vector<int>::size_type start) {
	if (start >= list.size()) {
		return 0;
	}
	int includedSum = list[start] + findLargestSumOfNonAdjacent(list, start + 2);
	int excludedSum = findLargestSumOfNonAdjacent(list, start + 1);
	return includedSum > excludedSum ? includedSum : excludedSum;
}

int findLargestSumOfNonAdjacentOptimized(const std::vector<int>& list) {
	if (list.empty())
	{
		return 0;
	}
	int includedSum = list[0];
	int excludedSum = 0;
	for (std::vector<int>::size_type i = 1; i < list.size(); i++) {
		int excluded_current = includedSum > excludedSum ? includedSum : excludedSum;
		includedSum = excludedSum + list[i];
		excludedSum = excluded_current;
	}
	return includedSum > excludedSum ? includedSum : excludedSum;
}

void printLargestSumNonAdjacent(const std::vector<int>& list) {
	int sum = findLargestSumOfNonAdjacentOptimized(list);//findLargestSumOfNonAdjacent(list, 0);
	std::cout << "The given vector is: ";
	for (std::vector<int>::size_type i = 0; i < list.size(); i++) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl << "The largest sum of non-adjacent elements are: " << sum << std::endl;
}

int main() {
	std::vector<int> list1 = { 2, 4, 6, 2, 5 };
	printLargestSumNonAdjacent(list1);
	std::vector<int> list2 = { 5, 1, 1, 5 };
	printLargestSumNonAdjacent(list2);
}