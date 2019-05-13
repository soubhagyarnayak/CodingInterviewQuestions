#include<iostream>
#include<iterator>
#include<vector>

/*
Given an array of integers, return a new array such that each element at index i of the new array 
is the product of all the numbers in the original array except the one at i.
You cannot use division.
input: {10, 3, 5, 6, 2}
output: {180, 600, 360, 300, 900}
*/


void printProductArray(const std::vector<int>& input) {
	std::vector<int> output;
	int product = 1;
	for (int i = 0; i < input.size(); i++) {
		output.push_back(product);
		product *= input.at(i);
	}

	product = 1;
	for (int i = input.size() - 1; i >= 0; i--) {
		output.at(i) = output.at(i) * product;
		product *= input.at(i);
	}
	std::cout << "Input array is:" << std::endl;
	for (int i = 0; i < input.size(); i++) {
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Output array is:" << std::endl;
	for (int i = 0; i < output.size(); i++) {
		std::cout << output[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> input1 = { 1, 2, 3, 4, 5 };
	printProductArray(input1);
	std::vector<int> input2 = { 3, 2, 1 };
	printProductArray(input2);
	std::vector<int> input3 = { 10, 3, 5, 6, 2 };
	printProductArray(input3);
}