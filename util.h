#ifndef LEETCODE_UTIL_H_
#define LEETCODE_UTIL_H_

#include <iostream>
#include <string>
#include <vector>

void print_vector(const std::vector<int> nums) {
  if (nums.empty()) {
    std::cout << "[]";
    return;
  }
  std::cout << "[";
  int size = nums.size();
  for (int i = 0; i < size - 1; ++i) {
    std::cout << nums[i] << ", ";
  }
  std::cout << nums[size-1] << "]" << std::endl;
}

void print_vector(const std::vector<std::string> nums) {
  if (nums.empty()) { 
    std::cout << "[]";
    return;
  } 
  std::cout << "[";
  int size = nums.size();
  for (int i = 0; i < size - 1; ++i) { 
    std::cout << "\"" << nums[i] << "\", ";
  } 
  std::cout << nums[size-1] << "]" << std::endl;
}

#endif  // LEETCODE_UTIL_H_
