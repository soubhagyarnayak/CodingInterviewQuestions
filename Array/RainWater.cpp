/**
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water 
it is able to trap after raining.
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
**/

#include <iostream>

void printArray(int arr[], int length){
    std::cout << "\n Printing array \n";
    for(int i=0;i<length;i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int findCapturedRainWater(int height[], int length){
    int* left = new int[length];
    int* right = new int[length];
    for(int i=0;i<length;i++){
        left[i] = 0;
        right[i] = 0;
    }
    left[0] = height[0];
    for(int i=1;i<length;i++){
        left[i] = left[i-1]>height[i]?left[i-1]:height[i];
    }
    printArray(left, length);
    right[length-1] = height[length-1];
    for(int i=length-2;i>=0;i--){
        right[i] = right[i+1]>height[i]?right[i+1]:height[i];
    }
    printArray(right, length);
    int result = 0;
    for(int i=0;i<length;i++){
        int level = right[i]<left[i]?right[i]:left[i];
        result += level - height[i];
    }
    return result;
}

int main() {
    int* heights = new int[12]{0,1,0,2,1,0,1,3,2,1,2,1};
	int captured = findCapturedRainWater(heights,12);
    std::cout << captured << std::endl;
}