//B. Tanya and Candies
#include<iostream>

using namespace std;

typedef long long ll;

int n;
ll a, jumpSum[200002];

ll getSum(int p) {
  if(p < 0) return 0;
  return jumpSum[p];
}

ll getLastSum(int p) {
  if((n - 1 - p) & 1) {
    return getSum(n - 2);
  }
  return getSum(n - 1);
}

int main() {
  int ans = 0;
  cin >> n;
  for(int i=0; i < n; ++i) {
    cin>>a;
    jumpSum[i] = a + (i >= 2 ? jumpSum[i - 2] : 0);
  }

  for(int i=0; i < n; ++i) {
    ll sum1 = getSum(i - 2) + (getLastSum(i + 1) - getSum(i - 1));
    ll sum2 = getSum(i - 1) + (getLastSum(i + 2) - getSum(i));
    if(sum1 == sum2) ++ans;
  }
  cout << ans << endl;
  return 0;
}
