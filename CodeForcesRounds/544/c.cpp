/**
 * C. Balanced Team
 * https://codeforces.com/contest/1133/problem/C
 */
#include<iostream>
#include<algorithm>
using namespace std;

int a[200000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans = 0, start = 0, end = 0;
  while(end < n) {
    if(a[end] - a[start] <= 5) {
      ans = max(ans, end - start + 1);
      ++end;
      continue;
    }
    ++start;
  }
  cout << ans << endl;
  return 0;
}
