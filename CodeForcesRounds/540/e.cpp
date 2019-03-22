// E. Yet Another Ball Problem
#include<iostream>
using namespace std;

typedef long long ll;

ll n, k;

ll getG(ll b, ll addStep) {
  // addStep > -k
  return (b + addStep + k) > k ? (b + addStep + k) % k : b + addStep + k;
}

int main() {
  cin >> n >> k;
  if(k * (k - 1) < n) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;

  ll i = 0, addStep = -1, b = 1;
  while(i < n) {
    // swap first two pair for each segment
    if(b == 1) {
      cout << 2 << ' ' << getG(2, addStep) << endl;
      
      // ignore if it's end
      if(i == n - 1) break;

      cout << 1 << ' ' << getG(1, addStep) << endl;
      i += 2;
      b += 2;
    } else {
      cout << b << ' ' << getG(b, addStep) << endl;
      ++i;
      ++b;
    }
    if(b > k) {
      b = 1;
      --addStep;
    }
  }
  return 0;
}
