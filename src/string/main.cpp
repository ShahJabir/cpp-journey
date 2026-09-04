#include <bits/stdc++.h>

using namespace std;

int main() {
  char name[10] = {'G', 'o', '\0', 'l', 'u', '\0'};
  char name2[] = "Golu";
  string arr = "Aolu";
  string arr2 = "Golu";
  string str;
  cout << "Enter a string : ";
  getline(cin, str);
  cout << str << endl;
  cout << name << endl;
  cout << name2 << endl;
  cout << (arr < arr2) << endl;
}
