/**
 * B. Nastya Is Playing Computer Games
 * https://codeforces.com/contest/1136/problem/B
 */
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int n, k, ans;
  cin >> n >> k;
  ans = n * 3 + min(n - k, k - 1);
  cout << ans << endl;
  return 0;
}
