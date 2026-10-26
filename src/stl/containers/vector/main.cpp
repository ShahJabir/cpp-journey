
#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<int> v;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int temp;
    std::cout << "Enter value " << i + 1 << ": ";
    std::cin >> temp;
    v.push_back(temp);
  }

  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
  }

  return 0;
}
