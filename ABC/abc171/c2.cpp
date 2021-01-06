#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  //--------------------//
  // modを利用
  //--------------------//
  ll n;
  cin >> n;
  string ans;
  while(n){
    n--;
    ans += 'a' +n%26;
    n /= 26;
  }

  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}
