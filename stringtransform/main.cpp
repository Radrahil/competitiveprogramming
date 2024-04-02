#include <bits/stdc++.h>

using namespace std;

int main() {
  string txt;
  cin >> txt;
  int changes = 0;
  int len = txt.length();

  // Loop through the string
  for (int i = 1; i < len; i++) {
    // If two adjacent characters are the same
    if (txt[i] == txt[i - 1]) {
      // Change the current character to any other character except the previous
      // one
      for (char c = 'a'; c <= 'z'; c++) {
        if (c != txt[i - 1] && c != txt[i + 1]) {
          txt[i] = c;
          changes++;
          break;
        }
      }
    }
  }
  cout << changes << endl;
  cout << txt << endl; // Output the transformed string
}
