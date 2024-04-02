#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll filled(vector<ll> cakes, vector<ll> boxes, ll N) {
  ll boxesFilled = 0;
  ll boxIndex = 0;
  ll cakeIndex = 0;

  while (boxIndex < N and cakeIndex < N) {
    if (cakes[cakeIndex] <= boxes[boxIndex]) {
      boxesFilled++;
      cakeIndex++;
    }
    boxIndex++;
  }

  cout << boxesFilled << endl;

  return 0;
}

int main() {
  ll N, Q;

  cin >> N;

  vector<ll> cakes, boxes;

  for (int i = 0; i < N; i++) {
    ll cake;
    cin >> cake;
    cakes.push_back(cake);
  }

  for (int i = 0; i < N; i++) {
    ll box;
    cin >> box;
    boxes.push_back(box);
  }

  sort(boxes.begin(), boxes.end());

  cin >> Q;

  for (int i = 0; i < Q; i++) {
    ll pos, val;
    cin >> pos >> val;

    cakes[pos - 1] = val;

    filled(cakes, boxes, N);
  }

  return 0;
}
