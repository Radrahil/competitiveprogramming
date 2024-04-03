#include <bits/stdc++.h>

#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll solve(vi big, vi small, ll N, ll K) {
  ll bigPt = 0;
  ll smallPt = N - 1;
  
  while (K > 0) {
    if (big[bigPt] >= small[smallPt]) {
      break;
    } else if ( smallPt < 0 || bigPt >= N) {
      break;
    } else {
      swap(big[bigPt], small[smallPt]);
      K--;
      bigPt++;
      smallPt--;
    }
  }

  sort(big.begin(),big.end());
  sort(small.begin(), small.end());

  return big.back() + small.back();
}

int main() {
  ll N, K, height;
  vi top, bottom;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> height;
    top.push_back(height);
  }
  for (int i = 0; i < N; i++) {
    cin >> height;
    bottom.push_back(height);
  }

  sort(top.begin(), top.end());
  sort(bottom.begin(), bottom.end());

  // cout << top.back() << bottom.back() << endl;

  cout << min(solve(top, bottom, N, K), solve(bottom, top, N, K)) << endl;
  return 0;
}
