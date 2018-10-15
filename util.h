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

void print_vector_array(const std::vector<std::vector<int>> vec_arr) {
  if (vec_arr.empty()) {
    std::cout << "[]" << std::endl;
    return;
  }
  std::cout << "[" << std::endl;
  for (int i = 0; i < vec_arr.size(); ++i)
    print_vector(vec_arr[i]);
  std::cout << "]" << std::endl;
}

#endif  // LEETCODE_UTIL_H_
