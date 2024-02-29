#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> input(n);
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }

  if (n == 1) {
    cout << input[0];
    return 0;
  }

  vector<long long> dp(n);
  dp[0] = input[0];
  dp[1] = input[1];
  dp[n - 1] = input[n - 1]; // Initialize the last element

  for (int i = 2; i < n - 1; i++) { // Loop only until the second last element
    dp[i] = min(dp[i - 1], dp[i - 2]) + input[i];
  }

  long long ans = min(dp[n - 2], dp[n - 3]); // Choose the minimum between the
                                             // second last and the third last

  cout << ans;

  return 0;
}
