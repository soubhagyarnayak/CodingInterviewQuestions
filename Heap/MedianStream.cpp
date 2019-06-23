#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

/***
Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2

***/

void printVector(const std::vector<float>& data) {
	std::cout << ">>";
	for (std::vector<float>::size_type i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void printMedians(float stream[], size_t size) {
	std::vector<float> left;
	std::vector<float> right;
	for (std::vector<float>::size_type i = 0; i < size; i++) {
		float median = 0;
		if (left.size() == right.size()) {
			if (left.size() == 0 || stream[i] < left.front()) {
				left.push_back(stream[i]);
				std::push_heap(left.begin(), left.end());
				median = left.front();
			}
			else {
				right.push_back(stream[i]);
				std::push_heap(right.begin(), right.end(), std::greater<int>());
				median = right.front();
			}
		}
		else if (left.size() > right.size()) {
			if (stream[i] < left.front()) {
				right.push_back(left.front());
				left.pop_back();
				std::push_heap(left.begin(), left.end());
				left.push_back(stream[i]);
				std::push_heap(left.begin(), left.end());
				std::push_heap(right.begin(), right.end(), std::greater<int>());
			}
			else {
				right.push_back(stream[i]);
				std::push_heap(right.begin(), right.end(), std::greater<int>());
			}
			median = ((left.front()+right.front()) / 2);
		}
		else {
			if (stream[i] > right.front()) {
				left.push_back(right.front());
				right.erase(right.begin());
				std::push_heap(right.begin(), right.end(), std::greater<int>());
				right.push_back(stream[i]);
				std::push_heap(left.begin(), left.end());
				std::push_heap(right.begin(), right.end(), std::greater<int>());
			}
			else {
				left.push_back(stream[i]);
				std::push_heap(left.begin(), left.end());
			}
			median = ((left.front() + right.front()) / 2);
		}
		std::cout << median << std::endl;
		//printVector(left);
		//printVector(right);
	}
}

int main() {
	float stream[] = { 2, 1, 5, 7, 2, 0, 5 };
	printMedians(stream, sizeof(stream)/sizeof(stream[0]));
	return 0;
}