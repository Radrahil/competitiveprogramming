#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int totalarea = 0;

  int arr[200][200] = {0};

  for (int i = 0; i < N; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int j = x1; j < x2; j++) {
      for (int k = y1; k < y2; k++) {
        arr[j + 100][k + 100] = 1;
      }
    }
  }

  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200; j++) {
      if (arr[i][j] == 1) {
        totalarea++;
      }
    }
  }
  cout << totalarea << endl;
}
