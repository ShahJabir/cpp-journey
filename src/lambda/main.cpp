#include <bits/stdc++.h>
using namespace std;
int main() {
  auto add = [&]() {
    int n, sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
      sum += arr[i];
    }
    return sum;
  };
  cout << add() << endl;
  return 0;
}
