/**
 * E. K Balanced Teams
 * https://codeforces.com/contest/1133/problem/E
 */
#include<iostream>
#include<algorithm>
using namespace std;

int a[5010];
int maxStart[5010];
int dp[5010][2];
int main() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin>>a[i];
  }
  sort(a, a + n);
  int l = 0, r = 0;
  while(r < n) {
    if(a[r] - a[l] <= 5) {
      maxStart[r] = l;
      ++r;
      continue;
    }
    ++l;
  }
  for(int i = 1; i <= k; ++i) {
    for(int j = 0; j < n; ++j) {
      if(maxStart[j]) {
        dp[j][i%2] = max(dp[j - 1][i%2], dp[maxStart[j] - 1][(i-1)%2] + j - maxStart[j] + 1);
        continue;
      }
      dp[j][i%2] = max(dp[j - 1][i%2], j - maxStart[j] + 1);
    }
  }
  cout << dp[n - 1][k%2] << endl;
  return 0;
}
