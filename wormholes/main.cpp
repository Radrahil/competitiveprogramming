#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, X, Y;
  cin >> N >> X >> Y;

  vector<pair<long long, long long>> contests(N);
  for (int i = 0; i < N; ++i) {
    cin >> contests[i].first >> contests[i].second;
  }

  vector<long long> entry(X), exit(Y);
  for (int i = 0; i < X; ++i) cin >> entry[i];
  for (int i = 0; i < Y; ++i) cin >> exit[i];

  sort(entry.begin(), entry.end());
  sort(exit.begin(), exit.end());

  long long minTime = INT_MAX;  // Used to track the minimum time spent
  for (auto &contest : contests) {
    long long start = contest.first;
    long long end = contest.second;

    // Find the latest V wormhole before the contest starts
    auto entryIt = upper_bound(entry.begin(), entry.end(), start);
    if (entryIt != entry.begin()) {  // Check if not the first element
      entryIt--;                     // Move to the correct position if possible
    } else {
      continue;  // If there's no valid V wormhole before the contest starts,
                 // skip this contest
    }
    long long entryTime = *entryIt;

    // Find the earliest W wormhole after the contest ends
    auto exitIt = lower_bound(exit.begin(), exit.end(), end);
    if (exitIt != exit.end()) {  // Ensure there's a valid exit wormhole
      long long exitTime = *exitIt;

      // Update minTime if the current contest requires less time
      long long totalTime = exitTime - entryTime + 1;
      minTime = min(minTime, totalTime);  // Simplified updating minTime
    }
  }

  cout << minTime << endl;
  return 0;
}
