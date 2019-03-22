// D2. Coffee and Coursework (Hard Version)
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

ll num[200010], n, m;

bool cmp(ll a, ll b) {
  return a > b;
}

bool test(ll day) {
  if(day < 1) return false;
  ll sum = 0, i = 0, j = 0, minus = 0;
  while(sum < m) {
    if(num[i] - minus < 1) return false;
    sum += num[i] - minus;
    ++i;
    ++j;
    if(j == day) {
      j = 0;
      ++minus;
    }
  }
  return true;
}

int main() {
  ll sum = 0;
  cin >> n >> m;
  for(ll i = 0; i < n; i++) {
    cin >> num[i];
    sum += num[i];
  }
  if(m > sum) {
    cout << -1 << endl;
    return 0;
  }

  sort(num, num + n, cmp);

  ll l = 0, r = n;

  while(l + 1 < r) {
    ll mid = (l + r) / 2;
    if(test(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout<< r << endl;

}
