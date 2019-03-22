/**
 * B. Preparation for International Women's Day
 * https://codeforces.com/contest/1133/problem/B
 */

#include<iostream>
#include<cmath>
using namespace std;

int cnt[100];

int main() {
  int n, k, x;
  cin >> n >> k;
  while(n--) {
    cin >> x;
    ++cnt[x%k];
  }
  int ans = 0;
  if(cnt[0]) {
    ans += cnt[0] & -2;
  }
  for (int i = 1; i <= k/2; ++i) {
    if(i == k - i) {
      ans += cnt[i] & -2;
    } else {
      ans += min(cnt[i], cnt[k-i]) * 2;
    }
  }
  cout << ans << endl;
  return 0;
}
