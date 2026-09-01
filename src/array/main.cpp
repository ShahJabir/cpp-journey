#include <iostream>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};

  std::cout << "Memory address of arr: " << arr << std::endl;
  /* only using the name of array "arr" is can give the address of the first
   element of array */

  std::cout << "Memory address of arr: " << &arr << std::endl;
  /* using the & in the array name "&arr" is can give the address of the full
    array memory address */

  for (int i = 0; i < 5; i++) {
    std::cout << "Element at index of arr " << i << ": " << arr[i] << std::endl;
  }

  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << "Element at index (" << i << ", " << j
                << "): " << matrix[i][j] << std::endl;
    }
  }

  return 0;
}
