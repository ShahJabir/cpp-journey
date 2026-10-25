#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main() {
  int x = 10, y = 10;
  int *ptr = &x;
  int *ptr2 = &y;
  cout << "Address of x: " << ptr << endl;
  cout << "Address of y: " << ptr2 << endl;
  cout << (*ptr == *ptr2) << endl;
  cout << (*ptr)++ << endl;
  cout << *ptr << endl;
  cout << endl;
  return 0;
}
