
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> v = {10, 20, 30};
  v.clear();

  try {
    std::cout << v.at(0) << '\n';
  } catch (const std::out_of_range &e) {
    std::cout << "Error: " << e.what() << '\n';
  }

  return 0;
}
